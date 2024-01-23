/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   relations.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vketteni <vketteni@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 19:17:22 by vketteni          #+#    #+#             */
/*   Updated: 2024/01/23 18:31:27 by vketteni         ###   ########.fr       */
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
        if (*(int *)(tmp->content) > *(int *)(highest->content))
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
        if (*(int *)(tmp->content) < *(int *)(lowest->content))
            lowest = tmp;
        tmp = tmp->next;
    }
    return (lowest);
}

t_dlist *ft_get_next_higher_in_stack(t_dlist **stack, t_dlist *compare)
{
    t_dlist *higher;

    while (*stack != NULL)
    {
        if ((*(int *)(*stack)->content) > (*(int *)(compare)->content)) 
        {
            if (!higher)
                higher = *stack;
            else if ((*(int *)(*stack)->content) < (*(int *)((higher))->content))
                higher = *stack;
        }
    }
    return (higher);
}

t_dlist *ft_get_next_lower_in_stack(t_dlist **stack, t_dlist *compare)
{
    t_dlist *lower;

    while (*stack != NULL)
    {
        if ((*(int *)(*stack)->content) < (*(int *)(compare)->content)) 
        {
            if (!lower)
                lower = *stack;
            else if ((*(int *)(*stack)->content) > (*(int *)((lower))->content))
                lower = *stack;
        }
    }
    return (lower);
}