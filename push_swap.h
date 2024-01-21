/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vketteni <vketteni@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 14:55:06 by vketteni          #+#    #+#             */
/*   Updated: 2024/01/21 19:58:26 by vketteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP
# define PUSH_SWAP

# define SORTING_STEPS 3

# define A 0
# define B 1

# define PUSH 0
# define ROTATE 1
# define REVERSE_ROTATE 2
# define SWAP 3



# include <stdlib.h>

# include "submodules/libft/libft.h"
# include "submodules/ft_printf/ft_printf.h"

void	ft_push(t_dlist **stack_a, t_dlist **stack_b);
t_dlist	**rotate(t_dlist **stack);
void	ft_swap(t_dlist **stack);

//void    ft_print_operations(int argc, char **argv, int sort_alg);

void    ft_init_stack(t_dlist **stack, int argc, char **argv);

#endif