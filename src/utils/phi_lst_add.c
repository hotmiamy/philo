/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phi_lst_add.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hotmiamy <hotmiamy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 15:04:03 by llopes-n          #+#    #+#             */
/*   Updated: 2022/12/23 11:31:21 by hotmiamy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_phi_lst	*phi_lst_new(int id, t_philo *philo)
{
	t_phi_lst	*new_node;

	new_node = malloc(sizeof(t_phi_lst));
	new_node->id = id;
	new_node->philo = philo;
	new_node->next = NULL;
	return (new_node);
}

void	phi_lstadd_back(t_phi_lst **lst, t_phi_lst *new)
{
	t_phi_lst	*head;

	if (*lst == NULL)
		*lst = new;
	else
	{
		head = *lst;
		while ((*lst)->next != head && (*lst)->next)
			*lst = (*lst)->next;
		(*lst)->next = new;
		new->next = head;
		*lst = head;
	}
}
