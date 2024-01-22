/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initialize_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vketteni <vketteni@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 14:59:48 by vketteni          #+#    #+#             */
/*   Updated: 2024/01/20 20:43:03 by vketteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void delete(void *content)
{
    if (content)
            free(content);
}

static void	ft_populate_stack_with_input(t_dlist **stack, int argc, char** argv)
{
    int     i;
    t_dlist *new;
    int     *content;

    i = 1;
    while (i < argc)
    {
        content = (int *)malloc(sizeof(int));
        if (content == NULL)
            return (ft_dlstclear(stack, delete));
        *content = ft_atoi(argv[i]);
        new = ft_dlstnew(content);
        if (new == NULL)
            return (ft_dlstclear(stack, delete));
        ft_dlstadd_front(stack, new);
    }
}

static void	ft_initialize_upper_lower_relations(t_dlist **stack)
{
	t_dlist	*current_position;
	t_dlist	*next_lowest;
	t_dlist	*other;

	current_position = *stack;
	while (current_position != NULL)
	{
		other = *stack; 
		while (other != NULL)
		{
			if (other->content < current_position->content)
				next_lowest = other;
			other = other->next;
		}
		if (next_lowest)
		{
			current_position->next_lowest = next_lowest;
			next_lowest->next_highest = current_position;
		}
		current_position = current_position->next;
	}
}

static void	ft_initialize_median(t_dlist **stack, int stack_length)
{
	t_dlist *median;
	int		half;

	half = stack_length / 2;
	median = *stack;
	while (median != NULL)
		median = median->next_lowest;
	while (half--)
		median = median->next_highest; 
	median->median = median;
}
	
void    ft_initialize_stack(t_dlist **stack, int argc, char **argv)
{
    ft_populate_stack_with_input(stack, argc, argv);
	ft_initialize_upper_lower_relations(stack);
	ft_initialize_median(stack, (argc - 1));
}