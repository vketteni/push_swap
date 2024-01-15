/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vketteni <vketteni@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 22:15:55 by vketteni          #+#    #+#             */
/*   Updated: 2024/01/13 13:29:44 by vketteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	**rotate(t_list **stack)
{
	t_list	*first;

	if (stack == NULL)
		return ;
	if (*stack == NULL)
		return ;
	if ((*stack)->next == NULL)
		return ;
	first = *stack;
	*stack = (*stack)->next;
	first->next = NULL;
	ft_lstlast(*stack)->next = first;
	return (stack);
}

t_list	**ft_reverse_rotate(t_list **stack)
{
	t_list	*second_last;

	if (stack == NULL)
		return ;
	if (*stack == NULL)
		return ;
	if ((*stack)->next == NULL)
		return ;
	while ((second_last->next)->next != NULL)
		second_last = second_last->next;
	(second_last->next)->next = *stack;
	stack = &(second_last->next);
	(second_last)->next = NULL;
	return (stack);
}