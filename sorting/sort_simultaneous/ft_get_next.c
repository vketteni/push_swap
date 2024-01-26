/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vketteni <vketteni@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 19:05:44 by vketteni          #+#    #+#             */
/*   Updated: 2024/01/26 20:42:19 by vketteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

static t_dlist	*assign_path_and_return(int path, int path_length[A_B],
		t_dlist *next, int stack_id)
{
	path_length[stack_id] = path;
	return (next);
}

static t_dlist	*decide_next(int path_length[A_B],
		t_dlist *possible_next[HEAD_TAIL], int possible_path[HEAD_TAIL],
		int stack_id)
{
	if (!possible_next[HEAD] && !possible_next[TAIL])
		return (NULL);
	else if (!possible_next[HEAD] && possible_next[TAIL])
		return (assign_path_and_return(possible_path[TAIL], path_length,
				possible_next[TAIL], stack_id));
	else if (possible_next[HEAD] && !possible_next[TAIL])
		return (assign_path_and_return(possible_path[HEAD], path_length,
				possible_next[HEAD], stack_id));
	else if (possible_path[HEAD] < possible_path[TAIL])
		return (assign_path_and_return(possible_path[HEAD], path_length,
				possible_next[HEAD], stack_id));
	else
		return (assign_path_and_return(possible_path[TAIL], path_length,
				possible_next[TAIL], stack_id));
}

static int	ft_path_length(t_dlist **stack, t_dlist *last, t_dlist *next)
{
	int	distance_head_next;
	int	distance_last_next;

	if (!next)
		return (0);
	distance_head_next = ft_distance_between(*stack, next);
	distance_last_next = ft_distance_between(last, next);
	if ((*stack == last) && distance_head_next <= 2)
		return (distance_head_next);
	else
		return (distance_head_next + distance_last_next);
}

t_dlist	*ft_get_next(t_dlist **stack, t_dlist *sorted_sublist[A_B][HEAD_TAIL],
		int path_length[A_B], int stack_id)
{
	t_dlist	*possible_next[HEAD_TAIL];
	int		possible_path[HEAD_TAIL];

	if (!(*stack))
		return (NULL);
	if (stack_id == A)
		possible_next[HEAD] = ft_next_lower(stack, sorted_sublist[A][HEAD]);
	else
		possible_next[HEAD] = ft_next_higher(stack, sorted_sublist[B][HEAD]);
	if (stack_id == A)
		possible_next[TAIL] = ft_next_higher(stack, sorted_sublist[A][TAIL]);
	else
		possible_next[TAIL] = ft_next_lower(stack, sorted_sublist[B][TAIL]);
	possible_path[HEAD] = ft_path_length(stack, sorted_sublist[stack_id][HEAD],
			possible_next[HEAD]);
	possible_path[TAIL] = ft_path_length(stack, sorted_sublist[stack_id][TAIL],
			possible_next[TAIL]);
	return (decide_next(path_length, possible_next, possible_path, stack_id));
}
