/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vketteni <vketteni@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 14:59:48 by vketteni          #+#    #+#             */
/*   Updated: 2024/01/20 17:30:55 by vketteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void delete(int *content)
{
    if (content)
            free(content);
}

static void	ft_populate_from_input(t_dlist **stack, int argc, char** argv)
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

static void	ft_initialize_upper_lower_bounds(t_dlist **stack)
{
	t_dlist	*current_position;
	t_dlist	*lower_bound;
	t_dlist	*other;

	current_position = *stack;
	while (current_position != NULL)
	{
		other = *stack; 
		while (other != NULL)
		{
			if (other->content < current_position->content)
				lower_bound = other;
			other = other->next;
		}
		if (lower_bound)
		{
			current_position->lower_bound = lower_bound->content;
			lower_bound->upper_bound = current_position->content;
		}
		current_position = current_position->next;
	}
}


void    ft_init_stack(t_dlist **stack, int argc, char **argv)
{
    ft_populate_from_input(stack, argc, argv);
	ft_initialize_upper_lower_bounds(stack);
}