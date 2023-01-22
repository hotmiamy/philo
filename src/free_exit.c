/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopes-n <llopes-n@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 00:08:54 by hotmiamy          #+#    #+#             */
/*   Updated: 2023/01/22 02:11:15 by llopes-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	free_lst(t_phi_lst *phi_lst)
{
	int			inx;
	t_phi_lst	*tmp;

	inx = 0;
	if (phi_lst->philo->philo_num < 2)
	{
		free(phi_lst);
		phi_lst = NULL;
		return ;
	}
	while (inx != phi_lst->philo->philo_num)
	{
		tmp = phi_lst->next;
		free(phi_lst);
		phi_lst = NULL;
		phi_lst = tmp;
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
