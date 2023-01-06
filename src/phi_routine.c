/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phi_routine.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hotmiamy <hotmiamy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 19:13:28 by hotmiamy          #+#    #+#             */
/*   Updated: 2023/01/06 20:43:33 by hotmiamy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	eating(t_phi_lst *phi_lst)
{
	pthread_mutex_lock(&phi_lst->fork);
	pthread_mutex_lock(&phi_lst->next->fork);
	print_action(phi_lst, EAT);
	msleep(phi_lst->philo->time_ate);
	pthread_mutex_unlock(&phi_lst->fork);
	pthread_mutex_unlock(&phi_lst->next->fork);
	return (0);
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

void	*routine(void *node)
{
	t_phi_lst	*phi_lst;

	phi_lst = (t_phi_lst *)node;
	phi_lst->start_time = current_time();
	eating(phi_lst);
	thinking(phi_lst);
	slepping(phi_lst);
	return (NULL);
}
