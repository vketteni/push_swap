/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_format_string.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vketteni <vketteni@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 22:57:44 by vketteni          #+#    #+#             */
/*   Updated: 2024/01/06 23:20:31 by vketteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_print_specified_format(char specifier, va_list *args)
{
	int	count;

	count = 0;
	if (specifier == 'c')
		count += ft_print_char(va_arg(*args, int));
	else if (specifier == 's')
		count += ft_print_str(va_arg(*args, char *));
	else if (specifier == 'p')
		count += ft_print_ptr(va_arg(*args, void *));
	else if (specifier == 'd' || specifier == 'i')
		count += ft_print_dec((long)va_arg(*args, int));
	else if (specifier == 'u')
		count += ft_print_dec((long)va_arg(*args, unsigned int));
	else if (specifier == 'x')
		count += ft_print_hex(va_arg(*args, unsigned int), 0);
	else if (specifier == 'X')
		count += ft_print_hex(va_arg(*args, unsigned int), 1);
	return (count);
}

int	ft_print_format_string(const char *format, va_list *args)
{
	int	print_count;

	print_count = 0;
	while (*format)
	{
		if (*format != '%')
			print_count += ft_print_char(*format);
		else
		{
			format++;
			if (*format == '%')
				print_count += ft_print_char('%');
			else
				print_count += ft_print_specified_format(*format, args);
		}
		format++;
	}
	return (print_count);
}
