/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vketteni <vketteni@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 14:33:03 by vketteni          #+#    #+#             */
/*   Updated: 2024/02/02 15:22:48 by vketteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	check_out_of_bounds(int input_list_len, char **input_list)
{
	int		i;
	long	num;

	i = 0;
	while (i < input_list_len)
	{
		num = ft_atol(input_list[i]);
		if (num > INT_MAX || num < INT_MIN)
		{
			ft_printf("Error\n");
			exit(-1);
		}
		i++;
	}
}

int	is_number(char *str)
{
	while (*str)
	{
		if (ft_isdigit(*str) == 0)
		{
			ft_printf("Error\n");
			exit(-1);
		}
		str++;
	}
	return (0);
}

int	check_repetitions(int input_list_len, char **input_list)
{
	int	i;
	int	j;

	i = 0;
	while (i < input_list_len)
	{
		j = i + 1;
		while (j < input_list_len)
		{
			if (ft_atol(input_list[i]) == ft_atol(input_list[j]))
			{
				ft_printf("Error\n");
				exit(-1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

void	check_already_sorted(int input_list_len, char **input_list)
{
	int	prev;
	int	next;
	int	i;

	i = 1;
	while (i < input_list_len)
	{
		prev = ft_atol(input_list[i - 1]);
		next = ft_atol(input_list[i]);
		if (prev > next)
			return ;
		i++;
	}
	ft_printf("Already sorted.\n");
	exit(0);
}

long	ft_atol(const char *nptr)
{
	int		is_negative;
	long	result;

	while (*nptr == ' ' || (*nptr >= 9 && *nptr <= 13))
		nptr++;
	if (ft_strncmp((char *)nptr, "-9223372036854775808",
			ft_strlen("9223372036854775808")) == 0)
		return (LONG_MIN);
	is_negative = 0;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			is_negative = 1;
		nptr++;
	}
	result = 0;
	while (ft_isdigit(*nptr))
	{
		result *= 10;
		result += (*(nptr++) - '0');
	}
	return (result * (1 + (is_negative * -2)));
}
