/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execute_stacks.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vketteni <vketteni@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 14:33:27 by vketteni          #+#    #+#             */
/*   Updated: 2024/01/24 18:47:09 by vketteni         ###   ########.fr       */
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
	operation_queue[B] = -1;
}

static void	execute_a(t_dlist **stack, int *operation_queue)
{
	if (operation_queue[A] == ROTATE)
		ft_ra(stack);
	if (operation_queue[A] == REVERSE_ROTATE)
		ft_rra(stack);
	if (operation_queue[A] == SWAP)
		ft_sa(stack);
	operation_queue[A] = -1;
}

void	ft_execute_stacks(t_dlist ***stacks, int *operation_queue,
		t_dlist **last, t_dlist **next)
{
	int	distance_next_a;
	int	distance_next_b;

	if (*stacks[A] && *stacks[B])
	{
		distance_next_a = ft_distance(last[A], next[A]);
		distance_next_b = ft_distance(last[B], next[B]);
		if (ft_absolute(ft_distance(last[A],
					next[A])) < ft_absolute(ft_distance(last[B], next[B])))
			execute_a(stacks[A], operation_queue, last, next);
		else if (*stacks[B])
			execute_b(stacks[B], operation_queue, last, next);
	}
	else if (*stacks[A])
		execute_a(stacks[A], operation_queue, last, next);
	else
		execute_b(stacks[B], operation_queue, last, next);
}
