/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vketteni <vketteni@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 14:55:06 by vketteni          #+#    #+#             */
/*   Updated: 2024/01/22 21:34:13 by vketteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP
# define PUSH_SWAP

# define SORTING_STEPS 3

# define DISTANCES_MERGE 8
# define ROTATE_A 0
# define ROTATE_B 1
# define REVERSE_ROTATE_A 2
# define REVERSE_ROTATE_B 3
# define RR 4
# define RRR 5

# define RA_RRB_MERGE 0
# define RRA_RB_MERGE 1
# define RR_MERGE 2
# define RRR_MERGE 3

# define A 0
# define B 1

# define PUSH 0
# define ROTATE 1
# define REVERSE_ROTATE 2
# define SWAP 3

# include "submodules/ft_printf/ft_printf.h"
# include "submodules/libft/libft.h"
# include <stdlib.h>

/*
 *	INSTRUCTIONS
 */
char	*ft_pa(t_dlist **stack_a, t_dlist **stack_b);
char	*ft_pb(t_dlist **stack_b, t_dlist **stack_a);
char	*ft_rb(t_dlist **stack_b);
char	*ft_ra(t_dlist **stack_a);
char	*ft_rr(t_dlist **stack_a, t_dlist **stack_b);
char	*ft_rra(t_dlist **stack_a);
char	*ft_rrb(t_dlist **stack_b);
char	*ft_rrr(t_dlist **stack_a, t_dlist **stack_b);
char	*ft_sa(t_dlist **stack_a);
char	*ft_sb(t_dlist **stack_b);
char	*ft_ss(t_dlist **stack_a, t_dlist **stack_b);

/*
*	SORTING
*/
void	ft_initialize_stack(t_dlist **stack, int argc, char **argv);
void	ft_divide_upto_median(t_dlist **stack_a, t_dlist **stack_b);
void	ft_merge(t_dlist **stack_a, t_dlist **stack_b);
void	ft_sort_and_print(t_dlist **stack_a);
void	ft_sort_simultaneously(t_dlist **stack_a, t_dlist **stack_b);
void	ft_execute_queue(t_dlist **stack_a, t_dlist **stack_b,
		int *operation_queue, t_dlist **last);
/*
*   UTILS
*/

int	ft_distance_to_closest_adjacent_value(t_dlist *start, t_dlist *next_highest,
		t_dlist *next_lowest);
int ft_distance_shortest(t_dlist *start, t_dlist *end);
int ft_distance_by_rotation(t_dlist *start, t_dlist *end);
int ft_distance_by_reverse_rotation(t_dlist *start, t_dlist *end);
t_dlist *ft_highest_in_stack(t_dlist **stack);
t_dlist *ft_lowest_in_stack(t_dlist **stack);

#endif