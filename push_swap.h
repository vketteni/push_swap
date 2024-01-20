/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vketteni <vketteni@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 14:55:06 by vketteni          #+#    #+#             */
/*   Updated: 2024/01/20 18:09:02 by vketteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP
# define PUSH_SWAP

# define UPPER_BOUND_UPUP 0
# define UPPER_BOUND_UPDOWN 1
# define UPPER_BOUND_DOWNDOWN 2
# define UPPER_BOUND_DOWNUP 3
# define LOWER_BOUND_UPUP 4
# define LOWER_BOUND_UPDOWN 5
# define LOWER_BOUND_DOWNDOWN 6
# define LOWER_BOUND_DOWNUP 7

# define CYCLE_PATH_PERMUTATIONS 8


# include <stdlib.h>

# include "submodules/libft/libft.h"
# include "submodules/ft_printf/ft_printf.h"

void	ft_push(t_dlist **stack_a, t_dlist **stack_b);
t_dlist	**rotate(t_dlist **stack);
void	ft_swap(t_dlist **stack);

//void    ft_print_operations(int argc, char **argv, int sort_alg);

void    ft_init_stack(t_dlist **stack, int argc, char **argv);

#endif