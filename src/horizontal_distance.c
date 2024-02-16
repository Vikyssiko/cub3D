/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   horizontal_distance.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkozlova <vkozlova@student.42wolfsburg.d>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 13:08:30 by vkozlova          #+#    #+#             */
/*   Updated: 2024/02/15 13:08:35 by vkozlova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3D.h"

int	find_first_y(t_game **game, int angle)
{
	int	y_coordinate;

	y_coordinate = (int)((*game)->player_y / 64);
	if (angle < 180)
		return (y_coordinate * 64 - 1);
	return (y_coordinate * 64 + 64);
}

int	find_y_diff(int angle)
{
	if (angle < 180)
		return (-64);
	return (64);
}

int	find_x_diff(int angle)
{
	double	diff;

	diff = 64 / tan(angle * 0.0174533);
	if (angle >= 90 && angle < 270)
		return (-diff);
	return (diff);
}

double 	horizont_hit_dist(t_game **game, int angle)
{
	int		x;
	int		y;
	double	dist;

	y = find_first_y(game, angle);
	x = (*game)->player_x + ((*game)->player_y - y) / tan(angle * 0.0174533);
	if (x < 0)
		x = 0;
	if (y < 0)
		y = 0;
	if ((*game)->map->map[y / 64][x / 64] == '1')
		return (abs(x - (*game)->player_x) / (*game)->cos_array[angle]);
	while (1)
	{
		y = y + find_y_diff(angle);
		x = x + find_x_diff(angle);
		if (x < 0)
			x = 0;
		if (y < 0)
			y = 0;
		if ((*game)->map->map[y / 64][x / 64] == '1')
			break ;
	}
//	(*ray).x = x;
//	(*ray).y = y;
	dist = abs(x - (*game)->player_x) / (*game)->cos_array[angle];
//	printf("x: %i, player_x: %i, angle: %i\n", x, (*game)->player_x, angle);
//	printf("dist hor: %f\n", dist);
//	printf("horizontal x: %i, y: %i\n", x / 64, y / 64);
	return (dist);
}
