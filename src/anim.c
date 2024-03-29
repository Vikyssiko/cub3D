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

void 	create_anim_array(t_game **game)
{
	t_img **array = malloc(sizeof(t_img *) * 4);

	array[0] = (*game)->door_img;
	array[1] = malloc(sizeof(t_img));
	*(array[1]) = create_door_texture(game, "./textures/door1.xpm");
	array[2] = malloc(sizeof(t_img));
	*(array[2]) = create_door_texture(game, "./textures/door2.xpm");
	array[3] = (*game)->open_door_img;
	(*game)->anim = array;
}

void 	create_anim_pixels_array(t_game **game)
{
	int ***array;
	int	y;
	int	x;

	y = 0;
	array = malloc(sizeof(int **) * 4);
	array[0] = (*game)->d_pixels;
	array[1] = malloc(sizeof(int *) * (TEXTURE_SIZE) + 1);
	array[2] = malloc(sizeof(int *) * (TEXTURE_SIZE) + 1);
	array[3] = (*game)->od_pixels;
	while (y < TEXTURE_SIZE + 1)
	{
		x = 0;
		array[1][y] = malloc(sizeof(int) * TEXTURE_SIZE + 1);
		array[2][y] = malloc(sizeof(int) * TEXTURE_SIZE + 1);
		while (x < TEXTURE_SIZE)
		{
			array[1][y][x] = get_pixel_color(x, y,
					(*game)->door_img->img_pixels_ptr, (*game)->anim[1]);
			array[2][y][x] = get_pixel_color(x, y,
							(*game)->door_img->img_pixels_ptr, (*game)->anim[2]);
			x++;
		}
		y++;
	}
	(*game)->doors_pixels = array;
}
