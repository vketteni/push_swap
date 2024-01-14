/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vketteni <vketteni@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 14:55:06 by vketteni          #+#    #+#             */
/*   Updated: 2024/01/13 22:26:23 by vketteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP
# define PUSH_SWAP

# define INSERTIONSORT      0
# define SELECTIONSORT  1

# include <stdlib.h>
# include <varargs.h>
# include "submodules/libft/libft.h"
# include "submodules/ft_printf/ft_printf.h"

void	ft_push(t_list **stack_a, t_list **stack_b);
t_list	**rotate(t_list **stack);
void	ft_swap(t_list **stack);

void    ft_print_operations(int argc, char **argv, int sort_alg);

void	ft_print_SELECTIONSORT(int argc, char **argv);

#endif