/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execute_queue.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vketteni <vketteni@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 14:33:27 by vketteni          #+#    #+#             */
/*   Updated: 2024/01/27 03:31:02 by vketteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	execute_b(t_dlist **stack, int *operation_queue)
{
	if (operation_queue[B] == ROTATE)
		ft_rb(stack);
	if (operation_queue[B] == REVERSE_ROTATE)
		ft_rrb(stack);
	if (operation_queue[B] == SWAP)
		ft_sb(stack);
	operation_queue[B] = WAIT;
}

void	execute_a(t_dlist **stack, int *operation_queue)
{
	if (operation_queue[A] == ROTATE)
		ft_ra(stack);
	if (operation_queue[A] == REVERSE_ROTATE)
		ft_rra(stack);
	if (operation_queue[A] == SWAP)
		ft_sa(stack);
	operation_queue[A] = WAIT;
}

void	execute_simultanous(t_dlist **stack_a, t_dlist **stack_b,
		int *operations)
{
	if (operations[A] == ROTATE)
		ft_rr(stack_a, stack_b);
	else if (operations[A] == REVERSE_ROTATE)
		ft_rrr(stack_a, stack_b);
	else if (operations[A] == SWAP)
		ft_ss(stack_a, stack_b);
	operations[A] = WAIT;
	operations[B] = WAIT;
}

void	ft_execute_queue(t_dlist **stack_a, t_dlist **stack_b,
		int *operation_queue, int *path_length)
{
	if (operation_queue[A] == operation_queue[B]
		&& (operation_queue[A] == ROTATE || operation_queue[A] == REVERSE_ROTATE
			|| operation_queue[A] == SWAP))
		execute_simultanous(stack_a, stack_b, operation_queue);
	else if ((operation_queue[B] == WAIT && operation_queue[A] != WAIT)
		|| ft_absolute(path_length[A]) < ft_absolute(path_length[B]))
		execute_a(stack_a, operation_queue);
	else if (operation_queue[B] != WAIT)
		execute_b(stack_b, operation_queue);
}
