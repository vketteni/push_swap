/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vketteni <vketteni@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 03:09:03 by vketteni          #+#    #+#             */
/*   Updated: 2024/01/30 06:40:41 by vketteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	int *stack_size_a;
	int *stack_size_b;
	long *stack_a;
	long *stack_b;

	if (argc < 2 || initialize_stack_size(argc, stack_size_a, stack_size_b) == -1
		|| initialize_inputs_to_stack(argc, argv, stack_a, stack_b) == -1)
		ft_printf("Error\n");
	if ((stack_size_a[1] == 2) && (stack_a[0] > stack_a[1]))
		rotate_stack_a(stack_a, stack_size_a);
	if (stack_size_a <= 3)
		sort_three_and_under(stack_a, stack_b, stack_size_a, stack_size_b);
    else if (stack_size_a <= 5)
        sort_five_and_under(stack_a, stack_b, stack_size_a, stack_size_b);
    else
        sort_gt_five(stack_a, stack_b, stack_size_a, stack_size_b);
    return (0);
}

void sort_three_and_under(long *stack_a, long *stack_b, int *stack_size_a, int *stack_size_b)
{
    if (stack_a[0] > stack_a[1] && stack_a[0] < stack_a[2])
        swap_a(stack_a);
    else if (stack_a[0] < stack_a[1] && stack_a[0] > stack_a[2])
    {
        reverse_rotate_a(stack_a);
        swap_a(stack_a);
    }
    else if (stack_a[1] < stack_a[0] && stack_a[1] > stack_a[2])
    {
        rotate_a(stack_a);
        swap_a(stack_a);
    }
    else if (stack_a[1] > stack_a[0] && stack_a[1] < stack_a[2])
        return ;
    else if (stack_a[2] < stack_a[0] && stack_a[2] > stack_a[1])
        rotate_a(stack_a);
    else if (stack_a[2] > stack_a[0] && stack_a[2] < stack_a[1])
        reverse_rotate_a(stack_a);
}

void    round_one(long *stack_a, long *stack_b, int *stack_size_a, int *stack_size_b)
{

}

void    sort_five_and_under(long *stack_a, long *stack_b, int *stack_size_a, int *stack_size_b)
{
    push_b(stack_a, stack_b);
    push_b(stack_a, stack_b);
    sort_three_and_under(stack_a, stack_b, stack_size_a, stack_size_b);
    while (stack_b != NULL)
    {
        if (stack_size_a == 3)
            round_one(stack_a, stack_b, stack_size_a, stack_size_b);
        else
            round_two(stack_a, stack_b, stack_size_a, stack_size_b);
    }
}

void sort_gt_five(long *stack_a, long *stack_b, int *stack_size_a, int *stack_size_b)
{
    
}