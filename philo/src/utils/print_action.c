/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_action.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopes-n <llopes-n@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 19:20:59 by hotmiamy          #+#    #+#             */
/*   Updated: 2023/01/22 22:05:51 by llopes-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_action(t_phi_lst *phi_lst, char *action)
{
	long	cur_time;

	if (!check_death(phi_lst->philo))
		return ;
	pthread_mutex_lock(&phi_lst->philo->print_mutex);
	cur_time = current_time() - phi_lst->start_time;
	printf("%ld philosofer %i %s\n", cur_time, phi_lst->id, action);
	pthread_mutex_unlock(&phi_lst->philo->print_mutex);
}

void	print_death(t_phi_lst *phi_lst, char *action)
{
	long	cur_time;

	pthread_mutex_lock(&phi_lst->philo->print_mutex);
	cur_time = current_time() - phi_lst->start_time;
	printf("%ld philosofer %i %s\n", cur_time, phi_lst->id, action);
	pthread_mutex_unlock(&phi_lst->philo->print_mutex);
}
