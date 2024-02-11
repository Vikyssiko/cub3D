/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkozlova <vkozlova@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 11:35:03 by vkozlova          #+#    #+#             */
/*   Updated: 2023/05/27 17:07:14 by vkozlova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*current;

	current = *lst;
	if (*lst == NULL)
		ft_lstadd_front(lst, new);
	else
	{
		while (current->next != NULL)
			current = current->next;
		current->next = new;
	}
}

// int main()
// {	
// 	t_list *node1 = ft_lstnew("node 1");
// 	t_list *node2 = ft_lstnew("node 2");
// 	t_list *new = ft_lstnew("new node");
// 	t_list **lst = &node1;
// 	node2->next = NULL;
// 	node1->next = node2;
// 	ft_lstadd_front(lst, new);
// 	printf("Content: %s\n", ft_lstlast(*lst)->content);
// 	ft_lstadd_back(lst, ft_lstnew("last node"));
// 	printf("Content: %s\n", ft_lstlast(*lst)->content);
// }
