/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_dec.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vketteni <vketteni@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 20:12:55 by vincentkett       #+#    #+#             */
/*   Updated: 2024/01/07 00:48:04 by vketteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_print_dec_rek(long long n)
{
	char	ascii;

	if (n > 9)
	{
		ft_print_dec_rek(n / 10);
		ascii = (n % 10) + '0';
		write(1, &ascii, 1);
	}
	else
	{
		ascii = n + '0';
		write(1, &ascii, 1);
	}
}

int	ft_print_dec(long dec)
{
	long long	nbr;
	int			count;

	count = 0;
	nbr = (long long)dec;
	if (nbr == 0)
		return (write(1, "0", 1));
	if (nbr < 0)
	{
		count += write(1, "-", 1);
		nbr = -nbr;
	}
	ft_print_dec_rek(nbr);
	while (nbr)
	{
		nbr /= 10;
		count++;
	}
	return (count);
}
