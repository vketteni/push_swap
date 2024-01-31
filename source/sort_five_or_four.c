/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five_or_four.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vketteni <vketteni@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 12:38:37 by vketteni          #+#    #+#             */
/*   Updated: 2024/01/31 12:46:54 by vketteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void    pa_ra(long *stack_a, long *stack_b)
{
    push_a(stack_a, stack_b);
    rotate_a(stack_a);
}

static void    one_into_three(long *stack_a, long *stack_b, int *stack_size_a, int *stack_size_b)
{
    if (stack_b[0] < stack_a[0])
        push_a(stack_a, stack_b);
    else if (stack_b[0] > stack_a[0] && stack_b[0] < stack_a[1])
    {
        rotate_a(stack_a);
        push_a(stack_a, stack_b);
        reverse_rotate_a(stack_a);
    }
    else if (stack_b[0] > stack_a[1] && stack_b[0] < stack_a[2])
    {
        reverse_rotate_a(stack_a);
        push_a(stack_a, stack_b);
        reverse_rotate_a(stack_a);
        reverse_rotate_a(stack_a);
    }
    else if (stack_b[0] > stack_a[2])
        pa_ra(stack_a, stack_b);
}

static void    one_into_four(long *stack_a, long *stack_b, int *stack_size_a, int *stack_size_b)
{
    if (stack_b[0] < stack_a[0])
        push_a(stack_a, stack_b);
    else if (stack_b[0] > stack_a[0] && stack_b[0] < stack_a[1])
    {
        rotate_a(stack_a);
        push_a(stack_a, stack_b);
        reverse_rotate_a(stack_a);
    }
    else if (stack_b[0] > stack_a[1] && stack_b[0] < stack_a[2])
    {
        reverse_rotate_a(stack_a);
        push_a(stack_a, stack_b);
        swap_a(stack_a);
        reverse_rotate_a(stack_a);
    }
    else if (stack_b[0] > stack_b[2] && stack_b[0] < stack_a[3])
    {
        reverse_rotate_a(stack_a);
        push_a(stack_a, stack_b);
        reverse_rotate_a(stack_a);
        reverse_rotate_a(stack_a);   
    }
    else if (stack_b[0] > stack_a[2])
        pa_ra(stack_a, stack_b);
}

void    sort_five_or_four(long *stack_a, long *stack_b, int *stack_size_a, int *stack_size_b)
{
    push_b(stack_a, stack_b);
    if (stack_size_a == 4)
        push_b(stack_a, stack_b);
    sort_three_and_under(stack_a, stack_b, stack_size_a, stack_size_b);
    while (stack_size_b != 0)
    {
        if (stack_size_a == 3)
            one_into_three(stack_a, stack_b, stack_size_a, stack_size_b);
        else
            one_into_four(stack_a, stack_b, stack_size_a, stack_size_b);
    }
}
