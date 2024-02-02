/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vketteni <vketteni@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 12:59:51 by vketteni          #+#    #+#             */
/*   Updated: 2024/02/02 17:13:31 by vketteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	free_stacks(long *stack_a, long *stack_b, int *stack_size_a,
		int *stack_size_b)
{
	free(stack_a);
	free(stack_b);
	free(stack_size_a);
	free(stack_size_b);
	exit(0);
}
