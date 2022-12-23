/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hotmiamy <hotmiamy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 09:32:24 by llopes-n          #+#    #+#             */
/*   Updated: 2022/12/23 12:01:46 by hotmiamy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

//pthread functions
# include <pthread.h>
//malloc
# include <stdlib.h>
//printf
# include <stdio.h>
//gettymeofday
# include <sys/time.h>
// sleep
# include <unistd.h>

# define INT_MIN -2147483648
# define INT_MAX 2147483647

typedef struct s_phi_lst
{
	int					id;
	long				start_time;
	pthread_t			thread;
	struct s_philo		*philo;
	struct s_phi_lst	*next;
}	t_phi_lst;

typedef struct s_philo
{
	int			philo_num;
	t_phi_lst	*phi_lst;
}	t_philo;

void		phi_lstadd_back(t_phi_lst **lst, t_phi_lst *new);
void		fill_phi_lst(t_philo *philo);
void		*routine(void *node);
void		init(t_philo *philo, char *philo_num);
int			ft_atoi(const char *numstr);
long		current_time(void);
t_phi_lst	*phi_lst_new(int id, t_philo *philo);

#endif