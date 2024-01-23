/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vketteni <vketteni@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 22:10:10 by vketteni          #+#    #+#             */
/*   Updated: 2024/01/23 16:58:37 by vketteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	push(t_dlist **stack_a, t_dlist **stack_b)
{
	t_dlist	*tmp_ref;

	if (stack_b == NULL || stack_a == NULL)
		return ;
	if (*stack_a == NULL)
		return ;
	tmp_ref = *stack_a;
	*stack_a = (*stack_a)->next;
	tmp_ref->next = *stack_b;
	stack_b = &tmp_ref;
}

void	ft_pa(t_dlist **stack_a, t_dlist **stack_b)
{
	push(stack_a, stack_b);
	ft_printf("pa ");
}

void	ft_pb(t_dlist **stack_b, t_dlist **stack_a)
{
	push(stack_b, stack_a);
	ft_printf("pb ");
}