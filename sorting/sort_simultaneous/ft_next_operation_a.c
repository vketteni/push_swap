/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_next_operation_a.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vketteni <vketteni@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 17:24:59 by vketteni          #+#    #+#             */
/*   Updated: 2024/01/26 20:43:02 by vketteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

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
	else if (tail_to_next > 1)
	{
		if (stack_top_to_next > 1)
			return (ROTATE);
		else if (stack_top_to_next == 1)
			return (SWAP);
		return (REVERSE_ROTATE);
	}
	return (WAIT);
}

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
	else if (head_to_next > -1)
	{
		if (stack_top_to_next > 1)
			return (ROTATE);
		else if (stack_top_to_next == 1)
			return (SWAP);
		return (REVERSE_ROTATE);
	}
	return (WAIT);
}

int	ft_next_operation_a(t_dlist **stack_a, t_dlist *sorted_sublist[A_B][HEAD_TAIL], t_dlist *next)
{
	int	stack_top_to_next;
	int	head_to_next;
	int	tail_to_next;

	if (!(*stack_a) || !next)
		return (WAIT);
	stack_top_to_next = ft_distance_between(*stack_a, next);
	head_to_next = ft_distance_between(sorted_sublist[A][HEAD], next);
	tail_to_next = ft_distance_between(sorted_sublist[A][TAIL], next);
	if (ft_is_greater_than(next, sorted_sublist[A][TAIL]))
		return (retrieve_tail_operation(stack_top_to_next,
				tail_to_next));
	else
		return (retrieve_head_operation(stack_top_to_next,
				head_to_next));
}