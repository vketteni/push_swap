/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execute_rrr_merge.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vketteni <vketteni@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 00:30:05 by vketteni          #+#    #+#             */
/*   Updated: 2024/01/29 11:52:29 by vketteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void    ft_execute_rrr_merge(t_dlist **stack_a, t_dlist **stack_b, int *distances)
{
    if (distances[RRR] == distances[ROTATE_A])
    {
        while (distances[RRR]-- && distances[ROTATE_B]--)
            ft_rrr(stack_a, stack_b);
        while (distances[ROTATE_B]--)
            ft_rrb(stack_b);
        while(*stack_b)
            ft_pa(stack_b, stack_a);
    }
    else
    {
        while (distances[RRR]-- && distances[ROTATE_A]--)
            ft_rrr(stack_a, stack_b);
        while (distances[ROTATE_A]--)
            ft_rra(stack_a);
        while(*stack_b)
            ft_pa(stack_b, stack_a);
    }
}