/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_simultaneously.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vketteni <vketteni@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 11:57:25 by vketteni          #+#    #+#             */
/*   Updated: 2024/01/23 03:06:13 by vketteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

static int	next_operation(int distance_head_to_next, int distance_last_to_next)
{
	if (distance_head_to_next > 1)
		return (ROTATE);
	else if (distance_head_to_next < -1 || (distance_head_to_next == 0
			&& distance_last_to_next < -1))
		return (REVERSE_ROTATE);
	else if (distance_head_to_next == 1)
		return (SWAP);
	else
		return (-1);
}

static void	update_last(t_dlist **last)
{
	if (ft_distance_to_closest_adjacent_value(last[A], last[A]->next_highest,
			last[A]->next_lowest) == 1)
		last[A] = last[A]->next_highest;
	if (ft_distance_to_closest_adjacent_value(last[A], last[A]->next_highest,
			last[A]->next_lowest) == -1)
		last[A] = last[A]->next_lowest;
	if (ft_distance_to_closest_adjacent_value(last[B], last[B]->next_highest,
			last[B]->next_lowest) == 1)
		last[B] = last[B]->next_lowest;
	if (ft_distance_to_closest_adjacent_value(last[B], last[B]->next_highest,
			last[B]->next_lowest) == -1)
		last[B] = last[B]->next_highest;
}

void	ft_sort_simultaneously(t_dlist **stack_a, t_dlist **stack_b)
{
	int		operation_queue[2];
	t_dlist	*last[2];

	last[A] = *stack_a;
	last[B] = *stack_b;
	while (!ft_is_sorted(stack_a) && !ft_is_sorted(stack_b))
	{
		operation_queue[A] = next_operation(ft_distance_to_closest_adjacent_value(*stack_a,
					last[A]->next_highest, last[A]->next_lowest),
				ft_distance_to_closest_adjacent_value(last[A],
					last[A]->next_highest, last[A]->next_lowest));
		operation_queue[B] = next_operation(ft_distance_to_closest_adjacent_value(*stack_a,
					last[A]->next_highest, last[A]->next_lowest),
				ft_distance_to_closest_adjacent_value(last[A],
					last[A]->next_highest, last[A]->next_lowest));
		ft_execute_queue(stack_a, stack_b, operation_queue, last);
		update_last(last);
	}
}
