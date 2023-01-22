/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_action.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hotmiamy <hotmiamy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 19:20:59 by hotmiamy          #+#    #+#             */
/*   Updated: 2023/01/22 02:06:08 by hotmiamy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_bool	print_action(t_phi_lst *phi_lst, char *action)
{
	long	cur_time;

	if (check_variable(phi_lst->philo->stop_flag, FALSE, phi_lst->philo))
		return (FALSE);
	pthread_mutex_lock(&phi_lst->philo->print_mutex);
	cur_time = current_time() - phi_lst->start_time;
	printf("%ld philosofer %i %s\n", cur_time, phi_lst->id, action);
	pthread_mutex_unlock(&phi_lst->philo->print_mutex);
	return (0);
}
