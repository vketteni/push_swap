/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_decimal_to_base.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vketteni <vketteni@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 21:28:38 by vketteni          #+#    #+#             */
/*   Updated: 2024/01/12 12:02:13 by vketteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_strlen(const char *str)
{
	char	*start;

	start = (char *)str;
	while (*(str))
		str++;
	return (str - start);
}

static int	ft_len_after_base_change(long unsigned decimal, int base)
{
	int	len;

	len = 0;
	while (decimal)
	{
		decimal /= base;
		len++;
	}
	return (len);
}

char	*ft_decimal_to_base(unsigned long decimal, char *base)
{
	unsigned long	quotient;
	unsigned long	remainder;
	int				len;
	char			*new_base;

	quotient = decimal;
	len = ft_len_after_base_change(decimal, ft_strlen(base));
	new_base = (char *)malloc(sizeof(char) * (len + 1));
	if (!new_base)
		return (0);
	new_base[len--] = '\0' ;
	while (quotient && len >= 0)
	{
		remainder = quotient % ft_strlen(base);
		quotient = quotient / ft_strlen(base);
		new_base[len--] = base[remainder];
	}
	return (new_base);
}
