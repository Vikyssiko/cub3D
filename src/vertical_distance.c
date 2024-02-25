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

	x_coordinate = (int)((*game)->player_x / CUBE);
	if (angle < PI / 2 || angle >= PI * 1.5)
		return (x_coordinate * CUBE + CUBE);
	return (x_coordinate * CUBE - 1);
}

int	find_x_diff_vert(double angle)
{
	if (angle < PI / 2 || angle >= PI * 1.5)
		return (CUBE);
	return (-CUBE);
}

double	find_y_diff_vert(double angle)
{
	double	diff;

	diff = CUBE * tan(angle);
	if (angle < PI)
		return (-diff);
	return (diff);
}

t_dist 	find_dist(t_game **game, t_ray *ray, double angle, t_dist dist)
{
//	double	dist;
//	t_dist	dist;

	dist.dist = 2147483648;
	while (1)
	{
//		printf("here\n");
		if (((int)(ray->y) >> BITS) < 0 || ((int)(ray->y) >> BITS) >= (*game)->map->length
			|| (*game)->map->map[(int)(ray->y) >> BITS][(int)(ray->x) >> BITS] == '1'
			|| (*game)->map->map[(int)(ray->y) >> BITS][(int)(ray->x) >> BITS] == ' ')
		{
			double distance = cos(angle) * (ray->x - (*game)->player_x) - sin(angle) * (ray->y - (*game)->player_y);
//			if (distance < 0)
//				printf("%f\n", distance);
//			while (distance < 0 || distance > 10000)
//			{
//				angle -= 0.001745;
//				distance = cos(angle) * (ray->x - (*game)->player_x) - sin(angle) * (ray->y - (*game)->player_y);
//			}

//			if (distance < -1)
//				distance = -distance;
			dist.dist = find_min(dist.dist, distance);
//			dist.dist = find_min(dist.dist, cos(angle) * (ray->x - (*game)->player_x) - sin(angle) * (ray->y - (*game)->player_y));
//			if (dist.dist < 0)
//				printf("%f\n", dist.dist);
			break ;
		}
		ray->x += ray->x_diff;
		ray->y += ray->y_diff;
	}
//	dist.color = 0xFF00FF;
	return (dist);
}

t_dist 	vertical_hit_dist(t_game **game, double angle)
{
	t_ray	ray;
	double	tang;
	t_dist	dist;

	if ((angle > M_PI_2 - 0.009 && angle < M_PI_2 + 0.009)
		|| (angle > M_PI_2 * 3 - 0.01745 && angle < M_PI_2 * 3 + 0.01745))
		angle += 0.02;
//	else if (angle > M_PI_2 * 3 - 0.01745 && angle < M_PI_2 * 3 + 0.01745)
//		angle -= 0.02;
	tang = tan(angle);
//		tang = 75.204309;
//	else if (tang < -100)
//		tang = -75.204309;
//	else if (tang > 100)
//		tang =
	dist.color = 0x03CEA4;
//	dist.texture = (*game)->west_img;
	dist.direction = 'E';
	if (cos(angle) > 0.001) //right
	{
		ray.x = (((int)(*game)->player_x >> BITS) << BITS) + CUBE;
		ray.x_diff = CUBE;
		ray.y = ((*game)->player_x - ray.x) * tang + (*game)->player_y;
		ray.y_diff = -ray.x_diff * tang;
//        dist.texture = (*game)->west_img;
//		dist.direction = 'E';
	}
	else if (cos(angle) < -0.001) //left
	{
		ray.x = (((int)(*game)->player_x >> BITS) << BITS) - 0.0001;
		ray.x_diff = -CUBE;
		ray.y = ((*game)->player_x - ray.x) * tang + (*game)->player_y;
		ray.y_diff = -ray.x_diff * tang;
		dist.color = 0xE5F8F4;
//        dist.texture = (*game)->east_img;
		dist.direction = 'W';
	}
	else
	{
//		printf("in else\n");
		ray.x = (*game)->player_x;
		ray.y = (*game)->player_y;
	}
//	printf("vertical: %f\n",find_dist(game, &ray, angle));
	return (find_dist(game, &ray, angle, dist));
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
