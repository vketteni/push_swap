/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vketteni <vketteni@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 16:09:54 by vketteni          #+#    #+#             */
/*   Updated: 2024/01/31 16:44:30 by vketteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	push_a(long *stack_a, long *stack_b, int *stack_size_a,
		int *stack_size_b)
{
    int i;

    stack_size_a[1]++;
    i = 0;
    while (i < stack_size_a - 1)
    {
        stack_a[i + 1] = stack_a[i];
        i++;
    }
    stack_a[0] = stack_b[0];
    (*stack_size_b)--;
    i = 0;
    while (i < stack_size_b)
    {
        stack_b[i] = stack_b[i + 1];
        i++;
    }
    ft_prinf("pa\n");
}

void	push_b(long *stack_a, long *stack_b, int *stack_size_a,
		int *stack_size_b)
{
    int i;

    stack_size_b++;
    i = 0;
    while (i < stack_size_b - 1)
    {
        stack_a[i + 1] = stack_a[i];
        i++;
    }
    stack_b[0] = stack_a[0];
    stack_size_a[1]--;
    i = 0;
    while (i < stack_size_a[1])
    {
        stack_a[i] = stack_a[i + 1];
        i++;
    }
    ft_prinf("pb\n");
}