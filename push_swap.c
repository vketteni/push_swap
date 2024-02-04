/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vketteni <vketteni@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 03:09:03 by vketteni          #+#    #+#             */
/*   Updated: 2024/02/04 17:28:00 by vketteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort(int input_list_len, char **input_list)
{
	int		*stack_size_a;
	int		*stack_size_b;
	long	*stack_a;
	long	*stack_b;

	stack_size_a = (int *)malloc(sizeof(int) * 2);
	stack_size_b = (int *)malloc(sizeof(int));
	initialize_stack_size(input_list_len, stack_size_a, stack_size_b);
	stack_a = (long *)malloc(sizeof(long) * (input_list_len));
	stack_b = (long *)malloc(sizeof(long) * (input_list_len));
	if (!stack_a || !stack_b || !stack_size_a || !stack_size_b
		|| !initialize_stacks(input_list_len, input_list, stack_a, stack_b))
		free_stacks_exit(stack_a, stack_b, stack_size_a, stack_size_b);
	if (stack_size_a[1] == 2)
		rotate_a(stack_a, stack_size_a);
	else if (stack_size_a[1] == 3)
		sort_three(stack_a, stack_size_a);
	else if (stack_size_a[1] == 5 || stack_size_a[1] == 4)
		sort_five_or_four(stack_a, stack_b, stack_size_a, stack_size_b);
	else
		sort_gt_five(stack_a, stack_b, stack_size_a, stack_size_b);
	free_stacks(stack_a, stack_b, stack_size_a, stack_size_b);
}

int	main(int argc, char **argv)
{
	int		input_list_len;
	char	**input_list;

	input_list_len = 0;
	input_list = initialize_inputs(argc, argv, &input_list_len);
	sort(input_list_len, input_list);
	free_arr((void **)input_list);
	return (0);
}
