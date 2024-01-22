/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vketteni <vketteni@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 21:27:14 by vketteni          #+#    #+#             */
/*   Updated: 2024/01/22 14:34:49 by vketteni         ###   ########.fr       */
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

char	*ft_sa(t_dlist **stack_a)
{
	swap(stack_a);
	return ("sa");
}

char	*ft_sb(t_dlist **stack_b)
{
	swap(stack_b);
	return ("sb");
}

char	*ft_ss(t_dlist **stack_a, t_dlist **stack_b)
{
	swap(stack_a);
	swap(stack_b);
	return ("ss");
}