/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_a.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vketteni <vketteni@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 15:42:01 by vketteni          #+#    #+#             */
/*   Updated: 2024/01/25 20:01:14 by vketteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

static t_dlist *decide_higher_lower(t_dlist *last, t_dlist *higher, t_dlist *lower)
{
	int		distance_head_next_lower;
	int		distance_head_next_higher;

	if (higher)
		distance_head_next_higher = ft_distance_between(last, higher);
	if (lower)
		distance_head_next_lower = ft_distance_between(last, lower);
    if (higher && lower && (distance_head_next_higher != 1) && (distance_head_next_lower != -1))
    {
		if (distance_head_next_lower < distance_head_next_higher)
			return (lower);
		else
			return (higher);
    }
    else if (higher && (distance_head_next_higher != 1))
        return (higher);
    else if (lower && (distance_head_next_lower != -1))
        return (lower);
    else
        return (NULL);
}

t_dlist	*ft_get_next_a(t_dlist **stack, t_dlist *last)
{
	t_dlist	*lower;
	t_dlist	*higher;

	if (!(*stack))
		return (0);
	higher = ft_next_higher(stack, last);
	lower = ft_next_lower(stack, last);
    return (decide_higher_lower(last, higher, lower));
}