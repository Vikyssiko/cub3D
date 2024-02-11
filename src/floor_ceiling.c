/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floor_ceiling.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkozlova <vkozlova@student.42wolfsburg.d>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 12:19:24 by vkozlova          #+#    #+#             */
/*   Updated: 2024/02/11 12:19:32 by vkozlova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3D.h"

void	check_floor(t_game **game, char **instructions)
{
	if (ft_strcmp(instructions[0], "F") == 0)
	{
		if ((*game)->floor == NULL) {
			(*game)->floor = ft_strtrim(instructions[1], "\n");
		} else {
			clean_and_exit("Invalid floor instruction", game);
		}
	}
}

void	check_ceiling(t_game **game, char **instructions)
{
	if (ft_strcmp(instructions[0], "C") == 0)
	{
		if ((*game)->ceiling == NULL) {
			(*game)->ceiling = ft_strtrim(instructions[1], "\n");
		} else {
			clean_and_exit("Invalid ceiling instruction", game);
		}
	}
}

void	check_floor_ceiling(t_game **game, char **instructions)
{
	check_floor(game, instructions);
	check_ceiling(game, instructions);
}
