/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkozlova <vkozlova@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 11:51:38 by vkozlova          #+#    #+#             */
/*   Updated: 2023/05/27 13:32:26 by vkozlova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	del(lst->content);
	free(lst);
}

// void delete(void *content)
// {
// 	free(content);
// }

// int main()
// {	
// 	t_list *node1 = ft_lstnew("node 1");
// 	t_list *node2 = ft_lstnew("node 2");
// 	t_list **lst = &node1;
// 	node2->next = NULL;
// 	node1->next = node2;
// 	ft_lstdelone(*lst, delete);
// 	printf("Content: %s\n", (*lst)->next->content);
// 	printf("Content: %s\n", (*lst)->content);
// }
