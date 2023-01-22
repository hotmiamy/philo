/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopes-n <llopes-n@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 16:26:34 by hotmiamy          #+#    #+#             */
/*   Updated: 2023/01/22 16:52:13 by llopes-n         ###   ########.fr       */
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
	int	inx;
	int	jnx;

	inx = 1;
	jnx = 0;
	check_num_args(argc);
	while (args[inx])
	{
		while (args[inx][jnx])
		{
			if (ft_isdigit(args[inx][jnx]) == 0)
			{
				printf("need to be only numbers\n");
				exit(1);
			}
			if (ft_atoi(args[inx]) < 0)
			{
				printf("need to be only positive numbers\n");
				exit(1);
			}
			jnx++;
		}
		inx++;
		jnx = 0;
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
	pthread_mutex_init(&philo->print_mutex, NULL);
	pthread_mutex_init(&philo->vigi_mutex, NULL);
	pthread_mutex_init(&philo->check_mutex, NULL);
}

t_bool	check_death(t_philo *philo)
{
	t_bool	tmp;

	pthread_mutex_lock(&philo->check_mutex);
	tmp = philo->stop_flag;
	pthread_mutex_unlock(&philo->check_mutex);
	return (tmp);
}
