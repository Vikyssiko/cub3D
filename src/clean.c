/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkozlova <vkozlova@student.42wolfsburg.d>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 14:24:29 by vkozlova          #+#    #+#             */
/*   Updated: 2024/03/30 14:24:29 by vkozlova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3D.h"

void	clean_instructions(char **instructions)
{
	free(instructions[0]);
	free(instructions[1]);
	free(instructions);
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

void	free_map(t_game **game)
{
	int	y;

	y = 0;
	while (y < (*game)->map->length)
	{
		free((*game)->map->map[y++]);
	}
	free((*game)->map->map);
	free((*game)->map);
}

void	free_game(t_game **game)
{
	free_images(game);
	free_pixel_arrays(game);
	free_map(game);
}
