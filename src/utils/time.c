/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hotmiamy <hotmiamy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 10:57:26 by hotmiamy          #+#    #+#             */
/*   Updated: 2022/12/23 11:59:18 by hotmiamy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	current_time(void)
{
	struct timeval	cur_time;

	gettimeofday(&cur_time, NULL);
	return ((cur_time.tv_sec * 1000) + (cur_time.tv_usec / 1000));
}

void	msleep(int sleep_time)
{
	long	start_time;

	start_time = current_time();
	while (current_time() - start_time < (long)sleep_time)
		sleep(10);
}
