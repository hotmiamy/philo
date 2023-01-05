/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hotmiamy <hotmiamy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 16:00:45 by llopes-n          #+#    #+#             */
/*   Updated: 2023/01/04 22:18:01 by hotmiamy         ###   ########.fr       */
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

void	init(t_philo *philo, char **args)
{
	philo->philo_num = ft_atoi(args[1]);
	philo->time_die = ft_atoi(args[2]);
	philo->time_ate = ft_atoi(args[3]);
	philo->time_sleep = ft_atoi(args[4]);
	if (args[5] != NULL)
		philo->times_must_ate = ft_atoi(args[5]);
	fill_phi_lst(philo);
	thread_create(philo);
	thread_join(philo);
}
