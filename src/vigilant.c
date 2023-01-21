/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vigilant.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hotmiamy <hotmiamy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 20:56:13 by hotmiamy          #+#    #+#             */
/*   Updated: 2023/01/21 20:31:05 by hotmiamy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_bool	eat_counter(t_phi_lst *phi_lst)
{
	int			inx;
	t_phi_lst	*tmp;

	tmp = phi_lst;
	inx = 0;
	while (inx != phi_lst->philo->philo_num)
	{
		if (tmp->times_ate < phi_lst->philo->times_must_eate)
			return (TRUE);
		inx++;
		tmp = tmp->next;
	}
	phi_lst->philo->stop_flag = FALSE;
	return (FALSE);
}

void	*vigilant(void *node)
{
	int			time_eat;
	t_phi_lst	*philo;

	philo = (t_phi_lst *)node;
	usleep(21000);
	while (philo->philo->stop_flag)
	{
		pthread_mutex_lock(&philo->philo->vigi_mutex);
		time_eat = current_time() - philo->stop_eat;
		if (time_eat > philo->philo->time_die)
		{
			philo->philo->stop_flag = FALSE;
			break ;
		}
		pthread_mutex_unlock(&philo->philo->vigi_mutex);
		philo = philo->next;
	}
	print_action(philo, DEAD);
	return (NULL);
}