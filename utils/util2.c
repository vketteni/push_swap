/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vketteni <vketteni@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 12:59:51 by vketteni          #+#    #+#             */
/*   Updated: 2024/02/04 18:27:02 by vketteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	free_stacks(long *stack_a, long *stack_b, int *stack_size_a,
		int *stack_size_b)
{
	free(stack_a);
	free(stack_b);
	free(stack_size_a);
	free(stack_size_b);
}

void	free_arr(void **arr)
{
	int	i;

	i = 0;
	if (arr != NULL)
	{
		while (arr[i])
		{
			if (arr[i] != NULL)
				free(arr[i++]);
		}
		free(arr);
	}
}

void	free_arr_exit(void **arr)
{
	free(arr);
	exit(-1);
}

void	free_stacks_exit(long *stack_a, long *stack_b, int *stack_size_a,
		int *stack_size_b)
{
	free_stacks(stack_a, stack_b, stack_size_a, stack_size_b);
	exit(-1);
}

void	check_args(int input_list_len, char **input_list)
{
	check_number(input_list_len, input_list);
	check_repetitions(input_list_len, input_list);
	check_out_of_bounds(input_list_len, input_list);
	check_already_sorted(input_list_len, input_list);
}
