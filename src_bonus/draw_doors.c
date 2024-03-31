/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_doors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkozlova <vkozlova@student.42wolfsburg.d>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 15:08:57 by vkozlova          #+#    #+#             */
/*   Updated: 2024/03/31 15:08:57 by vkozlova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3D.h"

void	draw_door_line(int **array, t_game **game, t_dist *dist, int x)
{
	double	texture_pos;
	double	y_start;
	int		y_end;
	double	line_height;
	int		color;

	line_height = CUBE * (MAP_WIDTH / 2 / tan(M_PI_2 / 3)) / dist->dist;
	y_start = MAP_HEIGHT / 2 - (line_height / 2);
	y_end = MAP_HEIGHT / 2 + (line_height / 2);
	if (y_start < 0)
		y_start = 0;
	if (y_end > MAP_HEIGHT)
		y_end = MAP_HEIGHT - 1;
	texture_pos = (y_start - MAP_HEIGHT / 2 + line_height / 2)
		* (TEXTURE_SIZE / line_height);
	if (texture_pos < 0)
		texture_pos = 0.0;
	while (y_start < y_end)
	{
		color = array[(int)(texture_pos)][(int)dist->hit_point % TEXTURE_SIZE];
		if (color != 0)
			my_mlx_pixel_put((*game)->img, x, y_start, color);
		texture_pos += TEXTURE_SIZE / line_height;
		y_start++;
	}
}

int	is_dist_negative(double *ray_angle, double dist)
{
	if (dist < 0)
	{
		*ray_angle = fix_angle(*ray_angle - 0.0002);
		return (1);
	}
	return (0);
}

int	**init_door_pixels_array(t_game **game)
{
	if ((*game)->door_open == 1)
		return ((*game)->od_pixels);
	return ((*game)->d_pixels);
}

void	draw_doors(t_game **game)
{
	double	ray_angle;
	t_dist	dist;
	int		x;
	int		**array;

	ray_angle = fix_angle((*game)->player_angle + M_PI_2 / 3);
	x = 0;
	while (x < MAP_WIDTH)
	{
		dist = find_min_dist(vertical_hit_dist(game, ray_angle, 1),
				horizontal_hit_dist(game, ray_angle, 1));
		if (is_dist_negative(&ray_angle, dist.dist))
			continue ;
		if (dist.direction == 'D')
		{
			dist.dist *= cos(fix_angle((*game)->player_angle - ray_angle));
			if (is_dist_negative(&ray_angle, dist.dist))
				continue ;
			array = init_door_pixels_array(game);
			draw_door_line(array, game, &dist, x);
		}
		x++;
		ray_angle = fix_angle(ray_angle - 0.00058177);
	}
}
