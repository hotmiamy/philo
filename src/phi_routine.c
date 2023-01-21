/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phi_routine.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hotmiamy <hotmiamy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 19:13:28 by hotmiamy          #+#    #+#             */
/*   Updated: 2023/01/21 01:26:29 by hotmiamy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	take_fork(t_phi_lst *phi_lst)
{
	pthread_mutex_lock(&phi_lst->fork);
	print_action(phi_lst, FORK);
	pthread_mutex_lock(&phi_lst->next->fork);
	print_action(phi_lst, FORK);
	print_action(phi_lst, EAT);
}

int	thinking(t_phi_lst *phi_lst)
{
	print_action(phi_lst, THINK);
	msleep(1);
	return (0);
}

int	slepping(t_phi_lst *phi_lst)
{
	print_action(phi_lst, SLEEP);
	msleep(phi_lst->philo->time_sleep);
	return (0);
}

t_bool	eating(t_phi_lst *phi_lst)
{
	take_fork(phi_lst);
	if (phi_lst->philo->times_must_eate > 0)
		phi_lst->times_ate++;
	phi_lst->stop_eat = current_time();
	msleep(phi_lst->philo->time_ate);
	pthread_mutex_unlock(&phi_lst->fork);
	pthread_mutex_unlock(&phi_lst->next->fork);
	return (0);
}

void	*routine(void *node)
{
	t_phi_lst	*phi_lst;

	phi_lst = (t_phi_lst *)node;
	if (phi_lst->id % 2 == 0)
		msleep(2);
	while (phi_lst->philo->stop_flag)
	{
		eating(phi_lst);
		thinking(phi_lst);
		slepping(phi_lst);
	}
	return (NULL);
}
