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

	y_coordinate = (int)((*game)->player_y / CUBE);
	if (angle < PI)
		return (y_coordinate * CUBE - 1);
	return (y_coordinate * CUBE + CUBE);
}

int	find_y_diff(double angle)
{
	if (angle < PI)
		return (-CUBE);
	return (CUBE);
}

int	find_x_diff(double angle)
{
	double	diff;

	diff = CUBE / tan(angle);
	if (angle >= PI / 2 && angle < PI * 1.5)
		return (-diff);
	return (diff);
}

t_dist 	horizontal_hit_dist(t_game **game, double angle)
{
	t_ray	ray;
	t_dist 	dist;
	double	tang;

	tang = 1.0 / tan(angle);
	dist.dist = 2147483648;
	dist.direction = 'N';
	if (sin(angle) > 0.001)
	{
		ray.y = (((int)(*game)->player_y >> BITS) << BITS) - 0.0001;
		ray.y_diff = -CUBE;
		ray.x = ((*game)->player_y - ray.y) * tang + (*game)->player_x;
		ray.x_diff = -ray.y_diff * tang;
	}
	else if (sin(angle) < -0.001)
	{
		ray.y = (((int)(*game)->player_y >> BITS) << BITS) + CUBE;
		ray.y_diff = CUBE;
		ray.x = ((*game)->player_y - ray.y) * tang + (*game)->player_x;
		ray.x_diff = -ray.y_diff * tang;
		dist.direction = 'S';
	}
	else
	{
		ray.x = (*game)->player_x;
		ray.y = (*game)->player_y;
	}
	while (1)
	{
		if (((int)(ray.x) >> BITS) < 0 || ((int)(ray.x) >> BITS) >= (*game)->map_width
			|| (*game)->map->map[(int)(ray.y) >> BITS][(int)(ray.x) >> BITS] == '1'
			|| (*game)->map->map[(int)(ray.y) >> BITS][(int)(ray.x) >> BITS] == ' ')
		{
			double distance = cos(angle) * (ray.x - (*game)->player_x) - sin(angle) * (ray.y - (*game)->player_y);
			dist.dist = find_min(dist.dist, distance);
			break ;
		}
		ray.x += ray.x_diff;
		ray.y += ray.y_diff;
	}
	return (dist);
}
