/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execute_rr_merge.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vketteni <vketteni@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 00:20:04 by vketteni          #+#    #+#             */
/*   Updated: 2024/01/23 00:29:47 by vketteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void    ft_execute_rr_merge(t_dlist **stack_a, t_dlist **stack_b, int *distances)
{
    if (distances[RR] == distances[ROTATE_A])
    {
        while (distances[RR]-- && distances[ROTATE_B]--)
            ft_rr(stack_a, stack_b);
        while (distances[ROTATE_B]--)
            ft_rb(stack_b);
    }
    else
    {
        while (distances[RR]-- && distances[ROTATE_A]--)
            ft_rr(stack_a, stack_b);
        while (distances[ROTATE_A]--)
            ft_ra(stack_a);
    }
}