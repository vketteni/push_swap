/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vketteni <vketteni@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 14:54:00 by vketteni          #+#    #+#             */
/*   Updated: 2024/01/16 00:29:09 by vketteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// int main(void)
int main(int argc, char** argv)
{
	t_dlist	**stack_a;
	t_dlist	**stack_b;

	if (argc < 2)
		return (0);
	ft_init_stack(stack_a, argc, argv);
    ft_print_operations(stack_a, stack_b, argc - 1);

    return (0);
}

void    ft_print_operations(t_dlist **stack_a, t_dlist **stack_b, int unordered)
{
    char	**sort_operations;
    int		*sorted_top;
	int		*sorted_bottom;

	sorted_top = *stack_a;
	sorted_bottom = *stack_a;
    while (unordered > 0)
    {
		if (1)
			sort_operations = ft_selection_sort(stack_a, stack_b, sorted_bottom, sorted_top);
		if (sort_operations == NULL)
			return ((void)ft_printf("Error \n"));
		ft_printf(sort_operations);
		unordered--;
    }
}

t_dlist	*ft_select_upwards(t_dlist **stack, t_dlist *last, int distance)
{
	t_dlist	*next_sorted;

	next_sorted = last;
	while (distance)
	{
		if (next_sorted->next == NULL)
			next_sorted = *stack;
		else
			next_sorted = next_sorted->next;
		distance--;
	}
	return (next_sorted);
}

t_dlist	*ft_select_backwards(t_dlist **stack, t_dlist *last, int distance)
{
	t_dlist	*next_sorted;

	next_sorted = last;
	while (distance)
	{
		if (next_sorted->prev == NULL)
			next_sorted = ft_dlstlast(*stack);
		else
			next_sorted = next_sorted->prev;
		distance--;
	}
	return (next_sorted);
}

void	ft_swap_next(t_dlist *unsorted_elem, t_dlist *next_sorted)
{
	t_dlist *adjacent_elem;
	t_dlist *tmp;

		tmp = unsorted_elem;
		if (unsorted_elem == NULL)
		next_sorted->next = unsorted_elem->next;	 
		adjacent_elem = next_sorted->next;
		if (adjacent_elem != NULL)
			adjacent_elem->prev = next_sorted->prev;
		
		adjacent_elem = last->prev;
		next_sorted->prev = adjacent_elem;
		if (adjacent_elem != NULL)
			adjacent_elem->next = next_sorted;
		last->prev = next_sorted;
}


char *ft_select_and_swap(t_dlist **stack_a, t_dlist *last, int distance)
{
	char 	*sort_operations;
	t_dlist	*next_sorted;

	if (distance < 0)
		next_sorted = ft_select_backwards(stack_a, last, -distance);
	else
		next_sorted = ft_select_upwards(stack_a, last, distance);
	if (last->content > next_sorted->content)
		ft_swap_next(last->prev, next_sorted);
	else
		ft_swap_next_top(last, next_sorted);	
	return (ft_selection_sort_operations(distance));
}

char	*ft_selection_sort(t_dlist **stack_a, t_dlist **stack_b, t_dlist *sorted_top, t_dlist *sorted_bottom)
{
	int	distance_new_bottom;
	int	distance_new_top;

	ft_init_next_distance(distance_new_bottom, distance_new_top, sorted_bottom, sorted_top);
	if (distance_new_top <= distance_new_bottom)
		return (ft_select_and_swap(stack_a, sorted_top, distance_new_top));
	else
		return (ft_select_and_swap(stack_a, sorted_bottom, distance_new_bottom));
}
