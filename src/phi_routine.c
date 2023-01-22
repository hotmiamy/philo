/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phi_routine.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hotmiamy <hotmiamy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 19:13:28 by hotmiamy          #+#    #+#             */
/*   Updated: 2023/01/22 17:03:48 by hotmiamy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *node)
{
	t_phi_lst	*phi_lst;

	phi_lst = (t_phi_lst *)node;
	phi_lst->start_time = current_time();
	if (phi_lst->id % 2 == 0)
		msleep(2);
	while (check_death(phi_lst->philo))
	{
		if (phi_lst->id == phi_lst->philo->philo_num)
			last_eating(phi_lst);
		else if (eating(phi_lst) == FALSE)
			break ;
		if (thinking(phi_lst) == FALSE)
			break ;
		if (slepping(phi_lst) == FALSE)
			break ;
	}
	return (NULL);
}
