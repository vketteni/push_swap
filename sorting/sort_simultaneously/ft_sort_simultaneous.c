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

static int	next_operation(t_dlist **stack, t_dlist *last, t_dlist *next)
{
	int	distance_head_next;
	int	distance_last_next;

	if (!(*stack))
		return (-1);
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

t_dlist	*get_next(t_dlist **stack, t_dlist *last)
{
	int		distance_to_lower;
	int		distance_to_higher;
	t_dlist	*next_lower;
	t_dlist	*next_higher;

	if (!(*stack))
		return (0);
	next_higher = ft_next_higher(stack, last);
	next_lower = ft_next_lower(stack, last);
	distance_to_higher = ft_distance(*stack, next_higher);
	distance_to_lower = ft_distance(*stack, next_lower);
	if (distance_to_lower < distance_to_higher)
		return (next_lower);
	else
		return (next_higher);
}

static void	update_last_next(t_dlist ***stacks, t_dlist **last, t_dlist **next)
{
	while (*(stacks[A]) && ft_absolute(ft_distance(last[A], next[A])) == 1)
	{
		last[A] = next[A];
		next[A] = get_next(stacks[A], last[A]);
	}
	while (*(stacks[B]) && ft_absolute(ft_distance(last[B], next[B])) == 1)
	{
		last[B] = next[B];
		next[B] = get_next(stacks[B], last[B]);
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
	next[A] = get_next(stack_a, *stack_a);
	next[B] = get_next(stack_b, *stack_b);
	stacks[A] = stack_a;
	stacks[B] = stack_b;
	while (!ft_is_sorted_asc(stack_a) || !ft_is_sorted_dsc(stack_b))
	{
		operation_queue[A] = next_operation(stack_a, last[A], next[A]);
		operation_queue[B] = next_operation(stack_b, last[B], next[A]);
		ft_execute_queue(operation_queue, stacks, last, next);
		update_last_next(stacks, last, next);
	}
}
