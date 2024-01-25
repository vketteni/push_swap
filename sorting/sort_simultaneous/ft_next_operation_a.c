/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_next_operation_a.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vketteni <vketteni@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 17:24:59 by vketteni          #+#    #+#             */
/*   Updated: 2024/01/25 19:45:56 by vketteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

static int	next_operation_gt_asc(int distance_head_next, int distance_last_next)
{
	if (distance_last_next < 1)
	{
		if (distance_head_next < 0)
			return (REVERSE_ROTATE);
		else if (distance_head_next == 0)
			return (SWAP);
		else
			return (ROTATE);
	}
	if (distance_last_next > 1)
	{
		if (distance_head_next > 1)
			return (ROTATE);
		else if (distance_head_next == 1)
			return (SWAP);
		return (REVERSE_ROTATE);
	}
	return (WAIT);
}

static int	next_operation_lt_asc(int distance_head_next, int distance_last_next)
{
	if (distance_last_next < -1)
	{
		if (distance_head_next < 0)
			return (REVERSE_ROTATE);
		else if (distance_head_next == 0)
			return (SWAP);
		else
			return (ROTATE);
	}
	if (distance_last_next > -1)
	{
		if (distance_head_next > 1)
			return (ROTATE);
		else if (distance_head_next == 1)
			return (SWAP);
		return (REVERSE_ROTATE);
	}
	return (WAIT);
}

int	ft_next_operation_a(t_dlist **stack, t_dlist *last, t_dlist *next)
{
	int	distance_head_next;
	int	distance_last_next;

	if (!(*stack) || !next)
		return (WAIT);
	distance_head_next = ft_distance_between(*stack, next);
	distance_last_next = ft_distance_between(last, next);
	if (ft_is_greater_than(next, last))
		return (next_operation_gt_asc(distance_head_next,
				distance_last_next));
	else
		return (next_operation_lt_asc(distance_head_next,
				distance_last_next));
}