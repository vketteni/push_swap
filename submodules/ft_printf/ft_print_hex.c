/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vketteni <vketteni@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 20:13:52 by vincentkett       #+#    #+#             */
/*   Updated: 2024/01/12 11:40:58 by vketteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	ft_tolower(char c)
{
	if (c >= 'A' && c <= 'Z')
		return (c + ('a' - 'A'));
	return (c);
}

int	ft_print_hex(unsigned long hex, int uppercase)
{
	int		count;
	int		i;
	char	*hexadecimal;

	if (hex == 0)
		return (ft_print_char('0'));
	hexadecimal = ft_decimal_to_base(hex, "0123456789ABCDEF");
	count = 0;
	if (uppercase)
		count += ft_print_str(hexadecimal);
	else
	{
		i = 0;
		while (hexadecimal[i])
			count += ft_print_char(ft_tolower(hexadecimal[i++]));
	}
	free(hexadecimal);
	return (count);
}
