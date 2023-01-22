/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hotmiamy <hotmiamy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 00:08:54 by hotmiamy          #+#    #+#             */
/*   Updated: 2023/01/22 01:57:44 by hotmiamy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	free_lst(t_philo *philo)
{
	int			inx;
	t_phi_lst	*tmp;

	inx = 0;
	if (philo->philo_num < 2)
	{
		free(philo->phi_lst);
		philo->phi_lst = NULL;
		return ;
	}
	while (inx != philo->philo_num)
	{
		tmp = philo->phi_lst->next;
		free(philo->phi_lst);
		philo->phi_lst = NULL;
		philo->phi_lst = tmp;
		inx++;
	}
}

void	destroy_mutex(t_philo *philo)
{
	int			inx;
	t_phi_lst	*tmp;

	pthread_mutex_destroy(&philo->vigi_mutex);
	inx = 0;
	tmp = philo->phi_lst;
	while (inx < philo->philo_num)
	{
		pthread_mutex_destroy(&tmp->fork);
		tmp = tmp->next;
		inx++;
	}
}
