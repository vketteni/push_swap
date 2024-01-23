/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_median.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vketteni <vketteni@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 01:27:40 by vketteni          #+#    #+#             */
/*   Updated: 2024/01/23 01:47:13 by vketteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

t_dlist	*ft_get_median(t_dlist **stack)
{
	while ((*stack)->median == NULL && *stack != NULL)
		stack = &((*stack)->next);
	return (*stack);
}