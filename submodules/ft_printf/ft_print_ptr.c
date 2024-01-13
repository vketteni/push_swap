/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vketteni <vketteni@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 20:11:12 by vincentkett       #+#    #+#             */
/*   Updated: 2024/01/07 00:37:04 by vketteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_ptr(void *p)
{
	long unsigned	ptr;

	ptr = (long unsigned)p;
	if (!p)
		return (ft_print_str("0x0"));
	else
		return (ft_print_str("0x") + ft_print_hex(ptr, 0));
}
