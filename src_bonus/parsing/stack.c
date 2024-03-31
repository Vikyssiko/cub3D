/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkozlova <vkozlova@student.42wolfsburg.d>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 16:12:29 by vkozlova          #+#    #+#             */
/*   Updated: 2024/02/11 16:12:54 by vkozlova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../../header/cub3D.h"

t_stack	*ft_stcknew(char *content)
{
	t_stack	*node;

	node = malloc(sizeof(t_stack));
	if (node == NULL)
		return (NULL);
	node->str = content;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

int	ft_stcksize(t_stack *stck)
{
	int	size;

	size = 0;
	while (stck != NULL)
	{
		stck = stck->next;
		size++;
	}
	return (size);
}

void	ft_stckadd_back(t_stack **stack, t_stack *new)
{
	t_stack	*current;

	current = *stack;
	while (current->next != NULL)
		current = current->next;
	current->next = new;
	new->prev = current;
}
