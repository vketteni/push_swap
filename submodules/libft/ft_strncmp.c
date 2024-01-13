/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vketteni <vketteni@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 13:49:56 by vketteni          #+#    #+#             */
/*   Updated: 2023/12/01 13:41:30 by vketteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

int	ft_strncmp(char *s1, char *s2, size_t n)
{
	while ((*s1 || *s2) && n > 0)
	{
		if ((unsigned const char)*s1 != (unsigned const char)*s2)
			return ((unsigned const char)*s1 - (unsigned const char)*s2);
		s1++;
		s2++;
		n--;
	}
	return (0);
}

/*
# include <stdio.h>
# include <unistd.h>
int	main(void)
{
	printf("%d\n", ft_strncmp("test\200", "test\0", 6));
	return (0);
}
*/
