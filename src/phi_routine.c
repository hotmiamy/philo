/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phi_routine.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopes-n <llopes-n@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 19:13:28 by hotmiamy          #+#    #+#             */
/*   Updated: 2023/01/22 22:19:40 by llopes-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_bool	last_take_fork(t_phi_lst *phi_lst)
{
	pthread_mutex_lock(&phi_lst->next->fork);
	print_action(phi_lst, FORK);
	pthread_mutex_lock(&phi_lst->fork);
	print_action(phi_lst, FORK);
	print_action(phi_lst, EAT);
	return (TRUE);
}

t_bool	last_eating(t_phi_lst *phi_lst)
{
	last_take_fork(phi_lst);
	pthread_mutex_lock(&phi_lst->philo->vigi_mutex);
	if (phi_lst->philo->times_must_eate > 0)
		phi_lst->times_ate++;
	phi_lst->last_meat = current_time();
	pthread_mutex_unlock(&phi_lst->philo->vigi_mutex);
	msleep(phi_lst->philo->time_ate);
	pthread_mutex_unlock(&phi_lst->next->fork);
	pthread_mutex_unlock(&phi_lst->fork);
	return (TRUE);
}

void	*routine(void *node)
{
	t_phi_lst	*phi_lst;

	phi_lst = (t_phi_lst *)node;
	phi_lst->start_time = current_time();
	if (phi_lst->id % 2 == 0)
		usleep(10);
	while (check_death(phi_lst->philo))
	{
		if (phi_lst->id == phi_lst->philo->philo_num)
			last_eating(phi_lst);
		else if (eating(phi_lst) == FALSE)
			break ;
		if (thinking(phi_lst) == FALSE)
			break ;
		if (slepping(phi_lst) == FALSE)
			break ;
	}
	return (NULL);
}
