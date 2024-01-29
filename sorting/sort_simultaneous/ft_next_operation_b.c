/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_next_operation_b.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vketteni <vketteni@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 18:20:27 by vketteni          #+#    #+#             */
/*   Updated: 2024/01/28 23:02:58 by vketteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

static int	retrieve_head_operation(int stack_top_to_next, int head_to_next)
{
	if (head_to_next < -1)
	{
		if (stack_top_to_next < 0)
			return (REVERSE_ROTATE);
		else if (stack_top_to_next == 0)
			return (SWAP);
		else
			return (ROTATE);
	}
	if (head_to_next > -1)
	{
		if (stack_top_to_next > 1)
			return (ROTATE);
		else if (stack_top_to_next == 1)
			return (SWAP);
		return (REVERSE_ROTATE);
	}
	return (WAIT);
}

static int	retrieve_tail_operation(int stack_top_to_next, int tail_to_next)
{
	if (tail_to_next < 1)
	{
		if (stack_top_to_next < 0)
			return (REVERSE_ROTATE);
		else if (stack_top_to_next == 0)
			return (SWAP);
		else
			return (ROTATE);
	}
	if (tail_to_next > 1)
	{
		if (stack_top_to_next > 1)
			return (ROTATE);
		else if (stack_top_to_next == 1)
			return (SWAP);
		return (REVERSE_ROTATE);
	}
	return (WAIT);
}

int	ft_next_operation_b(t_dlist **stack_b, t_dlist *sorted_sublist[HEAD_TAIL],
		t_dlist *next)
{
	int stack_top_to_next;
	int head_to_next;
	int tail_to_next;

	if (!(*stack_b) || !next || ft_is_sorted_dsc(stack_b))
		return (WAIT);
	stack_top_to_next = ft_distance_between(*stack_b, next);
	head_to_next = ft_distance_between(sorted_sublist[HEAD], next);
	tail_to_next = ft_distance_between(sorted_sublist[TAIL], next);
	if (ft_is_greater_than(next, sorted_sublist[HEAD])
		|| (sorted_sublist[HEAD] == ft_highest_in_stack(stack_b)
			&& next == ft_lowest_in_stack(stack_b)))
		return (retrieve_head_operation(stack_top_to_next, head_to_next));
	else if (!ft_is_greater_than(next, sorted_sublist[TAIL])
		|| (sorted_sublist[TAIL] == ft_lowest_in_stack(stack_b)
			&& next == ft_highest_in_stack(stack_b)))
		return (retrieve_tail_operation(stack_top_to_next, tail_to_next));
	else
		return (WAIT);
}