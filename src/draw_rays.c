/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_rays.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkozlova <vkozlova@student.42wolfsburg.d>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 14:35:17 by vkozlova          #+#    #+#             */
/*   Updated: 2024/03/31 15:08:24 by vkozlova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3D.h"

int	**init_pixels_array(t_dist *dist, t_game **game)
{
	int		**array;

	array = NULL;
	if (dist->direction == 'N')
		array = (*game)->n_pixels;
	else if (dist->direction == 'S')
		array = (*game)->s_pixels;
	else if (dist->direction == 'W')
		array = (*game)->w_pixels;
	else if (dist->direction == 'E')
		array = (*game)->e_pixels;
	return (array);
}

void	draw_line(int **array, t_game **game, t_dist *dist, int x)
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
		my_mlx_pixel_put((*game)->img, x, y_start, color);
		texture_pos += TEXTURE_SIZE / line_height;
		y_start++;
	}
}

void	draw_rays(t_game **game)
{
	double	ray_angle;
	t_dist	dist;
	int		x;
	int		**array;

	x = 0;
	ray_angle = fix_angle((*game)->player_angle + M_PI_2 / 3);
	while (x < MAP_WIDTH)
	{
		dist = find_min_dist(vertical_hit_dist(game, ray_angle, 0),
				horizontal_hit_dist(game, ray_angle, 0));
		dist.dist *= cos(fix_angle((*game)->player_angle - ray_angle));
		if (dist.dist < 0)
		{
			ray_angle = fix_angle(ray_angle - 0.0002);
			continue ;
		}
		array = init_pixels_array(&dist, game);
		draw_line(array, game, &dist, x);
		x += 1;
		ray_angle = fix_angle(ray_angle - 0.00058177);
	}
}
