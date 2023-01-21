/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vigilant.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hotmiamy <hotmiamy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 20:56:13 by hotmiamy          #+#    #+#             */
/*   Updated: 2023/01/20 23:02:07 by hotmiamy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_bool	eat_counter(t_philo *philo)
{
	int			inx;
	t_phi_lst	*tmp;

	pthread_mutex_lock(&philo->check_mutex);
	tmp = philo->phi_lst;
	inx = 0;
	while (inx != philo->philo_num)
	{
		if (tmp->times_ate < philo->times_must_eate)
		{
			pthread_mutex_unlock(&philo->check_mutex);
			return (TRUE);
		}
		inx++;
		tmp = tmp->next;
	}
	philo->stop_flag = FALSE;
	pthread_mutex_unlock(&philo->check_mutex);
	destroy_mutex(philo);
	return (FALSE);
}

void	*vigilant(void *node)
{
	int			time_eat;
	t_phi_lst	*philo;

	philo = (t_phi_lst *)node;
	while (philo->philo->stop_flag)
	{
		pthread_mutex_lock(&philo->philo->vigi_mutex);
		time_eat = current_time() - philo->stop_eat;
		if (time_eat > philo->philo->time_die)
		{
			philo->philo->stop_flag = FALSE;
			destroy_mutex(philo->philo);
			break ;
		}
		if (philo->philo->times_must_eate > 0 && !eat_counter(philo->philo))
			return (NULL);
		pthread_mutex_unlock(&philo->philo->vigi_mutex);
	}
	print_action(philo, DEAD);
	return (NULL);
}
