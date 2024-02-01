/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vketteni <vketteni@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 14:33:03 by vketteni          #+#    #+#             */
/*   Updated: 2024/02/01 15:35:58 by vketteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int check_out_of_bounds(int argc, char **argv)
{
    int i;
    int num;

    i = 1;
    while (i < argc)
    {
        num = ft_atoi(argv[i]);
        if (num > 2147483647 || num < -2147483648)
        {
            ft_printf("Error\n");
            exit(-1);
        }
            return (-1);
        i++;
    }
    return (0);
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

int check_repetitions(int argc, char **argv)
{
    int i;
    int j;

    i = 1;
    while (i < argc)
    {
        j = i + 1;
        while (j < argc)
        {
            if (ft_atoi(argv[i]) == ft_atoi(argv[j]))
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

void    check_already_sorted(int argc, char **argv)
{
    int prev;
    int next;
    int i;

    i = 2;
    while (i < argc)
    {
        prev = ft_atoi(argv[i - 1]);
        next = ft_atoi(argv[i]);
        if (prev > next)
            return 0;
        i++;
    }
    ft_printf("Already sorted.\n");
    exit(0);
}