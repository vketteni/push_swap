/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_absolute.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vketteni <vketteni@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 03:10:48 by vketteni          #+#    #+#             */
/*   Updated: 2024/01/23 03:13:53 by vketteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

unsigned int    ft_absolute(int d)
{
    long integer;

    integer = (long)d;
    if (integer < 0)
        return (-(integer));
    return (integer);
}