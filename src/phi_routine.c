/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phi_routine.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hotmiamy <hotmiamy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 19:13:28 by hotmiamy          #+#    #+#             */
/*   Updated: 2023/01/21 20:18:10 by hotmiamy         ###   ########.fr       */
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
	while (phi_lst->philo->stop_flag)
	{
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
