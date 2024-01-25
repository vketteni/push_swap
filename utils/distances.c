/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   distances.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vketteni <vketteni@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 14:36:38 by vketteni          #+#    #+#             */
/*   Updated: 2024/01/25 19:58:27 by vketteni         ###   ########.fr       */
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
	int		size;
	t_dlist	*first;

	first = start;
	while (first != 0)
		first = first->prev;
	size = ft_dlstsize(first);
	distance = 0;
	while (start != end)
	{
		start = start->next;
		distance++;
	}
	return (size - distance);
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