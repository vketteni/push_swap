/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vketteni <vketteni@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 14:54:00 by vketteni          #+#    #+#             */
/*   Updated: 2024/01/17 11:10:02 by vketteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// int main(void)
int	main(int argc, char **argv)
{
	t_dlist	**stack_a;
	t_dlist	**stack_b;

	if (argc < 2)
		return (0);
	ft_init_stack(stack_a, argc, argv);
	ft_print_operations(stack_a, stack_b, argc - 1);
	return (0);
}

void	ft_print_operations(t_dlist **stack_a, t_dlist **stack_b, int unordered)
{
	char	**sort_operations;
	int		*last_lowest;
	int		*last_highest;

	last_lowest = *stack_a;
	last_highest = *stack_a;
	while (unordered > 0)
	{
		if (1)
			sort_operations = ft_selection_sort(stack_a, stack_b, last_highest,
					last_lowest);
		if (sort_operations == NULL)
			return ((void)ft_printf("Error \n"));
		ft_printf(sort_operations);
		unordered--;
	}
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

ft_selection_sort_operations()