/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkozlova <vkozlova@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 17:03:59 by vkozlova          #+#    #+#             */
/*   Updated: 2024/02/25 17:03:59 by vkozlova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3D.h"

void	clean_instructions(char **instructions)
{
	free(instructions[0]);
	free(instructions[1]);
}

void	free_string_array(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

void	free_stack(t_stack **stack)
{
	t_stack	*tmp;

	tmp = NULL;
	if (!(*stack))
		return ;
	while (*stack)
	{
		tmp = (*stack)->next;
		free((*stack)->str);
		free(*stack);
		*stack = tmp;
	}
}
