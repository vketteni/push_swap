/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_simultaneously.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vketteni <vketteni@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 11:57:25 by vketteni          #+#    #+#             */
/*   Updated: 2024/01/24 06:57:06 by vketteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

static int	next_operation(t_dlist **stack, t_dlist *last, t_dlist *next)
{
	int		distance_head_next;
	int		distance_last_next;

	distance_head_next = ft_distance(*stack, next);
	distance_last_next = ft_distance(last, next);
	if (distance_head_next > 1)
		return (ROTATE);
	else if (distance_head_next < -1 || (distance_head_next == 0
			&& distance_last_next < -1))
		return (REVERSE_ROTATE);
	else if (distance_head_next == 1)
		return (SWAP);
	else
		return (-1);
}

static void	update_last_next(t_dlist **stack_a, t_dlist stack_b, t_dlist **last, t_dlist **next)
{
	if (ft_distance(last[A], next[A]) == 1)
		last[A] = last[A]->next_highest;
	if (ft_distance_to_closest_adjacent_value(last[A], last[A]->next_highest,
			last[A]->next_lowest) == -1)
		last[A] = last[A]->next_lowest;
	if (ft_distance_to_closest_adjacent_value(last[B], last[B]->next_highest,
			last[B]->next_lowest) == 1)
		last[B] = last[B]->next_lowest;
	if (ft_distance_to_closest_adjacent_value(last[B], last[B]->next_highest,
			last[B]->next_lowest) == -1)
		last[B] = last[B]->next_highest;
}

t_dlist	*get_next(t_dlist **stack, t_dlist *last)
{
	int		distance_to_lower;
	int		distance_to_higher;
	t_dlist	*next_lower;
	t_dlist	*next_higher;

	next_higher = ft_get_next_higher(stack, *stack);
	next_lower = ft_get_next_lower(stack, *stack);
	distance_to_higher = ft_distance(*stack, next_higher);
	distance_to_lower = ft_distance(*stack, next_lower);
	if (distance_to_lower < distance_to_higher)
		return (next_lower);
	else
		return (next_higher);
}

void	ft_sort_simultaneously(t_dlist **stack_a, t_dlist **stack_b)
{
	int		operation_queue[2];
	t_dlist	*last[2];
	t_dlist	*next[2];

	last[A] = *stack_a;
	last[B] = *stack_b;
	next[A] = get_next(stack_a);
	next[B] = get_next(stack_b);
	while (!ft_is_sorted(stack_a) || !ft_is_sorted(stack_b))
	{
		operation_queue[A] = next_operation(stack_a, last[A], next[A]);
		operation_queue[B] = next_operation(stack_b, last[B], next[A]);
		ft_execute_queue(stack_a, stack_b, operation_queue, last);
		update_last_next(stack_a, stack_b, last, next);
	}
}
