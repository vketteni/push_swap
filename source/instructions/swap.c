/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vketteni <vketteni@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 17:08:55 by vketteni          #+#    #+#             */
/*   Updated: 2024/01/31 17:13:21 by vketteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

static void    swap(long *stack)
{
    long    tmp;

    tmp = stack[0];
    stack[0] = stack[1];
    stack[1] = tmp;
}

void    swap_a(long *stack_a)
{
    swap(stack_a);
    ft_printf("sa\n");
}

void    swap_b(long *stack_b)
{
    swap(stack_b);
    ft_printf("sb\n");    
}