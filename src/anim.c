/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkozlova <vkozlova@student.42wolfsburg.d>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 23:07:15 by vkozlova          #+#    #+#             */
/*   Updated: 2024/02/12 17:28:10 by vkozlova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3D.h"

void	create_anim_array(t_game **game)
{
	t_img	**array;

	array = malloc(sizeof(t_img *) * 7);
	array[0] = (*game)->door_img;
	array[1] = malloc(sizeof(t_img));
	*(array[1]) = create_door_texture(game, "./textures/door1.xpm");
	array[2] = malloc(sizeof(t_img));
	*(array[2]) = create_door_texture(game, "./textures/door2.xpm");
	array[3] = malloc(sizeof(t_img));
	*(array[3]) = create_door_texture(game, "./textures/door3.xpm");
	array[4] = malloc(sizeof(t_img));
	*(array[4]) = create_door_texture(game, "./textures/door4.xpm");
	array[5] = malloc(sizeof(t_img));
	*(array[5]) = create_door_texture(game, "./textures/door5.xpm");
	array[6] = (*game)->open_door_img;
	(*game)->anim = array;
}

void	create_doors_pixels(t_game **game)
{
	(*game)->doors_pixels = malloc(sizeof(int **) * 7);
	(*game)->doors_pixels[0] = (*game)->d_pixels;
	(*game)->doors_pixels[1] = malloc(sizeof(int *) * (TEXTURE_SIZE + 1));
	(*game)->doors_pixels[2] = malloc(sizeof(int *) * (TEXTURE_SIZE + 1));
	(*game)->doors_pixels[3] = malloc(sizeof(int *) * (TEXTURE_SIZE + 1));
	(*game)->doors_pixels[4] = malloc(sizeof(int *) * (TEXTURE_SIZE + 1));
	(*game)->doors_pixels[5] = malloc(sizeof(int *) * (TEXTURE_SIZE + 1));
	(*game)->doors_pixels[6] = (*game)->od_pixels;
}

void	put_pixel(t_game **game, int y, int x)
{
	(*game)->doors_pixels[1][y][x] = get_pixel_color(x, y,
			(*game)->anim[1]->img_pixels_ptr, (*game)->anim[1]);
	(*game)->doors_pixels[2][y][x] = get_pixel_color(x, y,
			(*game)->anim[2]->img_pixels_ptr, (*game)->anim[2]);
	(*game)->doors_pixels[3][y][x] = get_pixel_color(x, y,
			(*game)->anim[3]->img_pixels_ptr, (*game)->anim[3]);
	(*game)->doors_pixels[4][y][x] = get_pixel_color(x, y,
			(*game)->anim[4]->img_pixels_ptr, (*game)->anim[4]);
	(*game)->doors_pixels[5][y][x] = get_pixel_color(x, y,
			(*game)->anim[5]->img_pixels_ptr, (*game)->anim[5]);
}

void	create_anim_pixels_array(t_game **game)
{
	int	y;
	int	x;

	y = 0;
	create_doors_pixels(game);
	while (y < TEXTURE_SIZE + 1)
	{
		x = 0;
		(*game)->doors_pixels[1][y] = malloc(sizeof(int) * (TEXTURE_SIZE + 1));
		(*game)->doors_pixels[2][y] = malloc(sizeof(int) * (TEXTURE_SIZE + 1));
		(*game)->doors_pixels[3][y] = malloc(sizeof(int) * (TEXTURE_SIZE + 1));
		(*game)->doors_pixels[4][y] = malloc(sizeof(int) * (TEXTURE_SIZE + 1));
		(*game)->doors_pixels[5][y] = malloc(sizeof(int) * (TEXTURE_SIZE + 1));
		while (x < TEXTURE_SIZE)
		{
			put_pixel(game, y, x);
			x++;
		}
		y++;
	}
}
