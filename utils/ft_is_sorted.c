/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sorted.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vketteni <vketteni@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 02:48:10 by vketteni          #+#    #+#             */
/*   Updated: 2024/01/23 02:57:44 by vketteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int ft_is_sorted(t_dlist **stack)
{
    while (*stack != 0)
    {
        if ((*stack)->next != (*stack)->next_lowest)
            return(0);
        stack = &((*stack)->next);
    }
    return (1);
}