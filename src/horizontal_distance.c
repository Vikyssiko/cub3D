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

int	next_is_not_floor(t_game **game, t_ray *ray)
{
	char	**map;

	map = (*game)->map->map;
	if (((int)(ray->x) >> BITS) < 0
		|| ((int)(ray->x) >> BITS) >= (*game)->map_width
		|| map[(int)(ray->y) >> BITS][(int)(ray->x) >> BITS] == '1'
		|| map[(int)(ray->y) >> BITS][(int)(ray->x) >> BITS] == ' ')
		return (1);
	return (0);
}

t_dist	find_h_dist(t_game **game, t_ray *ray, double angle, t_dist dist)
{
	double	distance;

	dist.dist = 2147483648;
	while (1)
	{
		if (next_is_not_floor(game, ray))
		{
			distance = cos(angle) * (ray->x - (*game)->player_x)
				- sin(angle) * (ray->y - (*game)->player_y);
			dist.dist = find_min(dist.dist, distance);
			dist.hit_point = ray->x;
			break ;
		}
		ray->x += ray->x_diff;
		ray->y += ray->y_diff;
	}
	return (dist);
}

int	hit_door(t_game **game, t_ray *ray, t_dist *dist)
{
	char	**map;

	map = (*game)->map->map;
	if (((int)(ray->x) >> BITS) < 0
		|| ((int)(ray->x) >> BITS) >= (*game)->map_width
		|| map[(int)(ray->y) >> BITS][(int)(ray->x) >> BITS] == 'D')
	{
		dist->direction = 'D';
		dist->hit_point = ray->x + ray->x_diff / 2;
		return (1);
	}
	return (0);
}

t_dist	find_h_dist_d(t_game **game, t_ray *ray, double angle, t_dist dist)
{
	double	distance;

	dist.dist = 2147483648;
	while (1)
	{
		if (hit_door(game, ray, &dist))
		{
			distance = cos(angle) * (ray->x - (*game)->player_x
					+ ray->x_diff / 2) - sin(angle) * (ray->y
					- (*game)->player_y + ray->y_diff / 2);
			dist.dist = find_min(dist.dist, distance);
			break ;
		}
		if (next_is_not_floor(game, ray))
		{
			distance = cos(angle) * (ray->x - (*game)->player_x)
				- sin(angle) * (ray->y - (*game)->player_y);
			dist.dist = find_min(dist.dist, distance);
			dist.hit_point = ray->x;
			break ;
		}
		ray->x += ray->x_diff;
		ray->y += ray->y_diff;
	}
	return (dist);
}

t_dist	horizontal_hit_dist(t_game **game, double angle, int door)
{
	t_ray	ray;
	t_dist	dist;
	double	tang;

	tang = 1.0 / tan(angle);
	dist.direction = 'N';
	if (sin(angle) > 0.001)
	{
		ray.y = (((int)(*game)->player_y >> BITS) << BITS) - 0.0001;
		ray.y_diff = -CUBE;
		ray.x_diff = -ray.y_diff * tang;
		ray.x = ((*game)->player_y - ray.y) * tang + (*game)->player_x;
	}
	else
	{
		ray.y = (((int)(*game)->player_y >> BITS) << BITS) + CUBE;
		ray.y_diff = CUBE;
		ray.x_diff = -ray.y_diff * tang;
		ray.x = ((*game)->player_y - ray.y) * tang + (*game)->player_x;
		dist.direction = 'S';
	}
	if (door)
		return (find_h_dist_d(game, &ray, angle, dist));
	return (find_h_dist(game, &ray, angle, dist));
}
