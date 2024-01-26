/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_next_operation_b.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vketteni <vketteni@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 18:20:27 by vketteni          #+#    #+#             */
/*   Updated: 2024/01/25 23:09:27 by vketteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

static int	next_operation_gt_dsc(int distance_head_next, int distance_last_next)
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

static int	next_operation_lt_dsc(int distance_head_next, int distance_last_next)
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


int	ft_next_operation_b(t_dlist **stack_b, t_dlist *last, t_dlist *next)
{
	int	distance_head_next;
	int	distance_last_next;

	if (!(*stack_b) || !next || ft_is_sorted_dsc(stack_b))
		return (WAIT);
	distance_head_next = ft_distance_between(*stack_b, next);
	distance_last_next = ft_distance_between(last, next);
	if (ft_is_greater_than(next, last))
		return (next_operation_gt_dsc(distance_head_next,
				distance_last_next));
	else
		return (next_operation_lt_dsc(distance_head_next,
				distance_last_next));
}