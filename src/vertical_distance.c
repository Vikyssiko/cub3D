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

int	hit_vert_door(t_game **game, t_ray *ray, t_dist *dist)
{
	char	**map;

	map = (*game)->map->map;
	if (((int)(ray->y) >> BITS) < 0
		|| ((int)(ray->y) >> BITS) >= (*game)->map->length
		|| map[(int)(ray->y) >> BITS][(int)(ray->x) >> BITS] == 'D')
	{
		dist->hit_point = ray->y + ray->y_diff / 2;
		dist->direction = 'D';
		return (1);
	}
	return (0);
}

int	next_is_not_floor_v(t_game **game, t_ray *ray)
{
	char	**map;

	map = (*game)->map->map;
	if (((int)(ray->y) >> BITS) < 0
		|| ((int)(ray->y) >> BITS) >= (*game)->map->length
		|| map[(int)(ray->y) >> BITS][(int)(ray->x) >> BITS] == '1'
		|| map[(int)(ray->y) >> BITS][(int)(ray->x) >> BITS] == ' ')
		return (1);
	return (0);
}

t_dist	find_dist_d(t_game **game, t_ray *ray, double angle, t_dist dist)
{
	double	distance;

	dist.dist = 2147483648;
	while (1)
	{
		if (hit_vert_door(game, ray, &dist))
		{
			distance = cos(angle) * (ray->x - (*game)->player_x
					+ ray->x_diff / 2) - sin(angle) * (ray->y
					- (*game)->player_y + ray->y_diff / 2);
			dist.dist = find_min(dist.dist, distance);
			break ;
		}
		if (next_is_not_floor_v(game, ray))
		{
			distance = cos(angle) * (ray->x - (*game)->player_x)
				- sin(angle) * (ray->y - (*game)->player_y);
			dist.dist = find_min(dist.dist, distance);
			dist.hit_point = ray->y;
			break ;
		}
		ray->x += ray->x_diff;
		ray->y += ray->y_diff;
	}
	return (dist);
}

t_dist	find_dist(t_game **game, t_ray *ray, double angle, t_dist dist)
{
	double	distance;
	char	**map;

	map = (*game)->map->map;
	dist.dist = 2147483648;
	while (1)
	{
		if (((int)(ray->y) >> BITS) < 0
			|| ((int)(ray->y) >> BITS) >= (*game)->map->length
			|| map[(int)(ray->y) >> BITS][(int)(ray->x) >> BITS] == '1'
			|| map[(int)(ray->y) >> BITS][(int)(ray->x) >> BITS] == ' ')
		{
			distance = cos(angle) * (ray->x - (*game)->player_x)
				- sin(angle) * (ray->y - (*game)->player_y);
			dist.dist = find_min(dist.dist, distance);
			dist.hit_point = ray->y;
			break ;
		}
		ray->x += ray->x_diff;
		ray->y += ray->y_diff;
	}
	return (dist);
}

t_dist	vertical_hit_dist(t_game **game, double angle, int door)
{
	t_ray	ray;
	t_dist	dist;

	if ((angle > M_PI_2 - 0.001 && angle < M_PI_2 + 0.001))
		angle += 0.001;
	else if (angle > M_PI_2 * 3 - 0.001 && angle < M_PI_2 * 3 + 0.001)
		angle -= 0.001;
	dist.direction = 'E';
	if (cos(angle) > 0.001)
	{
		ray.x = (((int)(*game)->player_x >> BITS) << BITS) + CUBE;
		ray.x_diff = CUBE;
	}
	else
	{
		ray.x = (((int)(*game)->player_x >> BITS) << BITS) - 0.0002;
		ray.x_diff = -CUBE;
		dist.direction = 'W';
	}
	ray.y = ((*game)->player_x - ray.x) * tan(angle) + (*game)->player_y;
	ray.y_diff = -ray.x_diff * tan(angle);
	if (door)
		return (find_dist_d(game, &ray, angle, dist));
	return (find_dist(game, &ray, angle, dist));
}
