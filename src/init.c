/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hotmiamy <hotmiamy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 16:00:45 by llopes-n          #+#    #+#             */
/*   Updated: 2022/12/23 11:50:03 by hotmiamy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	fill_phi_lst(t_philo *philo)
{
	t_phi_lst	*node;
	int			inx;

	inx = 0;
	node = NULL;
	philo->phi_lst = NULL;
	while (inx != philo->philo_num)
	{
		node = phi_lst_new(inx + 1, philo);
		phi_lstadd_back(&philo->phi_lst, node);
		inx++;
	}
}

void	thread_create(t_philo *philo)
{
	int	inx;

	inx = 0;
	while (inx != philo->philo_num)
	{
		pthread_create(&philo->phi_lst->thread, NULL, &routine, philo->phi_lst);
		philo->phi_lst = philo->phi_lst->next;
		inx++;
	}
}

void	thread_join(t_philo *philo)
{
	int	inx;

	inx = 0;
	while (inx != philo->philo_num)
	{
		pthread_join(philo->phi_lst->thread, NULL);
		philo->phi_lst = philo->phi_lst->next;
		inx++;
	}
}

void	init(t_philo *philo, char *philo_num)
{
	philo->philo_num = ft_atoi(philo_num);
	fill_phi_lst(philo);
	thread_create(philo);
	thread_join(philo);
}
