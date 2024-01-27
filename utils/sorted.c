/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorted.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vketteni <vketteni@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 02:48:10 by vketteni          #+#    #+#             */
/*   Updated: 2024/01/27 02:44:15 by vketteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_is_sorted_asc(t_dlist **stack)
{
	t_dlist	*first;
	t_dlist	*highest;
	t_dlist	*lowest;

	highest = ft_highest_in_stack(stack);
	lowest = ft_lowest_in_stack(stack);
	first = *stack;
	while (*stack != NULL)
	{
		if (*stack == highest && (*stack)->next != lowest
			&& (*stack)->next != NULL)
			return (0);
		else if ((*stack)->next == NULL && ft_next_higher(stack,
				*stack) == first)
			break ;
		else if ((*stack) != highest && (*stack)->next != NULL
			&& (*stack)->next != ft_next_higher(stack, *stack))
			return (0);
		stack = &((*stack)->next);
	}
	return (1);
}

int	ft_is_sorted_dsc(t_dlist **stack)
{
	t_dlist *first;
	t_dlist *highest;
	t_dlist *lowest;

	first = *stack;
	highest = ft_highest_in_stack(stack);
	lowest = ft_lowest_in_stack(stack);
	while (*stack != NULL)
	{
		if (*stack == lowest && (*stack)->next != highest
			&& (*stack)->next != NULL)
			return (0);
		else if ((*stack)->next == NULL && ft_next_lower(stack,
				*stack) == first)
			break ;
		else if ((*stack) != lowest && (*stack)->next != NULL
			&& (*stack)->next != ft_next_lower(stack, *stack))
			return (0);
		stack = &((*stack)->next);
	}
	return (1);
}