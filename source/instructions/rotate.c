/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vketteni <vketteni@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 16:53:06 by vketteni          #+#    #+#             */
/*   Updated: 2024/02/02 17:07:15 by vketteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	rotate_a(long *stack_a, int *stack_size_a)
{
	long	first;
	int		i;

	first = stack_a[0];
	i = 0;
	while (i < stack_size_a[1] - 1)
	{
		stack_a[i] = stack_a[i + 1];
		i++;
	}
	stack_a[stack_size_a[1] - 1] = first;
	ft_printf("ra\n");
}

void	rotate_b(long *stack_b, int *stack_size_b)
{
	long	first;
	int		i;

	first = stack_b[0];
	i = 0;
	while (i < *stack_size_b - 1)
	{
		stack_b[i] = stack_b[i + 1];
		i++;
	}
	stack_b[*stack_size_b - 1] = first;
	ft_printf("rb\n");
}
