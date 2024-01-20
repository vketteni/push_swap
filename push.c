/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vketteni <vketteni@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 22:10:10 by vketteni          #+#    #+#             */
/*   Updated: 2024/01/20 13:26:47 by vketteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push(t_dlist **stack_a, t_dlist **stack_b)
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
