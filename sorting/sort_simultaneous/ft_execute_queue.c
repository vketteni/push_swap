/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execute_queue.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vketteni <vketteni@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 14:33:27 by vketteni          #+#    #+#             */
/*   Updated: 2024/01/25 19:45:56 by vketteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

static void	execute_b(t_dlist **stack, int *operation_queue)
{
	if (operation_queue[B] == ROTATE)
		ft_rb(stack);
	if (operation_queue[B] == REVERSE_ROTATE)
		ft_rrb(stack);
	if (operation_queue[B] == SWAP)
		ft_sb(stack);
	operation_queue[B] = WAIT;
}

static void	execute_a(t_dlist **stack, int *operation_queue)
{
	if (operation_queue[A] == ROTATE)
		ft_ra(stack);
	if (operation_queue[A] == REVERSE_ROTATE)
		ft_rra(stack);
	if (operation_queue[A] == SWAP)
		ft_sa(stack);
	operation_queue[A] = WAIT;
}

static void	execute_simultanous(t_dlist ***stacks, int *operations)
{
	if (operations[A] == ROTATE)
		ft_rr(stacks[A], stacks[B]);
	else if (operations[A] == REVERSE_ROTATE)
		ft_rrr(stacks[A], stacks[B]);
	else if (operations[A] == SWAP)
		ft_ss(stacks[A], stacks[B]);
	operations[A] = WAIT;
	operations[B] = WAIT;
}

static void	execute_single(t_dlist ***stacks, int *operation_queue,
		t_dlist **last, t_dlist **next)
{
	if (*stacks[A] && *stacks[B])
	{
		if (ft_absolute(ft_distance_between(last[A],
					next[A])) < ft_absolute(ft_distance_between(last[B], next[B])))
			execute_a(stacks[A], operation_queue);
		else if (*stacks[B])
			execute_b(stacks[B], operation_queue);
	}
	else if (*stacks[A])
		execute_a(stacks[A], operation_queue);
	else
		execute_b(stacks[B], operation_queue);
}

void	ft_execute_queue(int *operation_queue, t_dlist ***stacks,
		t_dlist **last, t_dlist **next)
{
	if (operation_queue[A] == operation_queue[B]
		&& (operation_queue[A] == ROTATE || operation_queue[A] == REVERSE_ROTATE
			|| operation_queue[A] == SWAP))
		execute_simultanous(stacks, operation_queue);
	else
		execute_single(stacks, operation_queue, last, next);
}