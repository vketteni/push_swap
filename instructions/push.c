/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vketteni <vketteni@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 22:10:10 by vketteni          #+#    #+#             */
/*   Updated: 2024/01/25 22:39:23 by vketteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	push(t_dlist **stack_a, t_dlist **stack_b)
{
	t_dlist	*first_a;
	t_dlist	*second_a;
	t_dlist	*first_b;

	if (stack_b == NULL || stack_a == NULL)
		return ;
	if (*stack_a == NULL)
		return ;
	first_a = *stack_a;
	first_b = *stack_b;
	second_a = first_a->next;
	first_a->next = first_b;\
	if (first_b)
		first_b->prev = first_a;
	if (second_a)
		second_a->prev = NULL;
	*stack_a = second_a;
	*stack_b = first_a;
}

void	ft_pa(t_dlist **stack_b, t_dlist **stack_a)
{
	push(stack_b, stack_a);
	ft_printf("pa ");
}

void	ft_pb(t_dlist **stack_a, t_dlist **stack_b)
{
	push(stack_a, stack_b);
	ft_printf("pb ");
}