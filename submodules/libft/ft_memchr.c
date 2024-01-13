/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vketteni <vketteni@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 14:04:17 by vketteni          #+#    #+#             */
/*   Updated: 2023/12/01 13:34:15 by vketteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

void	*ft_memchr(void *src, char chr, size_t n)
{
	const unsigned char	*s;
	unsigned char		c;

	s = src;
	c = (unsigned char)chr;
	while (n > 0)
	{
		if (*s == c)
			return ((void *)s);
		s++;
		n--;
	}
	return (0);
}
