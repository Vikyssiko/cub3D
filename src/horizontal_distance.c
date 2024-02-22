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

t_dist 	horizont_hit_dist(t_game **game, double angle)
{
	t_ray	ray;
	t_dist 	dist;
	double	tang;

//	if (tan(angle) > 1000)
//		tang = 1.0 / 75;
//	else
		tang = 1.0 / tan(angle);
//	if ((tang < 0.001 && tang > 0))
//		tang = 0.001;
//	else if ((tang > -0.001 && tang < 0))
//		tang = -0.001;
//		printf("tang: %f\n", tang);
	dist.dist = 2147483648;
//	dist.texture = (*game)->north_img;
	dist.color = 0xFA8072;
	if (sin(angle) > 0.001) //up
	{
		ray.y = (((int)(*game)->player_y >> 6) << 6) - 0.0001;
		ray.y_diff = -64;
		ray.x = ((*game)->player_y - ray.y) * tang + (*game)->player_x;
		ray.x_diff = -ray.y_diff * tang;
//        dist.texture = (*game)->north_img;
		dist.direction = 'N';
	}
	else if (sin(angle) < -0.001) //down
	{
		ray.y = (((int)(*game)->player_y >> 6) << 6) + 64;
		ray.y_diff = 64;
		ray.x = ((*game)->player_y - ray.y) * tang + (*game)->player_x;
		ray.x_diff = -ray.y_diff * tang;
//        dist.texture = (*game)->south_img;
		dist.color = 0xCCB3FF;
		dist.direction = 'S';
	}
	else
	{
//		printf("gfdf\n");
		ray.x = (*game)->player_x;
		ray.y = (*game)->player_y;
	}
	while (1)
	{
		if (((int)(ray.x) >> 6) < 0 || ((int)(ray.x) >> 6) >= (*game)->map_width
			|| (*game)->map->map[(int)(ray.y) >> 6][(int)(ray.x) >> 6] == '1'
			|| (*game)->map->map[(int)(ray.y) >> 6][(int)(ray.x) >> 6] == ' ')
		{
			double distance = cos(angle) * (ray.x - (*game)->player_x) - sin(angle) * (ray.y - (*game)->player_y);
//			while (distance < 0)
//			{
//				angle -= 0.00058177;
//				distance = cos(angle) * (ray.x - (*game)->player_x) - sin(angle) * (ray.y - (*game)->player_y);
//			}
//			if (distance < -1)
//				distance = -distance;
			dist.dist = find_min(dist.dist, distance);
//			dist.dist = find_min(dist.dist, cos(angle) * (ray.x - (*game)->player_x) - sin(angle) * (ray.y - (*game)->player_y));
			break ;
		}
		ray.x += ray.x_diff;
		ray.y += ray.y_diff;
	}
//	if (angle > M_PI - 0.001 && angle < M_PI + 0.001)
//		printf("dist: %f\n", dist.dist);
//	printf("horizontal: %f\n", dist);
//	dist.color = 0xFA8072;
	return (dist);

////	(*ray).x = x;
////	(*ray).y = y;
//	dist = abs(x - (*game)->player_x) / (*game)->cos_array[(int)(angle * 57.2958)];
//	return (dist);
}
