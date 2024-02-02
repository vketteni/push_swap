/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vketteni <vketteni@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 03:09:03 by vketteni          #+#    #+#             */
/*   Updated: 2024/02/02 13:00:37 by vketteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"



void	initialize_stack_size(int argc, char **argv, int *stack_size_a,
		int *stack_size_b)
{
	if (argc == 2)
		stack_size_a[0] = argc - 1;
	stack_size_a[1] = stack_size_a[0];
	*stack_size_b = 0;
}

void	initialize_stacks(int argc, char **argv, long *stack_a, long *stack_b)
{
	int		i;
	char	*argument;

	if ((!stack_a || !stack_b))
		exit(-1);
	check_args(&argc, &argv);
	i = 1;
	while (i < argc)
	{
		argument = argv[i];
		if (is_number(argument) == -1)
		{
			ft_printf("Error\n");
			exit(-1);
		}
		stack_a[i - 1] = ft_atol(argument);
		i++;
	}
}

void	initialize_inputs(int argc, char **argv, int input_list_len,
		char **input_list)
{
	if (argc == 1 && ft_printf("%s\n", argv[0]))
		exit(0);
	else if (argc == 2 && !ft_strchr(argv[1], ' '))
		exit(0);
	else if (argc == 2)
		input_string(argc, argv, input_list_len, input_list);
	else
		regular(argc, argv, input_list_len, input_list);
	check_repetitions(input_list_len, input_list);
	check_out_of_bounds(input_list_len, input_list);
	check_already_sorted(input_list_len, input_list);
}

void	sort(int input_list_len, char **input_list)
{
	int		*stack_size_a;
	int		*stack_size_b;
	long	*stack_a;
	long	*stack_b;

	stack_size_a = (int *)malloc(sizeof(int) * 2);
	stack_size_b = (int *)malloc(sizeof(int));
	initialize_stack_size(input_list_len, input_list, stack_size_a,
		stack_size_b);
	stack_a = (long *)malloc(sizeof(long) * (argc - 1));
	stack_b = (long *)malloc(sizeof(long) * (argc - 1));
	if (!stack_a || !stack_b || !stack_size_a || !stack_size_b)
		return (0);
	initialize_stacks(input_list_len, input_list, stack_a, stack_b);
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

	initialize_inputs(argc, argv, input_list_len, input_list);
	sort(input_list_len, input_list);
	return (0);
}
