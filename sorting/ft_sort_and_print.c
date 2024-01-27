/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_and_print.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vketteni <vketteni@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 11:43:30 by vketteni          #+#    #+#             */
/*   Updated: 2024/01/22 11:43:42 by vketteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_sort_and_print(t_dlist **stack_a)
{
	t_dlist	*null_ptr;
	t_dlist	**stack_b;

	null_ptr = NULL;
	stack_b = &null_ptr;
	ft_divide_upto_median(stack_a, stack_b);
	ft_sort_simultaneous(stack_a, stack_b);
	ft_merge(stack_a, stack_b);
	
}