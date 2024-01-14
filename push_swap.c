/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vketteni <vketteni@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 14:54:00 by vketteni          #+#    #+#             */
/*   Updated: 2024/01/14 20:37:12 by vketteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// int main(void)
int main(int argc, char** argv)
{
	t_list	**stack_a;
	t_list	**stack_b;

	if (argc < 2)
		return (0);
	ft_init_stack(stack_a, argc, argv);
    ft_print_operations(stack_a, stack_b, argc - 1);

    return (0);
}

void    ft_print_operations(t_list **stack_a, t_list **stack_b, int unordered)
{
    char	**sort_operations;
	int		*bottom;
    int		*top;

    while (unordered > 0)
    {
		if (1)
			sort_operations = ft_selection_sort(stack_a, stack_b, bottom, top);
		if (sort_operations == NULL)
			return ((void)ft_printf("Error \n"));
		ft_printf(sort_operations);
		unordered--;
    }
}

static void	ft_init_top_and_bottom(t_list **stack, int *top, int *bottom)
{
	*top = (*stack)->content;
	*bottom = (*stack)->content;
}

char *ft_select_and_swap(t_list **stack_a, int distance)
{
	char *sort_operations;
	while 

	return ();
}

/* 	

*/
char	*ft_selection_sort(t_list **stack_a, t_list **stack_b, int *bottom, int *top)
{
	int	distance_new_bottom;
	int	distance_new_top;

	if (*top == NULL && *bottom == NULL)
		ft_init_top_and_bottom(stack_a, top, bottom);
	ft_init_top_and_bot_distance(distance_new_bottom, distance_new_top, bottom, top);
	if (distance_new_bottom <= distance_new_top)
		return (ft_select_and_swap(stack_a, distance_new_bottom));
	else
		return (ft_select_and_swap(stack_a, distance_new_top));
}
