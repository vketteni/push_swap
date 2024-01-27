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
        new = ft_dlstnew((int *)content);
        if (new == NULL)
            return (ft_dlstclear(stack, delete));
        ft_dlstadd_back(stack, new);
		i++;
    }
}

static void	ft_initialize_upper_lower_relations(t_dlist **stack)
{
	t_dlist	*current_position;
	t_dlist	*next_lowest;
	t_dlist	*other;

	next_lowest = NULL;
	current_position = *stack;
	while (current_position != NULL)
	{
		other = *stack; 
		next_lowest = NULL; 
		while (other != NULL)
		{
			if (other != current_position && *(int*)(other->content) < *(int *)(current_position->content) && (next_lowest == NULL || *(int *)(other->content) > *(int *)(next_lowest->content)))
					next_lowest = other;
			other = other->next;
		}
		if (next_lowest != NULL)
		{
			current_position->next_lowest = next_lowest;
			next_lowest->next_highest = current_position;
		}
		current_position = current_position->next;
	}
}

static void	ft_initialize_median(t_dlist **stack, int stack_length)
{
	int		half;

	half = stack_length / 2;
	while (*stack != NULL && (*stack)->next_lowest != NULL)
		stack = &((*stack)->next_lowest);
	while (half-- && (*stack)->next_highest != NULL)
		stack = &((*stack)->next_highest); 
	(*stack)->median = (*stack);
}
	
void    ft_initialize_stack(t_dlist **stack, int argc, char **argv)
{
    ft_populate_stack_with_input(stack, argc, argv);
	ft_initialize_upper_lower_relations(stack);
	ft_initialize_median(stack, (argc - 1));
}