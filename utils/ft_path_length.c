/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_path_length.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vketteni <vketteni@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 16:29:29 by vketteni          #+#    #+#             */
/*   Updated: 2024/01/28 19:20:47 by vketteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_path_length(t_dlist **stack, t_dlist *last, t_dlist *next)
{
	int	distance_head_next;
	int	distance_last_next;

	if (!next)
		return (0);
	distance_head_next = ft_distance_between(*stack, next);
	distance_last_next = ft_distance_between(last, next);
	if ((*stack == last) && distance_head_next <= 2)
		return (distance_head_next + distance_last_next - 1);
	else
		return (distance_head_next + distance_last_next - 2);
}
