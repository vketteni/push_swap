/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vketteni <vketteni@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 21:27:14 by vketteni          #+#    #+#             */
/*   Updated: 2024/01/23 16:59:12 by vketteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	swap(t_dlist **stack)
{
	t_dlist	*second;

	if (stack == NULL)
		return ;
	if (*stack == NULL)
		return ;
	if ((*stack)->next == NULL)
		return ;
	second = (*stack)->next;
	(*stack)->next = second->next;
	second->next = *stack;
	stack = &second;
}

void	ft_sa(t_dlist **stack_a)
{
	swap(stack_a);
	ft_printf("sa ");
}

void	ft_sb(t_dlist **stack_b)
{
	swap(stack_b);
	ft_printf("sb ");
}

void	ft_ss(t_dlist **stack_a, t_dlist **stack_b)
{
	swap(stack_a);
	swap(stack_b);
	ft_printf("ss ");
}