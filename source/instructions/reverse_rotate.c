/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vketteni <vketteni@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 17:06:16 by vketteni          #+#    #+#             */
/*   Updated: 2024/02/01 14:50:56 by vketteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void    reverse_rotate_a(long *stack_a, int *stack_size_a)
{
    long    last;
    int     i;

    last = stack_a[stack_size_a[1] - 1];
    i = stack_size_a[1] - 1;
    while (i > 0)
    {
        stack_a[i] = stack_a[i - 1];
        i--;
    }
    stack_a[0] = last;
    ft_printf("rra\n");
}

void    reverse_rotate_b(long *stack_b, int *stack_size_b)
{
    long    last;
    int     i;

    last = stack_b[*stack_size_b - 1];
    i = *stack_size_b - 1;
    while (i < *stack_size_b)
    {
        stack_b[i] = stack_b[i - 1];
        i++;
    }
    stack_b[0] = last;
    ft_printf("rra\n");
}