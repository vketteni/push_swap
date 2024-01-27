/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   distances.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vketteni <vketteni@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 14:36:38 by vketteni          #+#    #+#             */
/*   Updated: 2024/01/27 10:40:51 by vketteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"


int	ft_distance_by_rotation(t_dlist *start, t_dlist *end)
{
	int	distance;

	distance = 0;
	while (start != end)
	{
		start = start->next;
		distance++;
	}
	return (distance);
}

int	ft_distance_by_reverse_rotation(t_dlist *start, t_dlist *end)
{
	int		distance;

	if (start == end)
		return (0);
	start = ft_dlstlast(start);
	distance = 1;
	while (start != end)
	{
		start = start->prev;
		distance++;
	}
	return (distance);
}

int	ft_distance_to_closest_lt_median(t_dlist *start, t_dlist *median)
{
	t_dlist *head;
	t_dlist *tail;
	int distance;

	distance = 0;
	head = start;
	tail = ft_dlstlast(start);
	while (head != NULL && tail != NULL)
	{
		if (*(int *)(tail->content) < *(int *)(median->content))
			return (-(++distance));
		if (*(int *)(head->content) < *(int *)(median->content))
			return (distance);
		distance++;
	}
	ft_printf("Error\ft_distance_to_closest_lt_median\n");
	exit(-1);
}