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

static void	update_last_next(t_dlist ***stacks, t_dlist **last, t_dlist **next)
{
	while (*(stacks[A]) && ft_absolute(ft_distance(last[A], next[A])) == 1)
	{
		last = next;
		next = ft_get_next(stacks[A], last);
	}
	while (*(stacks[B]) && ft_absolute(ft_distance(last[B], next[B])) == 1)
	{
		last = next;
		next = ft_get_next(stacks[B], last);
	}
}

static int	is_simultaneous(int operation)
{
	if (operation == ROTATE || operation == REVERSE_ROTATE || operation == SWAP)
		return (1);
	return (0);
}

void	ft_sort_simultaneous(t_dlist **stack_a, t_dlist **stack_b)
{
	int		operation_queue[2];
	t_dlist	*last[2];
	t_dlist	*next[2];
	t_dlist	**stacks[2];

	last[A] = *stack_a;
	last[B] = *stack_b;
	next[A] = ft_get_next(stack_a, *stack_a);
	next[B] = ft_get_next(stack_b, *stack_b);
	stacks[A] = stack_a;
	stacks[B] = stack_b;
	while (!ft_is_sorted_asc(stack_a) || !ft_is_sorted_dsc(stack_b))
	{
		operation_queue[A] = next_operation(stack_a, last[A], next[A]);
		operation_queue[B] = next_operation(stack_b, last[B], next[A]);
		if (operation_queue[A] == operation_queue[B]
			&& is_simultaneous(operation_queue[A]))
			execute_simultanous(stacks, operation_queue);
		else
			ft_execute_stacks(stacks, operation_queue);

		update_last_next(stacks, last, next);
	}
}
