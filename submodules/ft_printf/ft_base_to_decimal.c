/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_base_to_decimal.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vketteni <vketteni@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 21:34:06 by vketteni          #+#    #+#             */
/*   Updated: 2024/01/07 00:56:02 by vketteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_base_to_decimal(char *src, char *base)
{
	int	n;
	int	base_length;

	base_length = 0;
	while (*(base + base_length))
		base_length++;
	n = *(src)-base[0];
	while (*(src))
		n = (n * base_length) + *(src++) - base[0];
	return (n);
}
