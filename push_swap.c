/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vketteni <vketteni@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 14:54:00 by vketteni          #+#    #+#             */
/*   Updated: 2024/01/27 10:54:42 by vketteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void delete(void *content)
{
    if (content)
            free(content);
}

int	main(int argc, char **argv)
{
	t_dlist	*null_ptr;
	t_dlist	**stack_a;

	null_ptr = NULL;
	stack_a = &null_ptr;
	if (argc < 2)
		return (0);
	ft_initialize_stack(stack_a, argc, argv);
	ft_sort_and_print(stack_a);
	ft_dlstclear(stack_a, delete);
	return (0);
}
