/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vketteni <vketteni@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 21:27:14 by vketteni          #+#    #+#             */
/*   Updated: 2024/01/13 13:15:29 by vketteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(t_list **stack)
{
	t_list	*second;

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
