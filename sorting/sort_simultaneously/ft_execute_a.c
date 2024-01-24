/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vketteni <vketteni@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 14:33:27 by vketteni          #+#    #+#             */
/*   Updated: 2024/01/24 18:31:18 by vketteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

static void	execute_b(t_dlist **stack, int *operations)
{
	if (operations[B] == ROTATE)
		ft_rb(stack);
	if (operations[B] == REVERSE_ROTATE)
		ft_rrb(stack);
	if (operations[B] == SWAP)
		ft_sb(stack);
	operations[B] = -1;
	
}

static void	execute_simultanous(t_dlist ***stacks, int *operations)
{
	if (operations[A] == ROTATE)
		ft_rr(stacks[A], stacks[B]);
	else if (operations[A] == REVERSE_ROTATE)
		ft_rrr(stacks[A], stacks[B]);
	else if (operations[A] == SWAP)
		ft_ss(stacks[A], stacks[B]);
	operations[A] = -1;
	operations[B] = -1;
}

static int	is_simultaneous(int operation)
{
	if (operation == ROTATE || operation == REVERSE_ROTATE || operation == SWAP)
		return (1);
	return (0);
}

void	ft_execute_queue(t_dlist ***stacks, int *operation_queue,
		t_dlist **last, t_dlist **next)
{
	int	distance_next_a;
	int	distance_next_b;

	distance_next_a = ft_distance(last[A], next[A]);
	distance_next_b = ft_distance(last[B], next[B]);
	if (operation_queue[A] == operation_queue[B]
		&& is_simultaneous(operation_queue[A]))
		execute_simultanous(stacks, operation_queue);
	else if (ft_absolute(distance_next_a) < ft_absolute(distance_next_b))
		execute_a(stacks[A], operation_queue);
	else
		execute_b(stacks[B], operation_queue);
}
