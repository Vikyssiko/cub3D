/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vertical_distance.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkozlova <vkozlova@student.42wolfsburg.d>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 13:09:48 by vkozlova          #+#    #+#             */
/*   Updated: 2024/02/15 13:09:51 by vkozlova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3D.h"

int	find_first_x_vert(t_game **game, int angle)
{
	int	x_coordinate;

	x_coordinate = (int)((*game)->player_x / 64);
	if (angle < 90 || angle >= 270)
		return (x_coordinate * 64 + 64);
	return (x_coordinate * 64 - 1);
}

int	find_x_diff_vert(int angle)
{
	if (angle < 90 || angle >= 270)
		return (64);
	return (-64);
}

double	find_y_diff_vert(int angle)
{
	double	diff;

	diff = 64 * tan(angle * 0.0174533);
	if (angle < 180)
		return (-diff);
	return (diff);
}

double 	vertical_hit_dist(t_game **game, int angle)
{
	int	x;
	int	y;
	double 	dist;

	x = find_first_x_vert(game, angle);
	y = (*game)->player_y + ((*game)->player_x - x) * tan(angle * 0.0174533);
//	if (y > (*game)->map->length * 64)
//		return (MAXFLOAT);
//	printf("vertical x: %i, y: %i\n", x, y);
//	printf("%c\n", (*game)->map->map[y / 64][x / 64]);
	if (x < 0)
		x = 0;
	if (y < 0)
		y = 0;
	if ((*game)->map->map[y / 64][x / 64] == '1')
		return (abs(x - (*game)->player_x) / (*game)->cos_array[angle]);
	while (1)
	{
//		printf("here1\n");
		x = x + find_x_diff_vert(angle);
//		printf("x_diff_vert: %d\n", find_x_diff_vert(angle));
		y = y + find_y_diff_vert(angle);
//		printf("y_diff_vert: %f\n", find_y_diff_vert(angle));
//		printf("here3\n");
//		printf("vertical x: %i, y: %i\n", x, y);
		if (x < 0)
			x = 0;
		if (y < 0)
			y = 0;
		if ((*game)->map->map[y / 64][x / 64] == '1')
			break ;
	}
//	printf("here4\n");
	dist = abs(x - (*game)->player_x) / (*game)->cos_array[angle];
	printf("dist vert: %f\n", dist);
//	printf("vertical x: %i, y: %i\n", x, y);
	printf("vertical x: %i, y: %i\n", x / 64, y / 64);
	return (dist);
}

int		find_min(int a, int b)
{
	if (a <= b)
		return (a);
	return (b);
}
