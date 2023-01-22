/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hotmiamy <hotmiamy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 16:00:45 by llopes-n          #+#    #+#             */
/*   Updated: 2023/01/22 16:32:11 by hotmiamy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	change_last(t_philo *philo)
{
	t_phi_lst		*node;
	pthread_mutex_t	tmp;
	int				inx;

	inx = 1;
	node = philo->phi_lst;
	while (inx != philo->philo_num)
	{
		node = node->next;
		inx++;
	}
	tmp = node->fork;
	node->fork = node->next->fork;
	node->next->fork = tmp;
}

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
	pthread_create(&philo->vigi_thread, NULL, &vigilant, philo->phi_lst);
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
	pthread_join(philo->vigi_thread, NULL);
	destroy_mutex(philo);
}

void	*init(t_philo *philo, char **args, int argc)
{
	check_args(argc, args);
	init_struct(args, philo);
	fill_phi_lst(philo);
	change_last(philo);
	if (philo->philo_num < 2)
	{
		print_action(philo->phi_lst, FORK);
		print_action(philo->phi_lst, DEAD);
		return (NULL);
	}
	thread_create(philo);
	thread_join(philo);
	return (NULL);
}
