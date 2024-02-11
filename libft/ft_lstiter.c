/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkozlova <vkozlova@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 12:11:41 by vkozlova          #+#    #+#             */
/*   Updated: 2023/05/27 17:09:03 by vkozlova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	while (lst != NULL)
	{
		f(lst->content);
		lst = lst->next;
	}
}

// void	function(void *content)
// {
// 	content = "Modified";
// }

// int main()
// {	
// 	t_list *node1 = ft_lstnew("node 1");
// 	t_list *node2 = ft_lstnew("node 2");
// 	t_list **lst = &node1;
// 	node2->next = NULL;
// 	node1->next = node2;
// 	ft_lstiter(*lst, function);
// 	printf("Content: %s\n", (*lst)->content);
// 	printf("Content: %s\n", (*lst)->next->content);
// }