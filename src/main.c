/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopes-n <llopes-n@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 09:28:05 by llopes-n          #+#    #+#             */
/*   Updated: 2022/10/28 16:57:56 by llopes-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	eating(t_phi_lst *phi_lst)
{
	printf("philosofer %i is eating\n", phi_lst->id);
	return (0);
}

int	thinking(t_phi_lst *phi_lst)
{
	printf("philosofer %i is thinking\n", phi_lst->id);
	return (0);
}

int	slepping(t_phi_lst *phi_lst)
{
	printf("philosofer %i is sleeping\n", phi_lst->id);
	return (0);
}

void	*routine(void *node)
{
	t_phi_lst	*phi_lst;

	phi_lst = (t_phi_lst *)node;
	eating(phi_lst);
	thinking(phi_lst);
	slepping(phi_lst);
	return (NULL);
}

int	main(int argc, char **argv)
{
	t_philo	philo;
	int		inx;

	inx = 0;
	if (argc <= 1)
		return (0);
	philo.philo_num = ft_atoi(argv[1]);
	fill_phi_lst(&philo);
	while (inx != philo.philo_num)
	{
		pthread_create(&philo.phi_lst->thread, NULL, &routine, philo.phi_lst);
		philo.phi_lst = philo.phi_lst->next;
		inx++;
	}
	inx = 0;
	while (inx != philo.philo_num)
	{
		pthread_join(philo.phi_lst->thread, NULL);
		philo.phi_lst = philo.phi_lst->next;
		inx++;
	}
	return (0);
}
