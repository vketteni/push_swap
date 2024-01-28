/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vketteni <vketteni@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 19:05:44 by vketteni          #+#    #+#             */
/*   Updated: 2024/01/28 19:04:09 by vketteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

static t_dlist	*next_dsc(t_dlist **stack, t_dlist *last)
{
	if (last == ft_lowest_in_stack(stack))
		return (ft_highest_in_stack(stack));
	else
	return (ft_next_lower(stack, last));
}

static t_dlist	*next_asc(t_dlist **stack, t_dlist *last)
{
	if (last == ft_highest_in_stack(stack))
		return (ft_lowest_in_stack(stack));
	else
	return (ft_next_higher(stack, last));
}

t_dlist	*ft_next_a(t_dlist **stack_a, t_dlist *sorted_sublist[HEAD_TAIL], int path_length[HEAD_TAIL])
{
	t_dlist *next_head;
	t_dlist *next_tail;
	int path_head_next;
	int path_tail_next;

	if (*stack_a == NULL || sorted_sublist[HEAD] == NULL
		|| sorted_sublist[TAIL] == NULL)
		return (NULL);
	path_length[A] = 0;
	next_head = next_dsc(stack_a, sorted_sublist[HEAD]);
	next_tail = next_asc(stack_a, sorted_sublist[TAIL]);
	if (next_head == sorted_sublist[TAIL] || next_tail == sorted_sublist[HEAD])
		return (NULL);
	path_head_next = ft_path_length(stack_a, sorted_sublist[HEAD], next_head);
	path_tail_next = ft_path_length(stack_a, sorted_sublist[TAIL], next_tail);
	if (ft_absolute(path_head_next) < ft_absolute(path_tail_next))
	{
		path_length[A] = path_head_next;
		return (next_head);
	}
	path_length[A] = path_tail_next;
	return (next_tail);
}

t_dlist	*ft_next_b(t_dlist **stack_b, t_dlist *sorted_sublist[HEAD_TAIL], int path_length[HEAD_TAIL])
{
	t_dlist *next_head;
	t_dlist *next_tail;
	int path_head_next;
	int path_tail_next;

	if (*stack_b == NULL || sorted_sublist[HEAD] == NULL
		|| sorted_sublist[TAIL] == NULL)
		return (NULL);
	next_head = next_asc(stack_b, sorted_sublist[HEAD]);
	next_tail = next_dsc(stack_b, sorted_sublist[TAIL]);
	if (next_head == sorted_sublist[TAIL] || next_tail == sorted_sublist[HEAD])
		return (NULL);
	path_head_next = ft_path_length(stack_b, sorted_sublist[HEAD], next_head);
	path_tail_next = ft_path_length(stack_b, sorted_sublist[TAIL], next_tail);
	if (ft_absolute(path_head_next) < ft_absolute(path_tail_next))
	{
		path_length[B] = path_head_next;
		return (next_head);
	}
	path_length[B] = path_tail_next;
	return (next_tail);
}
