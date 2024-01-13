/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vketteni <vketteni@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 20:10:49 by vincentkett       #+#    #+#             */
/*   Updated: 2024/01/07 00:42:33 by vketteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_str(char *str)
{
	int	count;

	count = 0;
	if (!str)
	{
		str = "(null)";
		while (*str)
			count += ft_print_char(*str++);
	}
	else
	{
		while (*(str))
			count += ft_print_char(*(str++));
	}
	return (count);
}
