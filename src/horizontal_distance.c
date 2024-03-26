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

t_dist	find_h_dist(t_game **game, t_ray *ray, double angle, t_dist dist)
{
	double	distance;
	char	**map;

	dist.dist = 2147483648;
	map = (*game)->map->map;
	while (1)
	{
		if (((int)(ray->x) >> BITS) < 0
			|| ((int)(ray->x) >> BITS) >= (*game)->map_width
			|| map[(int)(ray->y) >> BITS][(int)(ray->x) >> BITS] == '1'
			|| map[(int)(ray->y) >> BITS][(int)(ray->x) >> BITS] == ' ')
		{
			distance = cos(angle) * (ray->x - (*game)->player_x)
				- sin(angle) * (ray->y - (*game)->player_y);
			dist.dist = find_min(dist.dist, distance);
			dist.hit_point = ray->x;
			break ;
		}
		else if (map[(int)(ray->y) >> BITS][(int)(ray->x) >> BITS] == 'D')
		{
			distance = cos(angle) * (ray->x - (*game)->player_x + ray->x_diff / 2)
					   - sin(angle) * (ray->y - (*game)->player_y + ray->y_diff / 2);
			dist.dist = find_min(dist.dist, distance);
			dist.direction = 'D';
			dist.hit_point = ray->x + ray->x_diff / 2;
			break ;
		}
		ray->x += ray->x_diff;
		ray->y += ray->y_diff;
	}
//	dist.hit_point = ray->x;
	return (dist);
}

t_dist	horizontal_hit_dist(t_game **game, double angle)
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
	else if (sin(angle) < -0.001)
	{
		ray.y = (((int)(*game)->player_y >> BITS) << BITS) + CUBE;
		ray.y_diff = CUBE;
		ray.x_diff = -ray.y_diff * tang;
		ray.x = ((*game)->player_y - ray.y) * tang + (*game)->player_x;
		dist.direction = 'S';
	}
	else
	{
		ray.x_diff = CUBE * sin(0.0001);
		ray.y_diff = 0;
		ray.x = (*game)->player_x;
		ray.y = (*game)->player_y;
	}
	return (find_h_dist(game, &ray, angle, dist));
}
