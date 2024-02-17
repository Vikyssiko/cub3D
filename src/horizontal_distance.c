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

int	find_first_y(t_game **game, double angle)
{
	int	y_coordinate;

	y_coordinate = (int)((*game)->player_y / 64);
	if (angle < PI)
		return (y_coordinate * 64 - 1);
	return (y_coordinate * 64 + 64);
}

int	find_y_diff(double angle)
{
	if (angle < PI)
		return (-64);
	return (64);
}

int	find_x_diff(double angle)
{
	double	diff;

	diff = 64 / tan(angle);
	if (angle >= PI / 2 && angle < PI * 1.5)
		return (-diff);
	return (diff);
}

double 	horizont_hit_dist(t_game **game, double angle)
{
	t_ray	ray;
//	double	dist;
	double	tang;

	tang = 1.0 / tan(angle);
//	dist = 2147483648;
	if (sin(angle) > 0.001)
	{
		ray.y = (((int)(*game)->player_y >> 6) << 6) - 0.0001;
		ray.y_diff = -64;
		ray.x = ((*game)->player_y - ray.y) * tang + (*game)->player_x;
		ray.x_diff = -ray.y_diff * tang;
	}
	else if (sin(angle) < -0.001)
	{
		ray.y = (((int)(*game)->player_y >> 6) << 6) + 64;
		ray.y_diff = 64;
		ray.x = ((*game)->player_y - ray.y) * tang + (*game)->player_x;
		ray.x_diff = -ray.y_diff * tang;
	}
	else
	{
		ray.x = (*game)->player_x;
		ray.y = (*game)->player_y;
	}
//	while (1)
//	{
//		if (ray.x < 0 || ray.x >= (*game)->map_width || (*game)->map->map[(int)(ray.y) >> 6][(int)(ray.x) >> 6] == '1')
//		{
//			dist = find_min(dist, cos(angle) * (ray.x - (*game)->player_x) - sin(angle) * (ray.y - (*game)->player_y));
//			break ;
//		}
//		ray.x += ray.x_diff;
//		ray.y += ray.y_diff;
//	}
	return (find_dist(game, &ray, angle));

//	int		x;
//	int		y;
//	double	dist;
//
//	y = find_first_y(game, angle);
//	x = (*game)->player_x + ((*game)->player_y - y) / tan(angle);
//	if (x < 0)
//		x = 0;
//	if (y < 0)
//		y = 0;
//	if ((*game)->map->map[y / 64][x / 64] == '1')
//		return (abs(x - (*game)->player_x) / (*game)->cos_array[(int)(angle * 57.2958)]);
//	while (1)
//	{
//		y = y + find_y_diff(angle);
//		x = x + find_x_diff(angle);
//		if (x < 0)
//			x = 0;
//		if (y < 0)
//			y = 0;
//		if ((*game)->map->map[y / 64][x / 64] == '1')
//			break ;
//	}
////	(*ray).x = x;
////	(*ray).y = y;
//	dist = abs(x - (*game)->player_x) / (*game)->cos_array[(int)(angle * 57.2958)];
////	printf("x: %i, player_x: %i, angle: %i\n", x, (*game)->player_x, angle);
////	printf("dist hor: %f\n", dist);
////	printf("horizontal x: %i, y: %i\n", x / 64, y / 64);
//	return (dist);
}
