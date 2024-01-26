/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_distance_between.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vketteni <vketteni@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 19:27:31 by vketteni          #+#    #+#             */
/*   Updated: 2024/01/25 23:00:13 by vketteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	forwards(t_dlist *start, t_dlist *end)
{
	int distance;
	t_dlist *tmp;
	t_dlist *head;

	tmp = start;
	while (tmp->prev != NULL)
		tmp = tmp->prev;
	head = tmp;
	tmp = start;
	distance = 0;
	while (tmp != end)
	{
		if (tmp->next == NULL)
			tmp = head;
		else 
			tmp = tmp->next;
		distance++;
	}
	return (distance);
}

static int	backwards(t_dlist *start, t_dlist *end)
{
	int distance;
	t_dlist *tmp;
	t_dlist *tail;

	distance = 0;
	tail = ft_dlstlast(start);
	tmp = start;
	while (tmp != end)
	{
		if (tmp->prev == NULL)
			tmp = tail;
		else 
			tmp = tmp->prev;
		distance++;
	}
	return (distance);
}

int	ft_distance_between(t_dlist *start, t_dlist *end)
{
	int	distance_forwards;
	int	distance_backwards;
	
	distance_forwards = forwards(start, end);
	distance_backwards = backwards(start, end);
	if (distance_forwards < distance_backwards)
		return (distance_forwards);
	return (-distance_backwards);
}