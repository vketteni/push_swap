/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vketteni <vketteni@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 14:55:06 by vketteni          #+#    #+#             */
/*   Updated: 2024/02/02 15:36:07 by vketteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP
# define PUSH_SWAP

# include "submodules/ft_printf/ft_printf.h"
# include "submodules/libft/libft.h"
# include <limits.h>
# include <stdlib.h>

/*
 *	SOURCE
 */
void	swap_a(long *stack_a);
void	swap_b(long *stack_b);
void	reverse_rotate_b(long *stack_b, int *stack_size_b);
void	reverse_rotate_a(long *stack_a, int *stack_size_a);
void	rotate_b(long *stack_b, int *stack_size_b);
void	rotate_a(long *stack_a, int *stack_size_a);
void	push_b(long *stack_a, long *stack_b, int *stack_size_a,
			int *stack_size_b);
void	push_a(long *stack_a, long *stack_b, int *stack_size_a,
			int *stack_size_b);

void	sort_five_or_four(long *stack_a, long *stack_b, int *stack_size_a,
			int *stack_size_b);
void	sort_three(long *stack_a, int *stack_size_a);
void	sort_gt_five(long *stack_a, long *stack_b, int *stack_size_a,
			int *stack_size_b);
void	initialize_stack_size(int input_list_len, int *stack_size_a,
		int *stack_size_b);
void	initialize_stacks(int input_list_len, char **input_list, long *stack_a,
			long *stack_b);
void	initialize_inputs(int argc, char **argv, int *input_list_len,
			char ***input_list);

/*
 *	UTILS
 */
void	free_stacks(long *stack_a, long *stack_b, int *stack_size_a,
			int *stack_size_b);
int		is_number(char *str);
void	check_out_of_bounds(int input_list_len, char **input_list);
int		check_repetitions(int input_list_len, char **input_list);
void	check_already_sorted(int input_list_len, char **input_list);
long	ft_atol(const char *nptr);

#endif