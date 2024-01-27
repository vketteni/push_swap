/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_sorted_sublists.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vketteni <vketteni@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 13:15:10 by vketteni          #+#    #+#             */
/*   Updated: 2024/01/27 14:32:48 by vketteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void    ft_initialize_sorted_sublist_a(t_dlist *sorted_sublist[A_B][HEAD_TAIL], t_dlist **stack_a)
{
	t_dlist *first;
	t_dlist *last;

	first = *stack_a;
	last = ft_dlstlast(*stack_a); 
	while (ft_next_higher(stack_a, sorted_sublist[A][TAIL]) == first->next && sorted_sublist[A][TAIL]->next != NULL)
	{
		sorted_sublist[A][TAIL] = sorted_sublist[A][TAIL]->next;
		first = first->next;
	}
	while (ft_next_lower(stack_a, sorted_sublist[A][HEAD]) == last && sorted_sublist[A][TAIL]->prev)
	{
		sorted_sublist[A][HEAD] = last;
		last = last->prev;
	}
}

void    ft_initialize_sorted_sublist_b(t_dlist *sorted_sublist[A_B][HEAD_TAIL], t_dlist **stack_b)
{
	t_dlist *first;
	t_dlist *last;
	first = *stack_b;
	last = ft_dlstlast(*stack_b); 
	while (ft_next_lower(stack_b, sorted_sublist[B][TAIL]) == first->next  && sorted_sublist[B][TAIL]->next != NULL)
	{
		sorted_sublist[B][TAIL] = sorted_sublist[B][TAIL]->next;
		first = first->next;
	}
	while (ft_next_higher(stack_b, sorted_sublist[B][HEAD]) == last)
	{
		sorted_sublist[B][HEAD] = last;
		last = last->prev;
	}
}