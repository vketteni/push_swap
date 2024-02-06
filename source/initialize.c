/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vketteni <vketteni@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 14:16:36 by vketteni          #+#    #+#             */
/*   Updated: 2024/02/06 16:33:01 by vketteni         ###   ########.fr       */
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

int	initialize_stacks(int input_list_len, char **input_list, long *stack_a,
		long *stack_b)
{
	int	i;

	if ((!stack_a || !stack_b))
		return (0);
	i = 0;
	while (i < input_list_len)
	{
		stack_a[i] = ft_atol(input_list[i]);
		i++;
	}
	return (1);
}

static char	**one_string_inputs(char **argv, int *input_list_len)
{
	char	**input_list;

	input_list = ft_split(argv[1], ' ');
	if (!input_list)
		exit(-1);
	while (input_list[*input_list_len] != NULL)
		(*input_list_len)++;
	return (input_list);
}

static char	**many_inputs(int argc, char **argv, int *input_list_len)
{
	char	**input_list;

	input_list = (char **)ft_calloc(sizeof(char *), argc);
	if (input_list == NULL)
		exit(-1);
	while (*input_list_len < argc - 1)
	{
		input_list[*input_list_len] = ft_strdup(argv[*input_list_len + 1]);
		if (!input_list[*input_list_len])
			free_arr_exit((void **)input_list);
		(*input_list_len)++;
	}
	return (input_list);
}

char	**initialize_inputs(int argc, char **argv, int *input_list_len)
{
	char	**input_list;

	if (argc <= 1)
		exit(-1);
	else if (argc == 2 && !ft_strchr(argv[1], ' ') && is_number(argv[1]))
		exit(0);
	else if (argc == 2)
		input_list = one_string_inputs(argv, input_list_len);
	else
		input_list = many_inputs(argc, argv, input_list_len);
	check_args(*input_list_len, input_list);
	return (input_list);
}
