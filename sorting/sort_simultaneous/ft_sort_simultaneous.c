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

static void	update_a(t_dlist **stack, t_dlist *sorted_sublist[A_B][HEAD_TAIL],
		int *path_length, t_dlist **next)
{
	while (*stack && next[A])
	{
		if (ft_is_greater_than(next[A], sorted_sublist[A][TAIL])
			&& ft_distance_between(sorted_sublist[A][TAIL], next[A]) == 1)
		{
			sorted_sublist[A][TAIL] = next[A];
			next[A] = ft_get_next(stack, sorted_sublist, path_length, A);
			path_length[A] = 0;
		}
		if (!ft_is_greater_than(next[A], sorted_sublist[A][TAIL])
			&& ft_distance_between(sorted_sublist[A][HEAD], next[A]) == -1)
		{
			sorted_sublist[A][HEAD] = next[A];
			next[A] = ft_get_next(stack, sorted_sublist, path_length, A);
			path_length[A] = 0;
		}
		else
			break ;
	}
}

static void	update_b(t_dlist **stack, t_dlist *sorted_sublist[A_B][HEAD_TAIL],
		int *path_length, t_dlist **next)
{
	while (*stack && next[B])
	{
		if (ft_is_greater_than(next[B], sorted_sublist[B][HEAD])
			&& (ft_distance_between(sorted_sublist[B][HEAD], next[B]) == -1))
		{
			sorted_sublist[B][HEAD] = next[B];
			next[B] = ft_get_next(stack, sorted_sublist, path_length, B);
			path_length[B] = 0;
		}
		if (!ft_is_greater_than(next[B], sorted_sublist[B][TAIL])
			&& (ft_distance_between(sorted_sublist[B][TAIL], next[B]) == 1))
		{
			sorted_sublist[B][HEAD] = next[B];
			next[B] = ft_get_next(stack, sorted_sublist, path_length, B);
			path_length[B] = 0;
		}
		else
			break ;
	}
}

static void	initialize_start(t_dlist **stack_a, t_dlist **stack_b,
		int *path_length, t_dlist *sorted_sublist[A_B][HEAD_TAIL])
{
	path_length[A] = 0;
	path_length[B] = 0;
	sorted_sublist[A][HEAD] = *stack_a;
	sorted_sublist[B][HEAD] = *stack_b;
	sorted_sublist[A][TAIL] = *stack_a;
	sorted_sublist[B][TAIL] = *stack_b;
}

void	ft_sort_simultaneous(t_dlist **stack_a, t_dlist **stack_b)
{
	int		operation_queue[A_B];
	t_dlist	*sorted_sublist[A_B][HEAD_TAIL];
	t_dlist	*next[A_B];
	int		path_length[A_B];

	initialize_start(stack_a, stack_b, path_length, sorted_sublist);
	next[A] = ft_get_next(stack_a, sorted_sublist, path_length, A);
	next[B] = ft_get_next(stack_b, sorted_sublist, path_length, B);
	while (!ft_is_sorted_asc(stack_a) || !ft_is_sorted_dsc(stack_b))
	{
		operation_queue[A] = ft_next_operation_a(stack_a, sorted_sublist,
				next[A]);
		operation_queue[B] = ft_next_operation_b(stack_b, sorted_sublist,
				next[B]);
		ft_execute_queue(stack_a, stack_b, operation_queue, path_length);
		if (!ft_is_sorted_asc(stack_a))
			update_a(stack_a, sorted_sublist, path_length, next);
		if (!ft_is_sorted_dsc(stack_b))
			update_b(stack_b, sorted_sublist, path_length, next);
	}
}
