/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopes-n <llopes-n@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 16:00:45 by llopes-n          #+#    #+#             */
/*   Updated: 2023/01/22 22:14:26 by llopes-n         ###   ########.fr       */
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

int	init(t_philo *philo, char **args, int argc)
{
	if (check_args(argc, args))
		return (1);
	init_struct(args, philo);
	fill_phi_lst(philo);
	if (philo->philo_num < 2)
	{
		philo->phi_lst->start_time = current_time();
		msleep(philo->time_die);
		print_action(philo->phi_lst, FORK);
		print_action(philo->phi_lst, DEAD);
		return (0);
	}
	thread_create(philo);
	thread_join(philo);
	return (0);
}
