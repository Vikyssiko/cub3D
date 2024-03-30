/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel_array.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkozlova <vkozlova@student.42wolfsburg.d>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 19:08:38 by vkozlova          #+#    #+#             */
/*   Updated: 2024/02/22 19:08:38 by vkozlova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3D.h"

int	get_pixel_color(int x, int y, char *data_addr, t_img *img)
{
	int	offset;
	int	red_offset;
	int	green_offset;
	int	blue_offset;

	offset = (y * img->line_len) + (x * (img->bits_per_pixel / 8));
	if (img->endian == 0)
	{
		red_offset = 0;
		green_offset = 1;
		blue_offset = 2;
	}
	else
	{
		red_offset = 2;
		green_offset = 1;
		blue_offset = 0;
	}
	return (((unsigned char)data_addr[(unsigned int)offset + blue_offset] << 16)
		| ((unsigned char)data_addr[(unsigned int)offset + green_offset] << 8)
		| (unsigned char)data_addr[(unsigned int)offset + red_offset]);
}

void	put_color(t_game **game, int x, int y)
{
	(*game)->n_pixels[y][x] = get_pixel_color(x, y,
			(*game)->north_img->img_pixels_ptr, (*game)->north_img);
	(*game)->s_pixels[y][x] = get_pixel_color(x, y,
			(*game)->south_img->img_pixels_ptr, (*game)->south_img);
	(*game)->w_pixels[y][x] = get_pixel_color(x, y,
			(*game)->west_img->img_pixels_ptr, (*game)->west_img);
	(*game)->e_pixels[y][x] = get_pixel_color(x, y,
			(*game)->east_img->img_pixels_ptr, (*game)->east_img);
	(*game)->d_pixels[y][x] = get_pixel_color(x, y,
			(*game)->door_img->img_pixels_ptr, (*game)->door_img);
	(*game)->od_pixels[y][x] = get_pixel_color(x, y,
			(*game)->open_door_img->img_pixels_ptr, (*game)->open_door_img);
}

void	create_array_of_pixels(t_game **game)
{
	int	y;
	int	x;

	y = 0;
	(*game)->w_pixels = malloc(sizeof(int *) * (TEXTURE_SIZE + 1));
	(*game)->e_pixels = malloc(sizeof(int *) * (TEXTURE_SIZE + 1));
	(*game)->s_pixels = malloc(sizeof(int *) * (TEXTURE_SIZE + 1));
	(*game)->n_pixels = malloc(sizeof(int *) * (TEXTURE_SIZE + 1));
	(*game)->d_pixels = malloc(sizeof(int *) * (TEXTURE_SIZE + 1));
	(*game)->od_pixels = malloc(sizeof(int *) * (TEXTURE_SIZE + 1));
	while (y < TEXTURE_SIZE + 1)
	{
		x = 0;
		(*game)->n_pixels[y] = malloc(sizeof(int) * (TEXTURE_SIZE + 1));
		(*game)->s_pixels[y] = malloc(sizeof(int) * (TEXTURE_SIZE + 1));
		(*game)->w_pixels[y] = malloc(sizeof(int) * (TEXTURE_SIZE + 1));
		(*game)->e_pixels[y] = malloc(sizeof(int) * (TEXTURE_SIZE + 1));
		(*game)->d_pixels[y] = malloc(sizeof(int) * (TEXTURE_SIZE + 1));
		(*game)->od_pixels[y] = malloc(sizeof(int) * (TEXTURE_SIZE + 1));
		while (x < TEXTURE_SIZE)
		{
			put_color(game, x, y);
			x++;
		}
		y++;
	}
}
