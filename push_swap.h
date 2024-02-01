/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vketteni <vketteni@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 14:55:06 by vketteni          #+#    #+#             */
/*   Updated: 2024/02/01 15:33:49 by vketteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP
# define PUSH_SWAP

# include "submodules/ft_printf/ft_printf.h"
# include "submodules/libft/libft.h"
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

/*
 *	UTILS
 */
void	free_stacks(long *stack_a, long *stack_b, int *stack_size_a,
			int *stack_size_b);
int		is_number(char *str);
int		check_repetitions(int argc, char **argv);
int		check_out_of_bounds(int argc, char **argv);
void	check_already_sorted(int argc, char **argv);

#endif