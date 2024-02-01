/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vketteni <vketteni@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 12:47:01 by vketteni          #+#    #+#             */
/*   Updated: 2024/02/01 18:05:13 by vketteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_three(long *stack_a, int *stack_size_a)
{
	if (stack_a[0] > stack_a[1] && stack_a[0] < stack_a[2])
		swap_a(stack_a);
	else if ((stack_a[0] < stack_a[1] && stack_a[0] > stack_a[2])
		|| (stack_a[0] < stack_a[1] && stack_a[0] < stack_a[2]))
	{
		reverse_rotate_a(stack_a, stack_size_a);
		swap_a(stack_a);
	}
	else if ((stack_a[1] < stack_a[0] && stack_a[1] > stack_a[2])
		|| (stack_a[1] < stack_a[0] && stack_a[1] < stack_a[2]))
	{
		rotate_a(stack_a, stack_size_a);
		swap_a(stack_a);
	}
	else if (stack_a[2] < stack_a[0] && stack_a[2] > stack_a[1])
		rotate_a(stack_a, stack_size_a);
	else
		return ;
}
