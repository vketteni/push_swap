/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execute_rra_rb_merge.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vketteni <vketteni@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 00:17:11 by vketteni          #+#    #+#             */
/*   Updated: 2024/01/26 00:10:50 by vketteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	ft_execute_rra_rb_merge(t_dlist **stack_a, t_dlist **stack_b, int *distances)
{
	while (distances[REVERSE_ROTATE_A]--)
		ft_rra(stack_a);
	while (distances[ROTATE_B]--)
		ft_rb(stack_b);
	while(*stack_b)
		ft_pa(stack_b, stack_a);
}