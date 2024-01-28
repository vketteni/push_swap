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

static void	update_a(t_dlist **stack_a, t_dlist *sorted_sublist[HEAD_TAIL],
		int path_length[A_B], t_dlist *next[A_B])
{
	while (*stack_a && next[A] && (ft_is_greater_than(next[A], sorted_sublist[TAIL])
			&& ft_distance_between(sorted_sublist[TAIL], next[A]) == 1))
	{
		sorted_sublist[TAIL] = next[A];
		next[A] = ft_next_a(stack_a, sorted_sublist, path_length);
	}
	while (*stack_a && next[A] && (!ft_is_greater_than(next[A], sorted_sublist[HEAD])
			&& ft_distance_between(sorted_sublist[HEAD], next[A]) == -1))
	{
		sorted_sublist[HEAD] = next[A];
		next[A] = ft_next_a(stack_a, sorted_sublist, path_length);
	}
	if (next[A] == NULL)
		path_length[A] = 0;
}

static void	update_b(t_dlist **stack_b, t_dlist *sorted_sublist[HEAD_TAIL],
		int path_length[A_B], t_dlist *next[A_B])
{
	while (*stack_b && next[B] && (!ft_is_greater_than(next[B], sorted_sublist[TAIL])
			&& ft_distance_between(sorted_sublist[TAIL], next[B]) == 1))
	{
		sorted_sublist[TAIL] = next[B];
		next[B] = ft_next_b(stack_b, sorted_sublist, path_length);
	}
	while (*stack_b && next[B] && (ft_is_greater_than(next[B], sorted_sublist[HEAD])
			&& ft_distance_between(sorted_sublist[HEAD], next[B]) == -1))
	{
		sorted_sublist[HEAD] = next[B];
		next[B] = ft_next_b(stack_b, sorted_sublist, path_length);
	}
	if (next[B] == NULL)
		path_length[A] = 0;
}



static void	initialize_sorted_sublists(t_dlist **stack_a, t_dlist **stack_b,
		t_dlist *sorted_sublist[A_B][HEAD_TAIL])
{
	sorted_sublist[A][HEAD] = *stack_a;
	sorted_sublist[B][HEAD] = *stack_b;
	sorted_sublist[A][TAIL] = *stack_a;
	sorted_sublist[B][TAIL] = *stack_b;
	ft_initialize_sorted_sublist_a(sorted_sublist[A], stack_a);
	ft_initialize_sorted_sublist_b(sorted_sublist[B], stack_b);
}

void	ft_sort_simultaneous(t_dlist **stack_a, t_dlist **stack_b)
{
	int		operation_queue[A_B];
	t_dlist	*sorted_sublist[A_B][HEAD_TAIL];
	t_dlist	*next[A_B];
	int		path_length[A_B];

	initialize_sorted_sublists(stack_a, stack_b, sorted_sublist);
	next[A] = ft_next_a(stack_a, sorted_sublist[A], path_length);
	next[B] = ft_next_b(stack_b, sorted_sublist[B], path_length);
	while (!ft_is_sorted_asc(stack_a) || !ft_is_sorted_dsc(stack_b))
	{
		operation_queue[A] = ft_next_operation_a(stack_a, sorted_sublist,
				next[A]);
		operation_queue[B] = ft_next_operation_b(stack_b, sorted_sublist,
				next[B]);
		ft_execute_queue(stack_a, stack_b, operation_queue, path_length);
		if (!ft_is_sorted_asc(stack_a))
			update_a(stack_a, sorted_sublist[A], path_length, next);
		if (!ft_is_sorted_dsc(stack_b))
			update_b(stack_b, sorted_sublist[B], path_length, next);
	}
}
