/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phi_routine.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopes-n <llopes-n@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 19:13:28 by hotmiamy          #+#    #+#             */
/*   Updated: 2023/01/22 03:14:48 by llopes-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *node)
{
	t_phi_lst	*phi_lst;

	phi_lst = (t_phi_lst *)node;
	if (phi_lst->id % 2 == 0)
		msleep(2);
	phi_lst->start_time = current_time();
	while (check_variable(phi_lst->philo->stop_flag, TRUE, phi_lst->philo))
	{
		if (phi_lst->id == phi_lst->philo->philo_num)
			last_eating(phi_lst);
		if (phi_lst->philo->stop_flag)
			eating(phi_lst);
		if (phi_lst->philo->times_must_eate > 0
			&& phi_lst->times_ate >= phi_lst->philo->times_must_eate)
			break ;
		if (phi_lst->philo->stop_flag)
			thinking(phi_lst);
		if (phi_lst->philo->stop_flag)
			slepping(phi_lst);
	}
	return (NULL);
}
