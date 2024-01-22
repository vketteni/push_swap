/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   highest_lowest.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vketteni <vketteni@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 19:17:22 by vketteni          #+#    #+#             */
/*   Updated: 2024/01/22 19:22:28 by vketteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_dlist *ft_highest_in_stack(t_dlist **stack)
{
    t_dlist *highest;
    t_dlist *tmp;

    highest = *stack;
    tmp = *stack;
    while (tmp != NULL)
    {
        if (tmp->content > highest->content)
            highest = tmp;
    }
    return (highest);
}

t_dlist *ft_lowest_in_stack(t_dlist **stack)
{
    t_dlist *lowest;
    t_dlist *tmp;

    lowest = *stack;
    tmp = *stack;
    while (tmp != NULL)
    {
        if (tmp->content < lowest->content)
            lowest = tmp;
    }
    return (lowest);
}