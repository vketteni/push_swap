/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execute_simultaneous.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vketteni <vketteni@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 14:33:27 by vketteni          #+#    #+#             */
/*   Updated: 2024/01/24 18:46:09 by vketteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	ft_execute_simultanous(t_dlist ***stacks, int *operations)
{
	if (operations[A] == ROTATE)
		ft_rr(stacks[A], stacks[B]);
	else if (operations[A] == REVERSE_ROTATE)
		ft_rrr(stacks[A], stacks[B]);
	else if (operations[A] == SWAP)
		ft_ss(stacks[A], stacks[B]);
	operations[A] = -1;
	operations[B] = -1;
}

