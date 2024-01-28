/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   distances.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vketteni <vketteni@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 14:36:38 by vketteni          #+#    #+#             */
/*   Updated: 2024/01/28 14:24:48 by vketteni         ###   ########.fr       */
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
	t_dlist *first;
	t_dlist *last;
	int distance;

	distance = 0;
	first = start;
	last = ft_dlstlast(start);
	while (first != last)
	{
		if (*(int *)(last->content) < *(int *)(median->content))
			return (-(++distance));
		if (*(int *)(first->content) < *(int *)(median->content))
			return (distance);
		first = first->next;
		last = last->prev;
		distance++;
	}
	ft_printf("Error\ft_distance_to_closest_lt_median\n");
	exit(-1);
}