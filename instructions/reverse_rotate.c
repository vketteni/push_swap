/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vketteni <vketteni@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 11:32:13 by vketteni          #+#    #+#             */
/*   Updated: 2024/01/23 16:59:00 by vketteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	reverse_rotate(t_dlist **stack)
{
	t_dlist	*first;
	t_dlist	*last;

	if (stack == NULL)
		return ;
	if (*stack == NULL)
		return ;
	if ((*stack)->next == NULL)
		return ;
	first = *stack;
	last = ft_dlstlast(*stack);
	stack = &last;
	first->prev = last;
	last->next = first;
	(last->prev)->next = NULL;
	last->prev = NULL;
}

void	ft_rra(t_dlist **stack_a)
{
	reverse_rotate(stack_a);
	ft_printf("rra ");
}

void	ft_rrb(t_dlist **stack_b)
{
	reverse_rotate(stack_b);
	ft_printf("rrb ");
}

void	ft_rrr(t_dlist **stack_a, t_dlist **stack_b)
{
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
	ft_printf("rrr ");
}