/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vketteni <vketteni@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 13:20:48 by vketteni          #+#    #+#             */
/*   Updated: 2023/12/01 13:22:49 by vketteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*current_node;

	if (lst == 0 || new == 0)
		return ;
	if (*lst == 0)
		*lst = new;
	else
	{
		current_node = *lst;
		while (current_node->next != 0)
			current_node = current_node->next;
		current_node->next = new;
	}
}

/*
# include <stdio.h>
# include <string.h>
void    print_result(t_list *lst, t_list *expected_result)
{
    int i;
    int passed;

    i = 0;
    passed = 1;
    while (expected_result != 0)
    {
        printf("List element: (%d)\n", i++);
        printf("Expected value:\t'%s'\n", (char *)expected_result->content);
        printf("Actual value:\t'%s'\n", (char *)lst->content);
        if (strcmp(expected_result->content, lst->content) != 0)
            passed = 0;
        expected_result = (expected_result)->next;
        lst = (lst)->next;
    }
    printf("Passed:\t%s\n", passed ? "Yes" : "No");
    printf("\n");
}
int main(void)
{
   // void    ft_lstadd_back(t_list **lst, t_list *new)
   printf("Test Case 1: Testing adding element to the back of empty list.\n");
    t_list   *element_1_1 = ft_lstnew(ft_strdup("1"));

    t_list   *expected_result_1 = element_1_1;

    t_list   *begin_1 = 0;
    ft_lstadd_back(&begin_1, ft_lstnew(ft_strdup("1")));

    print_result(begin_1, expected_result_1);

    printf("Test Case 2: Testing adding element to the back of existing list."
		   "\n");
    t_list  *element_1_2 = ft_lstnew(ft_strdup("1"));
    t_list  *element_2_2 = ft_lstnew(ft_strdup("2"));
    t_list  *element_3_2 = ft_lstnew(ft_strdup("3"));

    t_list   *expected_result_2 = element_1_2;
    expected_result_2->next = element_2_2;
    expected_result_2->next->next = element_3_2;

    t_list  *begin_2 = 0;
    ft_lstadd_back(&begin_2, ft_lstnew(ft_strdup("1")));
    ft_lstadd_back(&begin_2, ft_lstnew(ft_strdup("2")));
    ft_lstadd_back(&begin_2, ft_lstnew(ft_strdup("3")));

    print_result(begin_2, expected_result_2);
}*/
