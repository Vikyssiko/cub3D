/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cardinal_directions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkozlova <vkozlova@student.42wolfsburg.d>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 12:13:11 by vkozlova          #+#    #+#             */
/*   Updated: 2024/02/11 12:13:16 by vkozlova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3D.h"

void	check_north(t_game **game, char **instructions)
{
	if (ft_strcmp(instructions[0], "NO") == 0)
	{
		if ((*game)->north == NULL) {
			(*game)->north = ft_strtrim(instructions[1], "\n");
		} else {
			clean_and_exit("Invalid north instruction", game);
		}
	}
}

void	check_south(t_game **game, char **instructions)
{
	if (ft_strcmp(instructions[0], "SO") == 0)
	{
		if ((*game)->south == NULL) {
			(*game)->south = ft_strtrim(instructions[1], "\n");
		} else {
			clean_and_exit("Invalid south instruction", game);
		}
	}
}

void	check_west(t_game **game, char **instructions)
{
	if (ft_strcmp(instructions[0], "WE") == 0)
	{
		if ((*game)->west == NULL) {
			(*game)->west = ft_strtrim(instructions[1], "\n");
		} else {
			clean_and_exit("Invalid west instruction", game);
		}
	}
}

void	check_east(t_game **game, char **instructions)
{
	if (ft_strcmp(instructions[0], "EA") == 0)
	{
		if ((*game)->east == NULL) {
			(*game)->east = ft_strtrim(instructions[1], "\n");
		} else {
			clean_and_exit("Invalid east instruction", game);
		}
	}
}

void	check_cardinal_directions(t_game **game, char **instructions)
{
	check_north(game, instructions);
	check_south(game, instructions);
	check_east(game, instructions);
	check_west(game, instructions);
}
