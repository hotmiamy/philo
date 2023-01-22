/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopes-n <llopes-n@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 18:11:10 by hotmiamy          #+#    #+#             */
/*   Updated: 2023/01/22 06:34:17 by llopes-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_bool	take_fork_1(t_phi_lst *phi_lst)
{
	pthread_mutex_lock(&phi_lst->fork);
	if (print_action(phi_lst, FORK) == TRUE)
		return (TRUE);
	return (FALSE);
}

t_bool	take_fork_2(t_phi_lst *phi_lst)
{
	pthread_mutex_lock(&phi_lst->next->fork);
	if (print_action(phi_lst, FORK) == TRUE)
		return (TRUE);
	if (print_action(phi_lst, EAT) == TRUE)
		return (TRUE);
	return (FALSE);
}

t_bool	last_eating(t_phi_lst *phi_lst)
{
	if (take_fork_2(phi_lst) == TRUE)
		return (TRUE);
	if (take_fork_1(phi_lst))
		return (TRUE);
	pthread_mutex_lock(&phi_lst->philo->vigi_mutex);
	if (phi_lst->philo->times_must_eate > 0)
		phi_lst->times_ate++;
	phi_lst->stop_eat = current_time();
	pthread_mutex_unlock(&phi_lst->philo->vigi_mutex);
	msleep(phi_lst->philo->time_ate);
	pthread_mutex_unlock(&phi_lst->next->fork);
	pthread_mutex_unlock(&phi_lst->fork);
	return (FALSE);
}

t_bool	eating(t_phi_lst *phi_lst)
{
	if (take_fork_1(phi_lst))
		return (TRUE);
	if (take_fork_2(phi_lst) == TRUE)
		return (TRUE);
	pthread_mutex_lock(&phi_lst->philo->vigi_mutex);
	if (phi_lst->philo->times_must_eate > 0)
		phi_lst->times_ate++;
	phi_lst->stop_eat = current_time();
	pthread_mutex_unlock(&phi_lst->philo->vigi_mutex);
	msleep(phi_lst->philo->time_ate);
	pthread_mutex_unlock(&phi_lst->fork);
	pthread_mutex_unlock(&phi_lst->next->fork);
	return (FALSE);
}

int	thinking(t_phi_lst *phi_lst)
{
	if (print_action(phi_lst, THINK) == TRUE)
		return (TRUE);
	msleep(1);
	return (FALSE);
}

int	slepping(t_phi_lst *phi_lst)
{
	if (print_action(phi_lst, SLEEP) == TRUE)
		return (TRUE);
	msleep(phi_lst->philo->time_sleep);
	return (FALSE);
}
