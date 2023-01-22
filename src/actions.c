/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hotmiamy <hotmiamy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 18:11:10 by hotmiamy          #+#    #+#             */
/*   Updated: 2023/01/22 02:48:33 by hotmiamy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_bool	take_fork_1(t_phi_lst *phi_lst)
{
	pthread_mutex_lock(&phi_lst->fork);
	if (print_action(phi_lst, FORK) == FALSE)
		return (FALSE);
	return (TRUE);
}

t_bool	take_fork_2(t_phi_lst *phi_lst)
{
	pthread_mutex_lock(&phi_lst->next->fork);
	if (print_action(phi_lst, FORK) == FALSE)
		return (FALSE);
	if (print_action(phi_lst, EAT) == FALSE)
		return (FALSE);
	return (TRUE);
}

t_bool	last_eating(t_phi_lst *phi_lst)
{
	if (take_fork_2(phi_lst) == FALSE)
		return (FALSE);
	if (take_fork_1(phi_lst))
		return (FALSE);
	pthread_mutex_lock(&phi_lst->philo->vigi_mutex);
	if (phi_lst->philo->times_must_eate > 0)
		phi_lst->times_ate++;
	phi_lst->stop_eat = current_time();
	pthread_mutex_unlock(&phi_lst->philo->vigi_mutex);
	msleep(phi_lst->philo->time_ate);
	pthread_mutex_unlock(&phi_lst->next->fork);
	pthread_mutex_unlock(&phi_lst->fork);
	return (TRUE);
}

t_bool	eating(t_phi_lst *phi_lst)
{
	if (take_fork_1(phi_lst))
		return (FALSE);
	if (take_fork_2(phi_lst) == FALSE)
		return (FALSE);
	pthread_mutex_lock(&phi_lst->philo->vigi_mutex);
	if (phi_lst->philo->times_must_eate > 0)
		phi_lst->times_ate++;
	phi_lst->stop_eat = current_time();
	pthread_mutex_unlock(&phi_lst->philo->vigi_mutex);
	msleep(phi_lst->philo->time_ate);
	pthread_mutex_unlock(&phi_lst->fork);
	pthread_mutex_unlock(&phi_lst->next->fork);
	return (TRUE);
}

int	thinking(t_phi_lst *phi_lst)
{
	if (print_action(phi_lst, THINK) == FALSE)
		return (FALSE);
	msleep(1);
	return (TRUE);
}

int	slepping(t_phi_lst *phi_lst)
{
	if (print_action(phi_lst, SLEEP) == FALSE)
		return (FALSE);
	msleep(phi_lst->philo->time_sleep);
	return (TRUE);
}
