/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopes-n <llopes-n@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 18:11:10 by hotmiamy          #+#    #+#             */
/*   Updated: 2023/01/22 17:53:05 by llopes-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_bool	take_fork_1(t_phi_lst *phi_lst)
{
	if (check_variable(phi_lst->philo->stop_flag, phi_lst->philo))
		return (FALSE);
	pthread_mutex_lock(&phi_lst->fork);
	print_action(phi_lst, FORK);
	return (TRUE);
}

t_bool	take_fork_2(t_phi_lst *phi_lst)
{
	if (check_variable(phi_lst->philo->stop_flag, phi_lst->philo))
		return (FALSE);
	pthread_mutex_lock(&phi_lst->next->fork);
	print_action(phi_lst, FORK);
	print_action(phi_lst, EAT);
	return (TRUE);
}

t_bool	last_eating(t_phi_lst *phi_lst)
{
	take_fork_2(phi_lst);
	take_fork_1(phi_lst);
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

t_bool	eating(t_phi_lst *phi_lst)
{
	take_fork_1(phi_lst);
	take_fork_2(phi_lst);
	pthread_mutex_lock(&phi_lst->philo->vigi_mutex);
	if (phi_lst->philo->times_must_eate > 0)
		phi_lst->times_ate++;
	phi_lst->last_meat = current_time();
	pthread_mutex_unlock(&phi_lst->philo->vigi_mutex);
	msleep(phi_lst->philo->time_ate);
	pthread_mutex_unlock(&phi_lst->fork);
	pthread_mutex_unlock(&phi_lst->next->fork);
	return (TRUE);
}

int	thinking(t_phi_lst *phi_lst)
{
	print_action(phi_lst, THINK);
	msleep(1);
	return (TRUE);
}

int	slepping(t_phi_lst *phi_lst)
{
	print_action(phi_lst, SLEEP);
	msleep(phi_lst->philo->time_sleep);
	return (TRUE);
}
