/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vketteni <vketteni@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 22:15:55 by vketteni          #+#    #+#             */
/*   Updated: 2024/01/27 12:17:26 by vketteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	rotate(t_dlist **stack)
{
	t_dlist	*last;
	t_dlist	*first;
	t_dlist	*second;

	if (stack == NULL)
		return ;
	if (*stack == NULL)
		return ;
	if ((*stack)->next == NULL)
		return ;
	last = ft_dlstlast(*stack);
	first = *stack;
	second = first->next;
	*stack = second;
	last->next = first;
	first->prev = last;
	first->next = NULL;
	second->prev = NULL;
}

void	ft_ra(t_dlist **stack_a)
{
	rotate(stack_a);
	ft_printf("ra ");
}

void	ft_rb(t_dlist **stack_b)
{
	rotate(stack_b);
	ft_printf("rb ");
}

void	ft_rr(t_dlist **stack_a, t_dlist **stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
	ft_printf("rr ");
}