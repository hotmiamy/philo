/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopes-n <llopes-n@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 09:32:24 by llopes-n          #+#    #+#             */
/*   Updated: 2022/10/28 16:21:37 by llopes-n         ###   ########.fr       */
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

# define INT_MIN -2147483648
# define INT_MAX 2147483647

typedef struct s_phi_lst
{
	int					id;
	pthread_t			thread;
	struct s_phi_lst	*next;
}	t_phi_lst;

typedef struct s_philo
{
	int			philo_num;
	t_phi_lst	*phi_lst;
}	t_philo;

t_phi_lst	*phi_lst_new(int id);
void		phi_lstadd_back(t_phi_lst **lst, t_phi_lst *new);
void		fill_phi_lst(t_philo *philo);
int			ft_atoi(const char *numstr);

#endif