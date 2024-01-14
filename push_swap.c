/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vketteni <vketteni@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 14:54:00 by vketteni          #+#    #+#             */
/*   Updated: 2024/01/13 22:26:23 by vketteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// int main(void)
int main(int argc, char** argv)
{
	if (argc < 2)
		return (0);
    ft_print_operations(argc, argv, INSERTIONSORT);

    return (0);
}

void    ft_print_operations(int argc, char **argv, int sort_alg)
{
    if (sort_alg == INSERTIONSORT)
        ft_print_INSERTIONSORT(argc, argv);
    if (sort_alg == SELECTIONSORT)
        ft_print_SELECTIONSORT(argc, argv);
}

/* 	
*	Merge Sort is a divide-and-conquer sorting algorithm. 
*	It works by recursively dividing the unsorted list into 
*	smaller sub-lists until each sub-list contains only one element. 
*	Then, it merges these sub-lists in a way that the merged list is sorted. 
*	This process continues until the entire list is sorted.
*/
void	ft_print_SELECTIONSORT(int argc, char **argv)
{
	char	**sort_operations;
	t_list	**stack_a;
	t_list	**stack_b;

	ft_init_stack(stack_a, argc, argv);

}

char	*ft_pa