/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phi_routine.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hotmiamy <hotmiamy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 19:13:28 by hotmiamy          #+#    #+#             */
/*   Updated: 2023/01/22 02:11:29 by hotmiamy         ###   ########.fr       */
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
	while (check_variable(phi_lst->philo->stop_flag, FALSE, phi_lst->philo))
	{
		if (phi_lst->id == phi_lst->philo->philo_num)
		{
			if (last_eating(phi_lst))
				return (NULL);
		}
		if (eating(phi_lst))
			return (NULL);
		if (phi_lst->philo->times_must_eate > 0
			&& phi_lst->times_ate >= phi_lst->philo->times_must_eate)
			break ;
		if (thinking(phi_lst))
			return (NULL);
		if (slepping(phi_lst))
			return (NULL);
	}
	return (NULL);
}
