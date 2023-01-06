/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hotmiamy <hotmiamy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 16:00:45 by llopes-n          #+#    #+#             */
/*   Updated: 2023/01/05 22:59:24 by hotmiamy         ###   ########.fr       */
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
	int			inx;
	t_phi_lst	*tmp;

	inx = 0;
	tmp = philo->phi_lst;
	while (inx != philo->philo_num)
	{
		pthread_create(&tmp->thread, NULL, &routine, tmp);
		tmp = tmp->next;
		inx++;
	}
}

void	thread_join(t_philo *philo)
{
	int			inx;
	t_phi_lst	*tmp;

	inx = 0;
	tmp = philo->phi_lst;
	while (inx != philo->philo_num)
	{
		pthread_join(tmp->thread, NULL);
		tmp = tmp->next;
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
	pthread_mutex_init(&philo->phi_mutex, NULL);
	thread_create(philo);
	thread_join(philo);
}
