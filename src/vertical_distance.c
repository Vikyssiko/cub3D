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

t_dist 	find_dist(t_game **game, t_ray *ray, double angle, t_dist dist, int door)
{
	dist.dist = 2147483648;
	while (1)
	{
//		door = 1;
//		if (door && (((int)(ray->y) >> BITS) < 0 || ((int)(ray->y) >> BITS) >= (*game)->map->length
//			|| (*game)->map->map[(int)(ray->y) >> BITS][(int)(ray->x) >> BITS] == '1'
//			|| (*game)->map->map[(int)(ray->y) >> BITS][(int)(ray->x) >> BITS] == ' '))
//		{
////			dist.direction = 'D';
//			break ;
//		}
		if (door && (((int)(ray->y) >> BITS) < 0 || ((int)(ray->y) >> BITS) >= (*game)->map->length
			|| (*game)->map->map[(int)(ray->y) >> BITS][(int)(ray->x) >> BITS] == 'D'))
		{
			double distance = cos(angle) * (ray->x - (*game)->player_x + ray->x_diff / 2)
						- sin(angle) * (ray->y - (*game)->player_y + ray->y_diff / 2);
//			if (0 > distance) {
//				printf("dist: %f, angle: %f\n", dist.dist, angle);
//			}
			dist.dist = find_min(dist.dist, distance);
			dist.hit_point = ray->y + ray->y_diff / 2;
			dist.direction = 'D';
			break ;
		}
		if (((int)(ray->y) >> BITS) < 0 || ((int)(ray->y) >> BITS) >= (*game)->map->length
			|| (*game)->map->map[(int)(ray->y) >> BITS][(int)(ray->x) >> BITS] == '1'
			|| (*game)->map->map[(int)(ray->y) >> BITS][(int)(ray->x) >> BITS] == ' ')
		{
			double distance = cos(angle) * (ray->x - (*game)->player_x)
					- sin(angle) * (ray->y - (*game)->player_y);
			dist.dist = find_min(dist.dist, distance);
			dist.hit_point = ray->y;
			break ;
		}
//		else if (door && (*game)->map->map[(int)(ray->y) >> BITS][(int)(ray->x) >> BITS] == 'D')
//		{
//			double distance = cos(angle) * (ray->x - (*game)->player_x + ray->x_diff / 2)
//					- sin(angle) * (ray->y - (*game)->player_y + ray->y_diff / 2);
//			dist.dist = find_min(dist.dist, distance);
//			dist.hit_point = ray->y + ray->y_diff / 2;
//			dist.direction = 'D';
//			break ;
//		}
		ray->x += ray->x_diff;
		ray->y += ray->y_diff;
	}
//	dist.hit_point = ray->y;
	return (dist);
}

t_dist 	vertical_hit_dist(t_game **game, double angle, int door)
{
	t_ray	ray;
	double	tang;
	t_dist	dist;

	if ((angle > M_PI_2 - 0.001 && angle < M_PI_2 + 0.001))
		angle += 0.001;
	else if (angle > M_PI_2 * 3 - 0.001 && angle < M_PI_2 * 3 + 0.001)
		angle -= 0.001;
	tang = tan(angle);
	dist.direction = 'E';
	if (cos(angle) > 0.001)
	{
		ray.x = (((int)(*game)->player_x >> BITS) << BITS) + CUBE;
		ray.x_diff = CUBE;
		ray.y = ((*game)->player_x - ray.x) * tang + (*game)->player_y;
		ray.y_diff = -ray.x_diff * tang;
	}
	else
	{
		ray.x = (((int)(*game)->player_x >> BITS) << BITS) - 0.0002;
		ray.x_diff = -CUBE;
		ray.y = ((*game)->player_x - ray.x) * tang + (*game)->player_y;
		ray.y_diff = -ray.x_diff * tang;
		dist.direction = 'W';
	}
//	else
//	{
//		ray.y_diff = CUBE * cos(M_PI_2 - 0.0002);
//		ray.x_diff = 0;
//		ray.x = (*game)->player_x;
//		ray.y = (*game)->player_y;
//	}
	return (find_dist(game, &ray, angle, dist, door));
}

double		find_min(double a, double b)
{
	if (a <= b)
		return (a);
	return (b);
}

t_dist		find_min_dist(t_dist vert, t_dist hor)
{
	if (vert.dist <= hor.dist)
		return (vert);
	return (hor);
}
