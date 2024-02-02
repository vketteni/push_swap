/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vketteni <vketteni@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 14:16:36 by vketteni          #+#    #+#             */
/*   Updated: 2024/02/02 16:04:25 by vketteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	initialize_stack_size(int input_list_len, int *stack_size_a,
		int *stack_size_b)
{
	stack_size_a[0] = input_list_len;
	stack_size_a[1] = stack_size_a[0];
	*stack_size_b = 0;
}

void	initialize_stacks(int input_list_len, char **input_list, long *stack_a,
		long *stack_b)
{
	int		i;
	char	*argument;

	if ((!stack_a || !stack_b))
		exit(-1);
	i = 0;
	while (i < input_list_len)
	{
		argument = input_list[i];
		if (is_number(argument) == -1)
		{
			ft_printf("Error\n");
			exit(-1);
		}
		stack_a[i - 1] = ft_atol(argument);
		i++;
	}
}

void	initialize_inputs(int argc, char **argv, int *input_list_len,
		char ***input_list)
{
	if (argc == 1 && ft_printf("%s\n", argv[0]))
		exit(0);
	else if (argc == 2 && !ft_strchr(argv[1], ' '))
		exit(0);
	else if (argc == 2)
	{
		*input_list = ft_split(argv[1], ' ');
		while ((*input_list)[*input_list_len] != NULL)
			(*input_list_len)++;
	}
	else
	{
		*input_list = (char **)malloc(sizeof(char *) * (argc - 1));
		if (*input_list == NULL)
			exit(-1);
		while (*input_list_len < argc - 1)
		{
			(*input_list)[*input_list_len] = argv[*input_list_len + 1];
			(*input_list_len)++;
		}
	}
	check_repetitions(*input_list_len, *input_list);
	check_out_of_bounds(*input_list_len, *input_list);
	check_already_sorted(*input_list_len, *input_list);
}
