/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vketteni <vketteni@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 13:16:13 by vketteni          #+#    #+#             */
/*   Updated: 2023/12/01 13:18:02 by vketteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*current_node;
	t_list	*tmp;

	current_node = *lst;
	while (current_node != 0)
	{
		tmp = current_node;
		current_node = current_node->next;
		del(tmp->content);
		free(tmp);
	}
	*lst = 0;
}

/*

#include <stdio.h>
#include <string.h>

void ft_del(void *content)
{
    if (content)
        free(content);
}

void print_result(t_list **lstelem_refs, size_t len)
{
    int passed = 1;
    int i = 0;
    if (len == 0)
    {
        printf("List element (%d)\n", i);
        printf("Null pointer:\t%s\n", lstelem_refs[i] == 0 ? "Yes" : "No");
        if (lstelem_refs[i] != 0)
            passed = 0;
    }
    while ((size_t)i < len)
    {
        printf("List element (%d)\n", i);
        printf("Null pointer:\t%s\n", lstelem_refs[i] == 0 ? "Yes" : "No");
        if (lstelem_refs[i] != 0)
            passed = 0;
        i++;
    }
    printf("Passed:\t\t%s\n", passed ? "Yes" : "No");
}

size_t  ft_lstlen(t_list *lst)
{
    size_t i;

    i = 0;
    while (lst != 0)
    {
        i++;
        lst = lst->next;
    }
    return (i);
}

t_list  **get_element_references(t_list *lst)
{
    int i;
    size_t  len;

    len = ft_lstlen(lst);
    t_list **element_refs = malloc(len * sizeof(t_list *));
    if (element_refs == NULL)
    {
        perror("Memory allocation failed");
        exit(EXIT_FAILURE);
    }
    i = 0;
    while (lst != 0)
    {
        element_refs[i++] = lst;
        lst = lst->next;
    }
    return (element_refs);
}

int main(void)
{
    //  void    ft_lstclear(t_list **lst, void (*del)(void*))
    printf("Test Case 1: Testing clear empty list\n");
    t_list  *lst_1 = 0;
    size_t len_1 = ft_lstlen(lst_1);

    t_list  **lstelem_refs_1 = get_element_references(lst_1);
    ft_lstclear(&lst_1, ft_del);
    print_result(lstelem_refs_1, len_1);

    printf("Test Case 2: Testing clear populated list\n");
    t_list  *lst_2 = ft_lstnew(ft_strdup("1"));
    size_t len_2 = ft_lstlen(lst_2);

    t_list  **lstelem_refs_2 = get_element_references(lst_2);
    ft_lstclear(&lst_2, ft_del);
    print_result(lstelem_refs_2, len_2);

    free(lstelem_refs_1);
    free(lstelem_refs_2);
}


*/
