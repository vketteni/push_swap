/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_divide_upto_median.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vketteni <vketteni@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 11:58:42 by vketteni          #+#    #+#             */
/*   Updated: 2024/01/23 16:54:22 by vketteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

static int	contains_lt_median(t_dlist **stack, t_dlist	*median)
{
	while (*stack != NULL)
	{
		if (*(int *)((*stack)->content) < *(int *)(median->content))
			return (1);
		stack = &((*stack)->next);
	}
	return (0);
}

void	ft_divide_upto_median(t_dlist **stack_a, t_dlist **stack_b)
{
	int		distance;
	t_dlist	*median;

	median = ft_get_median(stack_a);
	if (median == NULL)
	{
		ft_printf("Error\nNo Median\n");
		return ;
	}
	while (contains_lt_median(stack_a, median))
	{
		distance = ft_distance_to_closest_lt_median(*stack_a, median);
		if (distance > 0)
			ft_ra(stack_a);
		else if (distance < 0)
			ft_rra(stack_a);
		else
			ft_pb(stack_a, stack_b);
	}
}
