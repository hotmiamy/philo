/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hotmiamy <hotmiamy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 09:28:05 by llopes-n          #+#    #+#             */
/*   Updated: 2023/01/04 23:29:58 by hotmiamy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	eating(t_phi_lst *phi_lst)
{
	long	cur_time;

	pthread_mutex_lock(&phi_lst->fork);
	pthread_mutex_lock(&phi_lst->next->fork);
	cur_time = current_time() - phi_lst->start_time;
	printf("%ld philosofer %i is eating\n", cur_time, phi_lst->id);
	msleep(phi_lst->philo->time_ate);
	pthread_mutex_unlock(&phi_lst->fork);
	pthread_mutex_unlock(&phi_lst->next->fork);
	return (0);
}

int	thinking(t_phi_lst *phi_lst)
{
	long	cur_time;

	cur_time = current_time() - phi_lst->start_time;
	printf("%ld philosofer %i is thinking\n", cur_time, phi_lst->id);
	return (0);
}

int	slepping(t_phi_lst *phi_lst)
{
	long	cur_time;

	cur_time = current_time() - phi_lst->start_time;
	printf("%ld philosofer %i is sleeping\n", cur_time, phi_lst->id);
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

int	main(int argc, char **argv)
{
	t_philo	philo;

	if (argc <= 1)
		return (0);
	init(&philo, argv);
	return (0);
}
