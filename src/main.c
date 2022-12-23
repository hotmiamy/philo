/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hotmiamy <hotmiamy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 09:28:05 by llopes-n          #+#    #+#             */
/*   Updated: 2022/12/23 12:04:35 by hotmiamy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	eating(t_phi_lst *phi_lst)
{
	long	cur_time;

	cur_time = current_time() - phi_lst->start_time;
	printf("%ld philosofer %i is eating\n", cur_time, phi_lst->id);
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
	init(&philo, argv[1]);
	return (0);
}
