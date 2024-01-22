/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_merge.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vketteni <vketteni@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 11:55:24 by vketteni          #+#    #+#             */
/*   Updated: 2024/01/22 21:43:53 by vketteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

static char	*next_operation(t_dlist **stack_a, t_dlist **stack_b)
{
}

static void	initialize_distances(t_dlist **stack_a, t_dlist **stack_b,
		int *distances)
{
	distances[ROTATE_A] = ft_distance_by_rotation(*stack_a,
			ft_lowest_in_stack(*stack_a));
	distances[ROTATE_B] = ft_distance_by_rotation(*stack_b,
			ft_highest_in_stack(*stack_b));
	distances[REVERSE_ROTATE_A] = ft_distance_by_reverse_rotation(*stack_a,
			ft_lowest_in_stack(*stack_a));
	distances[REVERSE_ROTATE_B] = ft_distance_by_reverse_rotation(*stack_b,
			ft_highest_in_stack(*stack_b));
	if (distances[ROTATE_A] - distances[ROTATE_B] > 0)
		distances[RR] = distances[ROTATE_B];
	else
		distances[RR] = distances[ROTATE_A];
	if (distances[REVERSE_ROTATE_A] - distances[REVERSE_ROTATE_B] > 0)
		distances[RRR] = distances[REVERSE_ROTATE_B];
	else
		distances[RRR] = distances[REVERSE_ROTATE_A];
}

static int	calculate_merge_strategy(int *distances)
{
	int shortest_merge;
	int	other;

	shortest_merge = distances[ROTATE_A] + distances[REVERSE_ROTATE_B];
	other = distances[REVERSE_ROTATE_A] + distances[ROTATE_B];
	if (other < shortest_merge)
		shortest_merge = other;
	other = distances[RR] + (distances[ROTATE_A] + distances[ROTATE_B] - (2 * distances[RR]));
	if (other < shortest_merge)
		shortest_merge = other;
	other = distances[RRR] + (distances[REVERSE_ROTATE_A] + distances[REVERSE_ROTATE_B] - (2 * distances[RRR]));
	if (other < shortest_merge)
		shortest_merge = other;
	if (shortest_merge == distances[ROTATE_A] + distances[REVERSE_ROTATE_B])
		return (RA_RRB_MERGE);
	else if (shortest_merge == distances[REVERSE_ROTATE_A] + distances[ROTATE_B])
		return (RRA_RB_MERGE);
	else if (shortest_merge == distances[RR] + (distances[ROTATE_A] + distances[ROTATE_B] - (2 * distances[RR])))
		return (RR_MERGE);
	else if (shortest_merge == distances[RR] + (distances[ROTATE_A] + distances[ROTATE_B] - (2 * distances[RR])))
		return (RRR_MERGE);
}

void	execute_merge(t_dlist **stack_a, t_dlist **stack_b ,int merge_strategy, int *distances)
{
	if (merge_strategy == RA_RRB_MERGE)
	{
		while (distances[ROTATE_A]--)
			ft_ra(stack_a);
		while (distances[REVERSE_ROTATE_B]--)
			ft_rrb(stack_b);
	}
	else if (merge_strategy == RRA_RB_MERGE)
	{
		while (distances[REVERSE_ROTATE_A]--)
			ft_rra(stack_a);
		while (distances[ROTATE_B]--)
			ft_rb(stack_b);
	}
	else if (merge_strategy == RR_MERGE)
	{
		while (distances[RR]--)
			ft_rr(stack_a, stack_b);
		while (distances[ROTATE_A])
	}
}

void	ft_merge(t_dlist **stack_a, t_dlist **stack_b)
{
	int	distances[DISTANCES_MERGE];
	int merge_strategy;
	initialize_distances(stack_a, stack_b, distances);
	merge_strategy = calculate_merge_strategy(distances);
	execute_merge(stack_a, stack_b, merge_strategy, distances);

	if (distances[ROTATE_A] + distances[REVERSE_ROTATE_B] > distances[RR]
		+ (distances[ROTATE_A] + distances[ROTATE_B] - (2 * distances[RR]))
		|| distances[REVERSE_ROTATE_A] + distances[ROTATE_B] > distances[RR]
		+ (distances[ROTATE_A] + distances[ROTATE_B] - (2 * distances[RR])))
	{
		execute_rr(distances[RR]);
		execute_ra(distances[ROTATE_A] - distances[RR]);
		execute_rb(distances[ROTATE_B] - distances[RR]);
	}
	else
	while (*stack_a !=)
		while (*stack_b)
			ft_pa(stack_a, stack_b);
}
