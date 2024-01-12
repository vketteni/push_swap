/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vketteni <vketteni@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 22:10:10 by vketteni          #+#    #+#             */
/*   Updated: 2024/01/12 23:58:34 by vketteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static t_list	**ft_push(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp_ref;

	tmp_ref = *stack_a;
	stack_a = (*stack_a)->next;
	tmp_ref->next = *stack_b;
	stack_b = &tmp_ref;
	return (stack_b);
}

t_list	**ft_pa(t_list **stack_a, t_list **stack_b)
{
	return (ft_push(stack_b, stack_a));
}

t_list	**ft_pb(t_list **stack_b, t_list **stack_a)
{
	return (ft_push(stack_a, stack_b));
}
