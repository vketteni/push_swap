/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vketteni <vketteni@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 14:33:03 by vketteni          #+#    #+#             */
/*   Updated: 2024/02/02 11:28:29 by vketteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	check_out_of_bounds(int argc, char **argv)
{
	int		i;
	long	num;

	if (argc == 2)
	{
		argv = ft_split(argv[1], ' ');
		i = 0;
	}
	else
		i = 1;
	while (i < argc)
	{
		num = ft_atol(argv[i]);
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

int	check_repetitions(int argc, char **argv)
{
	int	i;
	int	j;

	if (argc == 2)
	{
		argv = ft_split(argv[1], ' ');
		i = 0;
	}
	else
		i = 1;
	while (i < argc)
	{
		j = i + 1;
		while (j < argc)
		{
			if (ft_atol(argv[i]) == ft_atol(argv[j]))
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

void	check_already_sorted(int argc, char **argv)
{
	int	prev;
	int	next;
	int	i;

	if (argc == 2)
	{
		argv = ft_split(argv[1], ' ');
		i = 1;
	}
	else
		i = 2;
	while (i < argc)
	{
		prev = ft_atol(argv[i - 1]);
		next = ft_atol(argv[i]);
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
