/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hotmiamy <hotmiamy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 18:11:10 by hotmiamy          #+#    #+#             */
/*   Updated: 2023/01/21 19:06:51 by hotmiamy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	take_fork_1(t_phi_lst *phi_lst)
{
	pthread_mutex_lock(&phi_lst->fork);
	print_action(phi_lst, FORK);
}

void	take_fork_2(t_phi_lst *phi_lst)
{
	pthread_mutex_lock(&phi_lst->next->fork);
	print_action(phi_lst, FORK);
	print_action(phi_lst, EAT);
}

t_bool	eating(t_phi_lst *phi_lst)
{
	take_fork_1(phi_lst);
	take_fork_2(phi_lst);
	pthread_mutex_lock(&phi_lst->philo->vigi_mutex);
	if (phi_lst->philo->times_must_eate > 0)
		phi_lst->times_ate++;
	phi_lst->stop_eat = current_time();
	pthread_mutex_unlock(&phi_lst->philo->vigi_mutex);
	msleep(phi_lst->philo->time_ate);
	pthread_mutex_unlock(&phi_lst->fork);
	pthread_mutex_unlock(&phi_lst->next->fork);
	return (0);
}

void	thinking(t_phi_lst *phi_lst)
{
	print_action(phi_lst, THINK);
	msleep(1);
}

void	slepping(t_phi_lst *phi_lst)
{
	print_action(phi_lst, SLEEP);
	msleep(phi_lst->philo->time_sleep);
}