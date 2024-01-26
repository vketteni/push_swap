/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_simultaneous.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vketteni <vketteni@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 11:57:25 by vketteni          #+#    #+#             */
/*   Updated: 2024/01/24 18:33:11 by vketteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

static void	update_last_next(t_dlist ***stacks, t_dlist **last, t_dlist **next)
{
	while (*(stacks[A]) && next[A] && ft_is_greater_than(next[A], last[A])
		&& ft_distance_between(last[A], next[A]) == 1)
	{
		last[A] = next[A];
		next[A] = ft_get_next_a(stacks[A], last[A]);
	}
	while (*(stacks[A]) && next[A] && !ft_is_greater_than(next[A], last[A])
		&& ft_distance_between(last[A], next[A]) == -1)
	{
		last[A] = next[A];
		next[A] = ft_get_next_a(stacks[A], last[A]);
	}
	while (*(stacks[B]) && next[B] && ft_is_greater_than(next[B], last[B])
		&& ft_distance_between(last[B], next[B]) == -1)
	{
		last[B] = next[B];
		next[B] = ft_get_next_b(stacks[B], last[B]);
	}
	while (*(stacks[B]) && next[B] && !ft_is_greater_than(next[B], last[B])
		&& ft_distance_between(last[B], next[B]) == 1)
	{
		last[B] = next[B];
		next[B] = ft_get_next_b(stacks[B], last[B]);
	}
}

void	ft_sort_simultaneous(t_dlist **stack_a, t_dlist **stack_b)
{
	int		operation_queue[2];
	t_dlist	*last[2];
	t_dlist	*next[2];
	t_dlist	**stacks[2];

	last[A] = *stack_a;
	last[B] = *stack_b;
	next[A] = ft_get_next_a(stack_a, *stack_a);
	next[B] = ft_get_next_b(stack_b, *stack_b);
	stacks[A] = stack_a;
	stacks[B] = stack_b;
	while (!ft_is_sorted_asc(stack_a) || !ft_is_sorted_dsc(stack_b))
	{
		operation_queue[A] = ft_next_operation_a(stack_a, last[A], next[A]);
		operation_queue[B] = ft_next_operation_b(stack_b, last[B], next[A]);
		ft_execute_queue(operation_queue, stacks, last, next);
		update_last_next(stacks, last, next);
	}
}
