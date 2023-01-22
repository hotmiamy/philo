/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vigilant.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopes-n <llopes-n@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 20:56:13 by hotmiamy          #+#    #+#             */
/*   Updated: 2023/01/22 03:56:01 by llopes-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_bool	eat_counter(t_phi_lst *phi_lst)
{
	int			inx;
	t_phi_lst	*tmp;

	tmp = phi_lst;
	inx = 0;
	while (inx != phi_lst->philo->philo_num)
	{
		if (tmp->times_ate < phi_lst->philo->times_must_eate)
			return (TRUE);
		inx++;
		tmp = tmp->next;
	}
	phi_lst->philo->stop_flag = FALSE;
	return (FALSE);
}

t_bool	check_variable(int variable, t_bool vari_status, t_philo *philo)
{
	usleep(50);
	pthread_mutex_lock(&philo->check_mutex);
	if (variable == (int)vari_status)
	{
		pthread_mutex_unlock(&philo->check_mutex);
		return (vari_status);
	}
	else
	{
		pthread_mutex_unlock(&philo->check_mutex);
		return (!vari_status);
	}
}

void	set_stop_flag(t_philo *philo)
{
	pthread_mutex_lock(&philo->check_mutex);
	philo->stop_flag = FALSE;
	pthread_mutex_unlock(&philo->check_mutex);
}

void	*vigilant(void *node)
{
	int			time_eat;
	t_phi_lst	*philo;

	philo = (t_phi_lst *)node;
	while (philo->philo->stop_flag)
	{
		usleep(50);
		pthread_mutex_lock(&philo->philo->vigi_mutex);
		time_eat = current_time() - philo->stop_eat;
		pthread_mutex_unlock(&philo->philo->vigi_mutex);
		if (time_eat > philo->philo->time_die)
		{
			set_stop_flag(philo->philo);
			break ;
		}
		philo = philo->next;
	}
	print_action(philo, DEAD);
	return (NULL);
}
