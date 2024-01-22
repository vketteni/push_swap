/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   distances.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vketteni <vketteni@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 14:36:38 by vketteni          #+#    #+#             */
/*   Updated: 2024/01/22 19:42:16 by vketteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int ft_distance_shortest(t_dlist *start, t_dlist *end)
{
    int distance;
    int size;

    size = ft_dlstsize(ft_dlstfirst(start));
    distance = 0;
    while (start != end)
    {
        start = start->next;
        distance++;
    }
    if (distance > (size / 2))
        return ((size - distance) * -1);
    return (distance);
}

int	ft_distance_to_closest_adjacent_value(t_dlist *start, t_dlist *next_highest,
		t_dlist *next_lowest)
{
	int	distance_to_highest;
	int	distance_to_lowest;

	distance_to_lowest = shortest_distance(start, next_lowest);
	distance_to_highest = shortest_distance(start, next_highest);
	if (ft_absolute(distance_to_lowest) < ft_absolute(distance_to_highest))
	    return (distance_to_lowest);
    return (distance_to_highest);
}

int ft_distance_by_rotation(t_dlist *start, t_dlist *end)
{
    int distance;
    int size;

    size = ft_dlstsize(ft_dlstfirst(start));
    distance = 0;
    while (start != end)
    {
        start = start->next;
        distance++;
    }
    return (distance);
}

int ft_distance_by_reverse_rotation(t_dlist *start, t_dlist *end)
{
    int distance;
    int size;

    size = ft_dlstsize(ft_dlstfirst(start));
    distance = 0;
    while (start != end)
    {
        start = start->next;
        distance++;
    }
    return (size - distance);
}