/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vketteni <vketteni@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 14:54:00 by vketteni          #+#    #+#             */
/*   Updated: 2024/01/20 20:48:02 by vketteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_dlist	**stack;

	if (argc < 2)
		return (0);
	ft_init_stack(stack, argc, argv);
	ft_print_operations(stack);
	return (0);
}

static int	ft_error()
{
	ft_printf("Error!\n");
	return (NULL);
}

void	ft_print_operations(t_dlist **stack)
{
	char	*sort_operations;

	sort_operations = ft_sort(stack);
	if (sort_operations == NULL || ft_check_ordered(stack) == 0)
		return (ft_error());
	ft_printf(sort_operations);
}

char	*ft_sort(t_dlist **stack)
{
	t_dlist	**second_stack;

	
	// return ();
}

char	**ft_get_paths(t_dlist **stack)
{
	char 	**available_paths;
	t_dlist	*sorted_upper_bound;
	t_dlist	*sorted_lower_bound;

	available_paths = (char **)malloc(sizeof(char *) * CYCLE_PATH_PERMUTATIONS);
	if (available_paths == NULL)
		return (NULL);
	sorted_upper_bound = ft_sorted_upper_bound(stack);
	sorted_lower_bound = ft_sorted_lower_bound(stack);
	available_paths[UPPER_BOUND_UPUP] = ft_get_upup_path(stack, sorted_upper_bound);
	available_paths[UPPER_BOUND_UPDOWN] = 0;
	available_paths[UPPER_BOUND_DOWNDOWN] = 0;
	available_paths[UPPER_BOUND_DOWNUP] = 0;
	available_paths[LOWER_BOUND_UPUP] = 0;
	available_paths[LOWER_BOUND_DOWNUP] = 0;
	available_paths[LOWER_BOUND_DOWNDOWN] = 0;
	available_paths[LOWER_BOUND_UPDOWN] = 0;
	return (available_paths);
}

ft_get_upup_path(t_dlist **stack, t_dlist *sorted_upper_bound)
{
	
}

void	ft_swap_next_lowest(t_dlist *last, t_dlist *next_lowest)
{
	t_dlist	*before_lowest;
	t_dlist	*after_lowest;

	before_lowest = next_lowest->prev;
	before_lowest->next = next_lowest->next;
	after_lowest = next_lowest->next;
	after_lowest->prev = next_lowest->prev;
	last->prev = next_lowest;
	next_lowest->next = last;
	next_lowest->prev = NULL;
}

void	ft_swap_next_highest(t_dlist *last, t_dlist *next_highest)
{
	t_dlist	*tmp1;
	t_dlist	*tmp2;

	if (last->next == NULL)
		return ;
	tmp1 = last->next;
	tmp2 = next_highest;
	next_highest->next = tmp1->next;
	next_highest->prev = tmp1->prev;
	(last->next)->next = tmp2->next;
	(last->next)->prev = tmp2->prev;
}

char	*ft_selection_sort(t_dlist **stack_a, t_dlist **stack_b,
		t_dlist *last_highest, t_dlist *last_lowest)
{
	int		distance;
	t_dlist	*next;

	distance = ft_next_distance(last_lowest, last_highest, next);
	if (next == 0 || distance == 0)
		return (0);
	if (next->content < last_lowest->content)
	{
		ft_swap_next_lowest(last_lowest, next);
		return (ft_swap_lowest_operations(distance));
	}
	else
		ft_swap_next_highest(last_highest, next);
		return (ft_swap_highest_operations(distance));

}

int	ft_init_next_and_return_distance(t_dlist *dst, t_dlist *src, int distance)
{
	dst = src;
	return (distance);
}

int	ft_next_distance(t_dlist *last_lowest, t_dlist *last_highest, t_dlist *next)
{
	t_dlist	*tail;
	t_dlist	*head;
	int		distance;

	head = last_highest->next;
	tail = ft_dlstlast(last_highest);
	distance = 1;
	while (head != tail)
	{
		if (tail->content < last_lowest || tail->content > last_highest)
			return (ft_init_next_and_return_distance(next, tail, -distance));
		if (head->content < last_lowest || head->content > last_highest)
			return (ft_init_next_and_return_distance(next, head, distance));
		distance++;
		tail = tail->prev;
		head = head->prev;
	}
	return (0);
}

// ft_selection_sort_operations()