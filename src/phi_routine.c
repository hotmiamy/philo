/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phi_routine.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopes-n <llopes-n@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 19:13:28 by hotmiamy          #+#    #+#             */
/*   Updated: 2023/01/22 17:45:59 by llopes-n         ###   ########.fr       */
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
	while (check_variable(phi_lst->philo->stop_flag, phi_lst->philo))
	{
		if (eating(phi_lst) == FALSE)
			break ;
		if (thinking(phi_lst) == FALSE)
			break ;
		if (slepping(phi_lst) == FALSE)
			break ;
	}
	return (NULL);
}
