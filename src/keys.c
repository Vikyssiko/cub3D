/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkozlova <vkozlova@student.42wolfsburg.d>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 19:08:38 by vkozlova          #+#    #+#             */
/*   Updated: 2024/02/22 19:08:38 by vkozlova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3D.h"

void	change_position(t_game **game, int x, int y)
{
	int	y_index;
	int	x_index;

	y_index = y >> BITS;
	x_index = x >> BITS;
	if ((*game)->map->map[y_index][x_index] == '0'
		|| (*game)->map->map[y_index][x_index] == 'N'
		|| (*game)->map->map[y_index][x_index] == 'S'
		|| (*game)->map->map[y_index][x_index] == 'W'
		|| (*game)->map->map[y_index][x_index] == 'E')
	{
		(*game)->player_y = y;
		(*game)->player_x = x;
	}
}

void	go_straight(t_game **game)
{
	int	y;
	int	x;

	y = (*game)->player_y - sin((*game)->player_angle) * (CUBE / 25);
	x = (*game)->player_x + cos((*game)->player_angle) * (CUBE / 25);
	change_position(game, x, y);
}

void	go_back(t_game **game)
{
	int	y;
	int	x;

	y = (*game)->player_y + sin((*game)->player_angle) * (CUBE / 25);
	x = (*game)->player_x - cos((*game)->player_angle) * (CUBE / 25);
	change_position(game, x, y);
}

void	go_left(t_game **game)
{
	int	y;
	int	x;

	y = (*game)->player_y - cos((*game)->player_angle) * (CUBE / 25);
	x = (*game)->player_x - sin((*game)->player_angle) * (CUBE / 25);
	change_position(game, x, y);
}

void	go_right(t_game **game)
{
	int	y;
	int	x;

	y = (*game)->player_y + cos((*game)->player_angle) * (CUBE / 25);
	x = (*game)->player_x + sin((*game)->player_angle) * (CUBE / 25);
	change_position(game, x, y);
}
