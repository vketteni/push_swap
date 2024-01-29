/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vketteni <vketteni@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 23:53:04 by vketteni          #+#    #+#             */
/*   Updated: 2024/01/29 11:14:35 by vketteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

static int	update_condition_dsc(t_dlist **stack_b, t_dlist *last,
		t_dlist *next)
{
	if (next == ft_next_lower(stack_b, last)
		|| (last == ft_lowest_in_stack(stack_b)
			&& next == ft_highest_in_stack(stack_b)))
		return (1);
	return (0);
}

static int	update_condition_asc(t_dlist **stack_b, t_dlist *last,
		t_dlist *next)
{
	if (next == ft_next_higher(stack_b, last)
		|| (last == ft_highest_in_stack(stack_b)
			&& next == ft_lowest_in_stack(stack_b)))
		return (1);
	return (0);
}

void	ft_update_a(t_dlist **stack_a, t_dlist *sorted_sublist[HEAD_TAIL],
		int path_length[A_B], t_dlist *next[A_B])
{
	t_dlist	*head;
	t_dlist	*tail;

	head = sorted_sublist[HEAD];
	tail = sorted_sublist[TAIL];
	while (*stack_a && next[A] && ft_distance_between(tail, next[A]) == 1
		&& update_condition_asc(stack_a, tail, next[A]))
	{
		sorted_sublist[TAIL] = next[A];
		next[A] = ft_next_a(stack_a, sorted_sublist, path_length);
	}
	while (*stack_a && next[A] && ft_distance_between(head, next[A]) == -1
		&& update_condition_dsc(stack_a, head, next[A]))
	{
		sorted_sublist[HEAD] = next[A];
		next[A] = ft_next_a(stack_a, sorted_sublist, path_length);
	}
	if (next[A] == NULL || head == next[A] || tail == next[A])
		path_length = 0;
}

void	ft_update_b(t_dlist **stack_b, t_dlist *sorted_sublist[HEAD_TAIL],
		int path_length[A_B], t_dlist *next[A_B])
{
	t_dlist	*tail;
	t_dlist	*head;

	head = sorted_sublist[HEAD];
	tail = sorted_sublist[TAIL];
	while (*stack_b && next[B] && ft_distance_between(tail, next[B]) == 1
		&& update_condition_dsc(stack_b, tail, next[B]))
	{
		sorted_sublist[TAIL] = next[B];
		next[B] = ft_next_b(stack_b, sorted_sublist, path_length);
	}
	while (*stack_b && next[B] && ft_distance_between(head, next[B]) == -1
		&& update_condition_asc(stack_b, sorted_sublist[HEAD], next[B]))
	{
		sorted_sublist[HEAD] = next[B];
		next[B] = ft_next_b(stack_b, sorted_sublist, path_length);
	}
	if (next[B] == NULL || head == next[B] || tail == next[B])
		path_length[A] = 0;
}
