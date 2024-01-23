/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vketteni <vketteni@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 22:15:55 by vketteni          #+#    #+#             */
/*   Updated: 2024/01/23 16:58:44 by vketteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	rotate(t_dlist **stack)
{
	t_dlist	*last;

	if (stack == NULL)
		return ;
	if (*stack == NULL)
		return ;
	if ((*stack)->next == NULL)
		return ;
	last = ft_dlstlast(*stack);
	stack = &((*stack)->next);
	last->next = (*stack)->prev;
	(last->next)->prev = last;
	(last->next)->next = NULL;
	(*stack)->prev =  NULL;
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