/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_gt_five.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vketteni <vketteni@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 12:47:57 by vketteni          #+#    #+#             */
/*   Updated: 2024/01/31 17:33:33 by vketteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
void	initialize_copies(long *stack_a, int *stack_size_a, long *copy1, long *copy2)
{
	int	i;

	i = 0;
	while (i < stack_size_a[0])
	{
		copy1[i] = stack_a[i];
		copy2[i] = stack_a[i];
		i++;
	}
}

void	simple_sort(long *stack, int *stack_size_a)
{
	int		i;
	int		j;
	long	tmp;

	i = 0;
	while (i < stack_size_a[0])
	{
		j = i + 1;
		while (j < stack_size_a[0])
		{
			if (stack[j] < stack[i])
			{
				tmp = stack[i];
				stack[i] = stack[j];
				stack[j] = tmp;
			}
			j++;
		}
		i++;
	}
}

void	transform_values_based_on_relative_order(long *stack_a, long *original_copy, long *sorted_copy, int *stack_size_a)
{
	int	i;
	int	j;

	i = 0;
	while (i < stack_size_a[0])
	{
		j = 0;
		while (j < stack_size_a[0])
		{
			if (sorted_copy[j] == original_copy[i])
				stack_a[i] = j;
			j++;
		}
		i++;
	}
}

void	radix_sort(long *stack_a, long *stack_b, int *stack_size_a, int *stack_size_b)
{
	int	max_bits;
	int	max_number;
	int	index[2];

	max_number = stack_size_a[0] - 1;
	max_bits = 0;
	index[0] = 0;
	index[1] = 0;
	while (max_number >> max_bits != 0)
		max_bits++;
	while (index[0] < max_bits)
	{
		while (index[1] < stack_size_a[0])
		{
			if ((stack_a[0] >> index[0] & 1))
				rotate_a(stack_a, stack_size_a);
			else
				push_b(stack_a, stack_b, stack_size_a, stack_size_b);
			index[1]++;
		}
		while (*stack_size_b != 0)
			push_a(stack_a, stack_b, stack_size_a, stack_size_b);
		index[0]++;
	}
}

void	sort_gt_five(long *stack_a, long *stack_b, int *stack_size_a,
		int *stack_size_b)
{
	long *original_copy;
	long *sorted_copy;

	original_copy = (long *)malloc(sizeof(long) * stack_size_a[0]);
	sorted_copy = (long *)malloc(sizeof(long) * stack_size_a[0]);
	initialize_copies(stack_a, stack_size_a, original_copy, sorted_copy);
	simple_sort(sorted_copy, stack_size_a);
	transform_values_based_on_relative_order(stack_a, stack_size_a, original_copy, sorted_copy);
	free(original_copy);
	free(sorted_copy);
	radix_sort(stack_a, stack_b, stack_size_a, stack_size_b);
}