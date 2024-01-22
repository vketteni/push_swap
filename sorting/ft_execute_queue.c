/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execute_queue.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vketteni <vketteni@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 14:33:27 by vketteni          #+#    #+#             */
/*   Updated: 2024/01/22 19:24:31 by vketteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	execute_single_operations(t_dlist **stack, int operation,
		int stack_id)
{
	if (operation == ROTATE && stack_id == A)
		ft_ra(stack);
	if (operation == ROTATE && stack_id == B)
		ft_rb(stack);
	if (operation == REVERSE_ROTATE && stack_id == A)
		ft_rra(stack);
	if (operation == REVERSE_ROTATE && stack_id == B)
		ft_rrb(stack);
	if (operation == SWAP && stack_id == A)
		ft_sa(stack);
	if (operation == SWAP && stack_id == B)
		ft_sb(stack);
}

static void	execute_simultanous_operations(t_dlist **stack_a, t_dlist **stack_b,
		int *operation_queue)
{
	if ((operation_queue[A] == operation_queue[B])
		&& operation_queue[A] == ROTATE)
		ft_rr(stack_a, stack_b);
	else if ((operation_queue[A] == operation_queue[B])
		&& operation_queue[A] == REVERSE_ROTATE)
		ft_rrr(stack_a, stack_b);
	else if ((operation_queue[A] == operation_queue[B])
		&& operation_queue[A] == SWAP)
		ft_ss(stack_a, stack_b);
}

void	ft_execute_queue(t_dlist **stack_a, t_dlist **stack_b,
		int *operation_queue, t_dlist **last)
{
	int	distance_a;
	int	distance_b;

	distance_a = ft_distance_to_closest_adjacent_value(last, last[A]->next_highest,
			last[A]->next_lowest);
	distance_b = ft_distance_to_closest_adjacent_value(last, last[A]->next_highest,
			last[A]->next_lowest);
	execute_simultanous_operations(stack_a, stack_b, operation_queue);
	if (ft_absolute(distance_a) < ft_absolute(distance_b)) 
		execute_single_operations(stack_a, operation_queue[A], A);
	else 
		execute_single_operations(stack_a, operation_queue[B], B);
}
