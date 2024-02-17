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

int	find_first_x_vert(t_game **game, double angle)
{
	int	x_coordinate;

	x_coordinate = (int)((*game)->player_x / 64);
	if (angle < PI / 2 || angle >= PI * 1.5)
		return (x_coordinate * 64 + 64);
	return (x_coordinate * 64 - 1);
}

int	find_x_diff_vert(double angle)
{
	if (angle < PI / 2 || angle >= PI * 1.5)
		return (64);
	return (-64);
}

double	find_y_diff_vert(double angle)
{
	double	diff;

	diff = 64 * tan(angle);
	if (angle < PI)
		return (-diff);
	return (diff);
}

double	find_dist(t_game **game, t_ray *ray, double angle)
{
	double	dist;

	dist = 2147483648;
	while (1)
	{
		if (ray->y < 0 || ray->y >= (*game)->map->length || (*game)->map->map[(int)(ray->y) >> 6][(int)(ray->x) >> 6] == '1')
		{
			dist = find_min(dist, cos(angle) * (ray->x - (*game)->player_x) - sin(angle) * (ray->y - (*game)->player_y));
			break ;
		}
		ray->x += ray->x_diff;
		ray->y += ray->y_diff;
	}
	return (dist);
}

double 	vertical_hit_dist(t_game **game, double angle)
{
	t_ray	ray;
	double	tang;

	tang = tan(angle);
	if (cos(angle) > 0.001)
	{
		ray.x = (((int)(*game)->player_x >> 6) << 6) + 64;
		ray.x_diff = 64;
		ray.y = ((*game)->player_x - ray.x) * tang + (*game)->player_y;
		ray.y_diff = -ray.x_diff * tang;
	}
	else if (cos(angle) < -0.001)
	{
		ray.x = (((int)(*game)->player_x >> 6) << 6) - 0.0001;
		ray.x_diff = -64;
		ray.y = ((*game)->player_x - ray.x) * tang + (*game)->player_y;
		ray.y_diff = -ray.x_diff * tang;
	}
	else
	{
		ray.x = (*game)->player_x;
		ray.y = (*game)->player_y;
	}
	return (find_dist(game, &ray, angle));

//	int	x;
//	int	y;
//	double 	dist;
//
//	x = find_first_x_vert(game, angle);
//	y = (*game)->player_y + ((*game)->player_x - x) * tan(angle);
////	if (y > (*game)->map->length * 64)
////		return (MAXFLOAT);
////	printf("vertical x: %i, y: %i\n", x, y);
////	printf("%c\n", (*game)->map->map[y / 64][x / 64]);
//	if (x < 0)
//		x = 0;
//	if (y < 0)
//		y = 0;
//	if ((*game)->map->map[y / 64][x / 64] == '1')
//		return (abs(x - (*game)->player_x) / (*game)->cos_array[(int)(angle * 57.2958)]);
//	while (1)
//	{
////		printf("here1\n");
//		x = x + find_x_diff_vert(angle);
////		printf("x_diff_vert: %d\n", find_x_diff_vert(angle));
//		y = y + find_y_diff_vert(angle);
////		printf("y_diff_vert: %f\n", find_y_diff_vert(angle));
////		printf("here3\n");
////		printf("vertical x: %i, y: %i\n", x, y);
//		if (x < 0)
//			x = 0;
//		if (y < 0)
//			y = 0;
//		if ((*game)->map->map[y / 64][x / 64] == '1')
//			break ;
//	}
////	printf("here4\n");
//	dist = abs(x - (*game)->player_x) / (*game)->cos_array[(int)(angle * 57.2958)];
//	printf("dist vert: %f\n", dist);
////	printf("vertical x: %i, y: %i\n", x, y);
//	printf("vertical x: %i, y: %i\n", x / 64, y / 64);
	return (dist);
}

double		find_min(double a, double b)
{
	if (a <= b)
		return (a);
	return (b);
}
