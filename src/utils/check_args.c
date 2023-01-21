/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hotmiamy <hotmiamy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 16:26:34 by hotmiamy          #+#    #+#             */
/*   Updated: 2023/01/21 17:29:19 by hotmiamy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	check_num_args(int argc)
{
	if (argc < 5)
	{
		printf("need more arguments\n");
		exit(1);
	}
	if (argc > 6)
	{
		printf("too many arguments\n");
		exit(1);
	}
}

void	check_args(int argc, char **args)
{
	check_num_args(argc);
	args++;
	while (*args)
	{
		while (**args)
		{
			if (ft_isdigit(**args) == 0)
			{
				printf("need to be only numbers\n");
				exit(1);
			}
			if (ft_atoi(*args) < 0)
			{
				printf("need to be only positive numbers\n");
				exit(1);
			}
			*args = *args + 1;
		}
		args++;
	}
}

void	init_struct(char **args, t_philo *philo)
{
	philo->philo_num = ft_atoi(args[1]);
	philo->time_die = ft_atoi(args[2]);
	philo->time_ate = ft_atoi(args[3]);
	philo->time_sleep = ft_atoi(args[4]);
	if (args[5] != NULL)
		philo->times_must_eate = ft_atoi(args[5]);
	else
		philo->times_must_eate = -1;
	philo->stop_flag = TRUE;
	philo->phi_lst->start_time = current_time();
	pthread_mutex_init(&philo->check_mutex, NULL);
	pthread_mutex_init(&philo->vigi_mutex, NULL);
}
