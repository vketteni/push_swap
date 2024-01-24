/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vketteni <vketteni@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 14:55:06 by vketteni          #+#    #+#             */
/*   Updated: 2024/01/24 18:46:04 by vketteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP
# define PUSH_SWAP

# define SORTING_STEPS 3

# define DISTANCES_MERGE 6
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
void			ft_pa(t_dlist **stack_a, t_dlist **stack_b);
void			ft_pb(t_dlist **stack_b, t_dlist **stack_a);
void			ft_rb(t_dlist **stack_b);
void			ft_ra(t_dlist **stack_a);
void			ft_rr(t_dlist **stack_a, t_dlist **stack_b);
void			ft_rra(t_dlist **stack_a);
void			ft_rrb(t_dlist **stack_b);
void			ft_rrr(t_dlist **stack_a, t_dlist **stack_b);
void			ft_sa(t_dlist **stack_a);
void			ft_sb(t_dlist **stack_b);
void			ft_ss(t_dlist **stack_a, t_dlist **stack_b);

/*
 *	SORTING
 */
void			ft_initialize_stack(t_dlist **stack, int argc, char **argv);
void			ft_divide_upto_median(t_dlist **stack_a, t_dlist **stack_b);
void			ft_merge(t_dlist **stack_a, t_dlist **stack_b);
void			ft_sort_and_print(t_dlist **stack_a);
void			ft_sort_simultaneous(t_dlist **stack_a, t_dlist **stack_b);
void			ft_execute_simultanous(t_dlist ***stacks, int *operations);
void			ft_execute_stacks(t_dlist ***stacks, int *operation_queue,
					t_dlist **last, t_dlist **next);
t_dlist			*ft_get_median(t_dlist **stack);
t_dlist			*ft_get_next(t_dlist **stack, t_dlist *last);

/*
 *	MERGES
 */
void			ft_execute_rrr_merge(t_dlist **stack_a, t_dlist **stack_b,
					int *distances);
void			ft_execute_rr_merge(t_dlist **stack_a, t_dlist **stack_b,
					int *distances);
void			ft_execute_rra_rb_merge(t_dlist **stack_a, t_dlist **stack_b,
					int *distances);
void			ft_execute_ra_rrb_merge(t_dlist **stack_a, t_dlist **stack_b,
					int *distances);

/*
 *   UTILS
 */
int				ft_distance_to_closest_lt_median(t_dlist *start,
					t_dlist *median);
int				ft_distance_to_closest_adjacent_value(t_dlist *start,
					t_dlist *next_highest, t_dlist *next_lowest);
int				ft_distance(t_dlist *start, t_dlist *end);
int				ft_distance_by_rotation(t_dlist *start, t_dlist *end);
int				ft_distance_by_reverse_rotation(t_dlist *start, t_dlist *end);
t_dlist			*ft_highest_in_stack(t_dlist **stack);
t_dlist			*ft_lowest_in_stack(t_dlist **stack);
t_dlist			*ft_next_higher(t_dlist **stack, t_dlist *last);
t_dlist			*ft_next_lower(t_dlist **stack, t_dlist *last);
int				ft_is_sorted_asc(t_dlist **stack);
int				ft_is_sorted_dsc(t_dlist **stack);
unsigned int	ft_absolute(int d);

#endif