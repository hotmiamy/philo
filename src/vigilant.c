/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vigilant.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopes-n <llopes-n@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 20:56:13 by hotmiamy          #+#    #+#             */
/*   Updated: 2023/01/22 22:19:31 by llopes-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	set_stop_flag(t_philo *philo)
{
	pthread_mutex_lock(&philo->check_mutex);
	philo->stop_flag = FALSE;
	pthread_mutex_unlock(&philo->check_mutex);
}

t_bool	eat_counter(t_philo *philo)
{
	int			inx;
	t_phi_lst	*tmp;

	tmp = philo->phi_lst;
	inx = 0;
	while (inx != philo->philo_num)
	{
		if (tmp->times_ate < philo->times_must_eate)
			return (TRUE);
		inx++;
		tmp = tmp->next;
	}
	set_stop_flag(philo);
	return (FALSE);
}

void	*vigilant(void *node)
{
	int			time_eat;
	t_phi_lst	*phi_lst;

	phi_lst = (t_phi_lst *)node;
	while (phi_lst->philo->stop_flag)
	{
		usleep(10);
		pthread_mutex_lock(&phi_lst->philo->vigi_mutex);
		time_eat = current_time() - phi_lst->last_meat;
		if (time_eat > phi_lst->philo->time_die)
		{
			set_stop_flag(phi_lst->philo);
			pthread_mutex_unlock(&phi_lst->philo->vigi_mutex);
			break ;
		}
		if (phi_lst->philo->times_must_eate > 0 && !eat_counter(phi_lst->philo))
		{
			pthread_mutex_unlock(&phi_lst->philo->vigi_mutex);
			return (NULL);
		}
		pthread_mutex_unlock(&phi_lst->philo->vigi_mutex);
		phi_lst = phi_lst->next;
	}
	print_death(phi_lst, DEAD);
	return (NULL);
}
