/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkozlova <vkozlova@student.42wolfsburg.d>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 16:12:48 by vkozlova          #+#    #+#             */
/*   Updated: 2024/03/28 16:12:48 by vkozlova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3D.h"

t_door_list	*lstnew(t_img *content)
{
	t_door_list	*node;

	node = malloc(sizeof(t_door_list));
	if (node == NULL)
		return (NULL);
	node->door_img = content;
	node->next = NULL;
	return (node);
}

void	lstadd_front(t_door_list **lst, t_door_list *new)
{
	new->next = *lst;
	*lst = new;
}

t_door_list	*lstlast(t_door_list *list)
{
	while (list != NULL && list->next != NULL)
		list = list->next;
	return (list);
}

int	lstsize(t_door_list *list)
{
	int	size;

	size = 0;
	while (list != NULL)
	{
		list = list->next;
		size++;
	}
	return (size);
}

void	lstadd_back(t_door_list **list, t_door_list *new)
{
	t_door_list	*current;

	current = *list;
	while (current->next != NULL)
		current = current->next;
	current->next = new;
}
