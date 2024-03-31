/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkozlova <vkozlova@student.42wolfsburg.d>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 19:08:38 by vkozlova          #+#    #+#             */
/*   Updated: 2024/02/22 19:08:38 by vkozlova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3D.h"

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	int	offset;

	offset = (img->line_len * y) + (x * (img->bits_per_pixel / 8));
	*((unsigned int *)(offset + img->img_pixels_ptr)) = color;
}

void	draw_direction(t_game **game)
{
	int	i;
	int	y;
	int	x;

	i = 0;
	while (i < 10)
	{
		y = (*game)->player_y / CUBE * CELL_SIZE + CELL_SIZE / 2
			- sin((*game)->player_angle) * i;
		x = (*game)->player_x / CUBE * CELL_SIZE + CELL_SIZE / 2
			+ cos((*game)->player_angle) * i;
		my_mlx_pixel_put((*game)->img, x, y, PLAYER);
		i++;
	}
}

void	draw_player(t_game **game)
{
	int	y_start;
	int	y_end;
	int	x_start;
	int	x_end;

	y_start = (*game)->player_y / CUBE * CELL_SIZE;
	y_end = (*game)->player_y / CUBE * CELL_SIZE + CELL_SIZE - 1;
	x_start = (*game)->player_x / CUBE * CELL_SIZE;
	while (y_end >= y_start)
	{
		x_end = (*game)->player_x / CUBE * CELL_SIZE + CELL_SIZE - 1;
		while (x_end >= x_start)
		{
			my_mlx_pixel_put((*game)->img, x_end, y_end, PLAYER);
			x_end--;
		}
		y_end--;
	}
	draw_direction(game);
}

void	draw_cell(t_game **game, int x, int y)
{
	int	y_end;
	int	x_end;
	int	x_start;
	int	y_start;

	y_end = y * CELL_SIZE + CELL_SIZE - 1;
	x_end = x * CELL_SIZE + CELL_SIZE - 1;
	y_start = y * CELL_SIZE;
	while (y_start < y_end)
	{
		x_start = x * CELL_SIZE;
		while (x_start < x_end)
		{
			my_mlx_pixel_put((*game)->img, x_start, y_start, MINIMAP_COLOR);
			x_start++;
		}
		y_start++;
	}
}

void	draw_map(t_game **game)
{
	int	x;
	int	y;

	y = 0;
	while (y < (*game)->map->length)
	{
		x = 0;
		while (x < (*game)->map_width)
		{
			if ((*game)->map->map[y][x] == '1')
				draw_cell(game, x, y);
			x++;
		}
		y++;
	}
	draw_player(game);
}
