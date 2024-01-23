/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vketteni <vketteni@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 14:54:00 by vketteni          #+#    #+#             */
/*   Updated: 2024/01/23 13:38:32 by vketteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	return (0);
}
