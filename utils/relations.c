/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   relations.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vketteni <vketteni@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 19:17:22 by vketteni          #+#    #+#             */
/*   Updated: 2024/01/26 15:23:54 by vketteni         ###   ########.fr       */
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
		tmp = tmp->next;
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

t_dlist *ft_next_higher(t_dlist **stack, t_dlist *last)
{
    t_dlist *higher;

    higher = NULL;
    while (*stack != NULL)
    {
        if ((*(int *)(*stack)->content) > (*(int *)(last)->content)) 
        {
            if (!higher)
                higher = *stack;
            else if ((*(int *)(*stack)->content) < (*(int *)((higher))->content))
                higher = *stack;
        }
        stack = &((*stack)->next);
    }
    return (higher);
}

t_dlist *ft_next_lower(t_dlist **stack, t_dlist *last)
{
    t_dlist *lower;

    if (!stack || !last)
        return (NULL);
    lower = NULL;
    while (*stack != NULL)
    {
        if ((*(int *)(*stack)->content) < (*(int *)(last)->content)) 
        {
            if (!lower)
                lower = *stack;
            else if ((*(int *)(*stack)->content) > (*(int *)((lower))->content))
                lower = *stack;
        }
        stack = &((*stack)->next);
    }
    return (lower);
}

int ft_is_greater_than(t_dlist *next, t_dlist *last)
{
    if (*(int *)(next->content) > *(int *)(last->content))
        return (1);
    return (0);
}