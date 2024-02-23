/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel_array.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkozlova <vkozlova@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 11:37:14 by vkozlova          #+#    #+#             */
/*   Updated: 2024/02/23 11:37:14 by vkozlova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3D.h"

int get_pixel_color(int x, int y, char *data_addr, t_img *img) {
	// Calculate the offset of the pixel in the image data
	int offset = (y * img->line_len) + (x * (img->bits_per_pixel / 8));

	// Depending on the endian format, adjust the byte order
	int red_offset, green_offset, blue_offset;

	if (img->endian == 0) {  // Little-endian
		red_offset = 0;
		green_offset = 1;
		blue_offset = 2;
	} else {  // Big-endian
		red_offset = 2;
		green_offset = 1;
		blue_offset = 0;
	}

	// Retrieve color components
	int red = (unsigned char)data_addr[(unsigned int)offset + red_offset];
	int green = (unsigned char)data_addr[(unsigned int)offset + green_offset];
	int blue = (unsigned char)data_addr[(unsigned int)offset + blue_offset];

	// Assuming 8 bits per channel, you might need to scale the values based on the actual image format
	return (blue << 16) | (green << 8) | red;
}

void	create_array_of_pixels(t_game **game)
{
	int	y;
	int	x;

	x = 0;
	y = 0;
	(*game)->n_pixels = malloc(sizeof(int) * (TEXTURE_SIZE * TEXTURE_SIZE) + 1);
	(*game)->s_pixels = malloc(sizeof(int) * (TEXTURE_SIZE * TEXTURE_SIZE) + 1);
	(*game)->w_pixels = malloc(sizeof(int) * (TEXTURE_SIZE * TEXTURE_SIZE) + 1);
	(*game)->e_pixels = malloc(sizeof(int) * (TEXTURE_SIZE * TEXTURE_SIZE) + 1);
	while (y < TEXTURE_SIZE)
	{
		x = 0;
		while (x < TEXTURE_SIZE)
		{
			(*game)->n_pixels[y * TEXTURE_SIZE + x] = get_pixel_color(x, y, (*game)->north_img->img_pixels_ptr, (*game)->north_img);
			(*game)->s_pixels[y * TEXTURE_SIZE + x] = get_pixel_color(x, y, (*game)->south_img->img_pixels_ptr, (*game)->south_img);
			(*game)->w_pixels[y * TEXTURE_SIZE + x] = get_pixel_color(x, y, (*game)->west_img->img_pixels_ptr, (*game)->west_img);
			(*game)->e_pixels[y * TEXTURE_SIZE + x] = get_pixel_color(x, y, (*game)->east_img->img_pixels_ptr, (*game)->east_img);
			x++;
		}
		y++;
	}
//	(*game)->n_pixels + TEXTURE_SIZE * TEXTURE_SIZE = NULL;
//	(*game)->s_pixels[TEXTURE_SIZE * TEXTURE_SIZE] = NULL;
//	(*game)->w_pixels[TEXTURE_SIZE * TEXTURE_SIZE] = NULL;
//	(*game)->e_pixels[TEXTURE_SIZE * TEXTURE_SIZE] = NULL;
}

//int	*create_array_of_pixels_south(t_game **game)
//{
//	int	y;
//	int	x;
//
//	x = 0;
//	y = 0;
//	(*game)->n_pixels = malloc(sizeof(int) * TEXTURE_SIZE * TEXTURE_SIZE);
//	while (y < TEXTURE_SIZE)
//	{
//		while (x < TEXTURE_SIZE)
//		{
//			(*game)->n_pixels[y * TEXTURE_SIZE + x] = get_pixel_color(x, y, (*game)->south_img->img_pixels_ptr, (*game)->south_img);
//			x++;
//		}
//		y++;
//	}
//}
//
//int	*create_array_of_pixels_west(t_game **game)
//{
//	int	y;
//	int	x;
//
//	x = 0;
//	y = 0;
//	(*game)->n_pixels = malloc(sizeof(int) * TEXTURE_SIZE * TEXTURE_SIZE);
//	while (y < TEXTURE_SIZE)
//	{
//		while (x < TEXTURE_SIZE)
//		{
//			(*game)->n_pixels[y * TEXTURE_SIZE + x] = get_pixel_color(x, y, (*game)->west_img->img_pixels_ptr, (*game)->west_img);
//			x++;
//		}
//		y++;
//	}
//}
//
//int	*create_array_of_pixels_east(t_game **game)
//{
//	int	y;
//	int	x;
//
//	x = 0;
//	y = 0;
//	(*game)->n_pixels = malloc(sizeof(int) * TEXTURE_SIZE * TEXTURE_SIZE);
//	while (y < TEXTURE_SIZE)
//	{
//		while (x < TEXTURE_SIZE)
//		{
//			(*game)->n_pixels[y * TEXTURE_SIZE + x] = get_pixel_color(x, y, (*game)->east_img->img_pixels_ptr, (*game)->east_img);
//			x++;
//		}
//		y++;
//	}
//}
