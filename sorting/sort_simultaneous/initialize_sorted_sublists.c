/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_sorted_sublists.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vketteni <vketteni@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 13:15:10 by vketteni          #+#    #+#             */
/*   Updated: 2024/01/28 19:38:16 by vketteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	ft_initialize_sorted_sublist_a(t_dlist *sorted_sublist[HEAD_TAIL],
		t_dlist **stack_a)
{
	t_dlist	*last;
	t_dlist	*tail;
	t_dlist	*head;

	tail = sorted_sublist[TAIL];
	while ((ft_next_higher(stack_a, tail) == tail->next && tail->next != NULL)
		|| (ft_highest_in_stack(stack_a) == tail
			&& ft_lowest_in_stack(stack_a) == tail->next && tail->next != NULL))
	{
		sorted_sublist[TAIL] = tail->next;
		tail = tail->next;
	}
	last = ft_dlstlast(*stack_a);
	head = sorted_sublist[HEAD];
	while ((ft_next_lower(stack_a, head) == last && last != NULL)
		|| (ft_lowest_in_stack(stack_a) == head
			&& ft_highest_in_stack(stack_a) == last && last != NULL))
	{
		sorted_sublist[HEAD] = last;
		last = last->prev;
	}
}

void	ft_initialize_sorted_sublist_b(t_dlist *sorted_sublist[HEAD_TAIL],
		t_dlist **stack_b)
{
	t_dlist *last;
	t_dlist *tail;
	t_dlist *head;

	tail = sorted_sublist[TAIL];
	while ((ft_next_lower(stack_b, tail) == tail->next && tail->next != NULL)
		|| (ft_lowest_in_stack(stack_b) == tail
			&& ft_highest_in_stack(stack_b) == tail->next
			&& tail->next != NULL))
	{
		sorted_sublist[TAIL] = tail->next;
		tail = tail->next;
	}
	last = ft_dlstlast(*stack_b);
	head = sorted_sublist[HEAD];
	while ((ft_next_higher(stack_b, head) == last && last != NULL)
		|| (ft_highest_in_stack(stack_b) == head
			&& ft_lowest_in_stack(stack_b) == last && last != NULL))
	{
		sorted_sublist[HEAD] = last;
		last = last->prev;
	}
}