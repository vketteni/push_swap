/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execute_ra_rrb_merge.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vketteni <vketteni@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 00:11:18 by vketteni          #+#    #+#             */
/*   Updated: 2024/01/26 00:10:22 by vketteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	ft_execute_ra_rrb_merge(t_dlist **stack_a, t_dlist **stack_b, int *distances)
{
	while (distances[ROTATE_A]--)
		ft_ra(stack_a);
	while (distances[REVERSE_ROTATE_B]--)
		ft_rrb(stack_b);
	while(*stack_b)
		ft_pa(stack_b, stack_a);
}