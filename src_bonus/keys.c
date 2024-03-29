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
		|| (*game)->map->map[y_index][x_index] == 'E'
		|| ((*game)->door_open && (*game)->map->map[y_index][x_index] == 'D'))
	{
		(*game)->player_y = y;
		(*game)->player_x = x;
	}
}

//void	go_straight(t_game **game)
//{
//	int	y;
//	int	x;
//
//	y = (*game)->player_y - sin((*game)->player_angle) * (CUBE / 10);
//	x = (*game)->player_x + cos((*game)->player_angle) * (CUBE / 10);
//	change_position(game, x, y);
//}
//
//void	go_back(t_game **game)
//{
//	int	y;
//	int	x;
//
//	y = (*game)->player_y + sin((*game)->player_angle) * (CUBE / 10);
//	x = (*game)->player_x - cos((*game)->player_angle) * (CUBE / 10);
//	change_position(game, x, y);
//}
//
//void	go_left(t_game **game)
//{
//	int	y;
//	int	x;
//
//	y = (*game)->player_y - cos((*game)->player_angle) * (CUBE / 10);
//	x = (*game)->player_x - sin((*game)->player_angle) * (CUBE / 10);
//	change_position(game, x, y);
//}
//
//void	go_right(t_game **game)
//{
//	int	y;
//	int	x;
//
//	y = (*game)->player_y + cos((*game)->player_angle) * (CUBE / 10);
//	x = (*game)->player_x + sin((*game)->player_angle) * (CUBE / 10);
//	change_position(game, x, y);
//}

void	keys(t_game **game) {
	int	y;
	int	x;

	y = (*game)->player_y;
	x = (*game)->player_x;
	if ((*game)->keys.w_pressed) {
		y -= sin((*game)->player_angle) * (CUBE / 10);
		x += cos((*game)->player_angle) * (CUBE / 10);
	}
	if ((*game)->keys.s_pressed) {
		y += sin((*game)->player_angle) * (CUBE / 10);
		x -= cos((*game)->player_angle) * (CUBE / 10);
	}
	if ((*game)->keys.a_pressed) {
		y -= cos((*game)->player_angle) * (CUBE / 10);
		x -= sin((*game)->player_angle) * (CUBE / 10);
	}
	if ((*game)->keys.d_pressed) {
		y += cos((*game)->player_angle) * (CUBE / 10);
		x += sin((*game)->player_angle) * (CUBE / 10);
	}
	if ((*game)->keys.left_pressed)
		(*game)->player_angle = fix_angle((*game)->player_angle + 0.1);
	if ((*game)->keys.right_pressed)
		(*game)->player_angle = fix_angle((*game)->player_angle - 0.1);
	change_position(game, x, y);
}
