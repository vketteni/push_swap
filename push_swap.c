/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vketteni <vketteni@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 14:54:00 by vketteni          #+#    #+#             */
/*   Updated: 2024/01/13 15:16:23 by vketteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// int main(void)
int main(int argc, char** argv)
{
	if (argc < 2)
		return (0);
    ft_print_operations(argc, argv, RADIX);

    return (0);
}

void    ft_print_operations(int argc, char **argv, int sort_alg)
{
    if (sort_alg == RADIX)
        ft_print_radix(argc, argv);
    if (sort_alg == MERGESORT)
        ft_print_mergesort(argc, argv);
}