/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkozlova <vkozlova@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 11:12:51 by vkozlova          #+#    #+#             */
/*   Updated: 2023/05/27 17:06:33 by vkozlova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	while (lst != NULL && lst->next != NULL)
		lst = lst->next;
	return (lst);
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
// }
