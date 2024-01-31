/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vketteni <vketteni@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 03:09:03 by vketteni          #+#    #+#             */
/*   Updated: 2024/01/31 18:18:45 by vketteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stacks(long *stack_a, long *stack_b, int *stack_size_a, int *stack_size_b)
{
	free(stack_a);
	free(stack_b);
	free(stack_size_a);
	free(stack_size_b);
	exit(0);
}

void	initialize_stack_size(int argc, int *stack_size_a, int *stack_size_b)
{
	stack_size_a = (long *)malloc(sizeof(long) * 2);
	if (stack_size_a == NULL)
	{
		ft_printf("Error\n");
		exit(-1);
	}
	stack_size_b = (long *)malloc(sizeof(long));
	if (stack_size_b == NULL)
	{
		ft_printf("Error\n");
		exit(-1);
	}
	stack_size_a[0] = argc - 1;
	stack_size_a[1] = stack_size_a[0];
	*stack_size_b = 0;
}

void	initialize_stacks(int argc, char **argv, long *stack_a, long *stack_b)
{
	int		i;
	char	*argument;

	stack_a = (long *)malloc(sizeof(long) * (argc - 1));
	stack_b = (long *)malloc(sizeof(long) * (argc - 1));
	if (!stack_a || !stack_b)
		return (-1);
	i = 0;
	while (i < argc)
	{
		argument = argv[i + 1];
		if (is_number(argument) == -1)
		{
			ft_printf("Error\n");
			exit(-1);
		}
		stack_a[i] = ft_atoi(argument);
		i++;
	}
}

void	check_args(int argc, char **argv)
{
	check_repetitions(argc, argv);
	check_out_of_bounds(argc, argv);
}

		
int	main(int argc, char *argv[])
{
	int		*stack_size_a;
	int		*stack_size_b;
	long	*stack_a;
	long	*stack_b;

	check_args(argc, argv);
	stack_size_a = (int *)malloc(sizeof(int) * 2);
	stack_size_b = (int *)malloc(sizeof(int));
	initialize_stack_size(argc, stack_size_a, stack_size_b);
	stack_a = (long *)malloc(sizeof(long) * (argc - 1));
	stack_b = (long *)malloc(sizeof(long) * (argc - 1));
	if (!stack_a || !stack_b || !stack_size_a || !stack_size_b)
		return (0);
	initialize_stacks(argc, argv, stack_a, stack_b);
	if ((stack_size_a[1] == 2) && (stack_a[0] > stack_a[1]))
		rotate_a(stack_a, stack_size_a);
	else if (stack_size_a[1] == 3)
		sort_three(stack_a, stack_b);
	else if (stack_size_a[1] == 5 || stack_size_a[1] == 4)
		sort_five_or_four(stack_a, stack_b, stack_size_a, stack_size_b);
	else
		sort_gt_five(stack_a, stack_b, stack_size_a, stack_size_b);
	free_stacks(stack_a, stack_b, stack_size_a, stack_size_b);
	return (0);
}
	