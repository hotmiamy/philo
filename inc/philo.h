/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopes-n <llopes-n@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 09:32:24 by llopes-n          #+#    #+#             */
/*   Updated: 2023/01/22 17:46:11 by llopes-n         ###   ########.fr       */
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

# define DEAD "died"
# define EAT "is eating"
# define THINK "is thinking"
# define SLEEP "is sleeping"
# define FORK "has taken a fork"

typedef enum e_bool
{
	FALSE,
	TRUE
}	t_bool;

typedef struct s_phi_lst
{
	int					id;
	int					times_ate;
	long				start_time;
	long				last_meat;
	pthread_t			thread;
	pthread_mutex_t		fork;
	struct s_philo		*philo;
	struct s_phi_lst	*next;
}	t_phi_lst;

typedef struct s_philo
{
	int					philo_num;
	int					times_must_eate;
	int					time_sleep;
	int					time_die;
	int					time_ate;
	t_bool				stop_flag;
	pthread_mutex_t		print_mutex;
	pthread_mutex_t		check_mutex;
	pthread_mutex_t		vigi_mutex;
	pthread_t			vigi_thread;
	t_phi_lst			*phi_lst;
}	t_philo;

void		phi_lstadd_back(t_phi_lst **lst, t_phi_lst *new);
void		fill_phi_lst(t_philo *philo);
void		*init(t_philo *philo, char **args, int argc);
void		msleep(int sleep_time);
void		free_lst(t_phi_lst *phi_lst);
void		*routine(void *node);
void		*vigilant(void *node);
void		destroy_mutex(t_philo *philo);
void		init_struct(char **args, t_philo *philo);
void		check_args(int argc, char **args);
void		set_stop_flag(t_philo *philo);
int			slepping(t_phi_lst *phi_lst);
int			thinking(t_phi_lst *phi_lst);
int			ft_atoi(const char *numstr);
int			ft_isdigit(int c);
long		current_time(void);
t_bool		print_action(t_phi_lst *phi_lst, char *action);
t_bool		check_death(t_philo *philo);
t_bool		last_eating(t_phi_lst *phi_lst);
t_bool		eating(t_phi_lst *phi_lst);
t_phi_lst	*phi_lst_new(int id, t_philo *philo);

#endif