/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vketteni <vketteni@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 16:53:19 by vketteni          #+#    #+#             */
/*   Updated: 2024/01/24 17:53:44 by vketteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

t_dlist	*ft_get_next(t_dlist **stack, t_dlist *last)
{
	int		distance_to_lower;
	int		distance_to_higher;
	t_dlist	*next_lower;
	t_dlist	*next_higher;

	if (!(*stack))
		return (0);
	next_higher = ft_next_higher(stack, last);
	next_lower = ft_next_lower(stack, last);
	distance_to_higher = ft_distance(*stack, next_higher);
	distance_to_lower = ft_distance(*stack, next_lower);
	if (distance_to_lower < distance_to_higher)
		return (next_lower);
	else
		return (next_higher);
}
