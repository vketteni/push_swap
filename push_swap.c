/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vketteni <vketteni@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 14:54:00 by vketteni          #+#    #+#             */
/*   Updated: 2024/01/21 20:24:03 by vketteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_dlist	**stack;

	if (argc < 2)
		return (0);
	ft_init_stack(stack, argc, argv);
	ft_print_operations(stack);
	return (0);
}

static int	ft_error(void)
{
	ft_printf("Error!\n");
	return (NULL);
}

void	ft_print_operations(t_dlist **stack_a)
{
	t_dlist	**stack_b;

	ft_divide_upto_median(stack_a, stack_b);
	ft_sort_simultaneously(stack_a, stack_b);
	ft_merge(stack_a, stack_b);
}

void	ft_merge(t_dlist **stack_a, t_dlist **stack_b)
{
	ft_rotate_until_median(stack_a, stack_b);
	while (*stack_b)
		ft_pa(stack_a, stack_b);
}

void	ft_sort_simultaneously(t_dlist **stack_a, t_dlist **stack_b)
{
	int		operation_queue[2];
	int		direction_to_next[2];
	t_dlist	*last[2];

	last[A] = *stack_a;
	last[B] = *stack_b;
	while (!ft_is_sorted(stack_a) && !ft_is_sorted(stack_b))
	{
		operation_queue[A] = ft_next_operation(last[A], ft_distance_to_next(last, A));
		operation_queue[B] = ft_next_operation(last[B], ft_distance_to_next(last, B));
		ft_execute_queue(stack_a, stack_b, operation_queue, last);
	}
}

void	ft_execute_queue(t_dlist **stack_a, t_dlist **stack_b,
		int *operation_queue, t_dlist **last)
{
	if ((operation_queue[A] == operation_queue[B]) && operation_queue[A] == ROTATE)
		ft_rr(stack_a, stack_b);
	if ((operation_queue[A] == operation_queue[B]) && operation_queue[A] == REVERSE_ROTATE)
		ft_rrr(stack_a);
	if ((operation_queue[A] == operation_queue[B]) && operation_queue[A] == SWAP)
		ft_ss(stack_a, stack_b);
	if (ft_absolute(ft_distance_to_next(last, A)) < ft_absolute(ft_distance_to_next(last, B)))
		ft_execute(stack_a, operation_queue[A], A);
	else
		ft_execute(stack_a, operation_queue[B], B);
	ft_update_last(last);
}

void	ft_execute(t_dlist **stack, int operation, int stack_id)
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

int	ft_next_operation(t_dlist *last, int distance_to_next)
{
	if (distance_to_next > 1)
		return (ROTATE);
	else if (distance_to_next < -1 || (distance_to_next == 0
			&& ft_distance(ft_dlstfirst(last[A]), last[A]) < -1))
		return (REVERSE_ROTATE);
	else if (distance_to_next == 1)
		return (SWAP);
}

void	ft_divide_upto_median(t_dlist **stack_a, t_dlist **stack_b)
{
	int		direction;
	t_dlist	*median;

	median = ft_get_median(stack_a);
	while (ft_contains_le_median(stack_a))
	{
		direction = ft_find_closest_le_median(median, stack_a);
		if (direction > 0)
			ft_ra(stack_a);
		else if (direction < 0)
			ft_rra(stack_a);
		else
			ft_pa(stack_a, stack_b);
	}
}
