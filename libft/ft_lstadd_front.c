/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkozlova <vkozlova@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 21:54:25 by vkozlova          #+#    #+#             */
/*   Updated: 2023/05/27 17:07:10 by vkozlova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	new->next = *lst;
	*lst = new;
}

// int main()
// {	
// 	t_list *node1 = ft_lstnew("node 1");
// 	t_list *node2 = ft_lstnew("node 2");
// 	t_list *new = ft_lstnew("new node");
// 	t_list **lst = &node1;
// 	node2->next = NULL;
// 	node1->next = node2;
// 	printf("Content: %s\n", (*lst)->content);
// 	ft_lstadd_front(lst, new);
// 	printf("Content: %s\n", (*lst)->content);
// }