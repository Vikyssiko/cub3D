/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkozlova <vkozlova@student.42wolfsburg.d>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 15:49:05 by vkozlova          #+#    #+#             */
/*   Updated: 2024/03/28 15:49:05 by vkozlova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3D.h"

t_img	create_door_texture(t_game **game, char *texture)
{
	t_img	img;
	int		size;

	size = TEXTURE_SIZE;
	img.img_ptr = mlx_xpm_file_to_image((*game)->mlx_ptr,
			texture, &size, &size);
	if (!img.img_ptr)
		clean_and_exit("Check door texture", game);
	img.img_pixels_ptr = mlx_get_data_addr(img.img_ptr,
			&img.bits_per_pixel, &img.line_len, &img.endian);
	if (!img.img_pixels_ptr)
		clean_and_exit("Check door texture", game);
	return (img);
}

void	create_door_texture_img(t_game **game)
{
	t_img	img;
	int		size;

	size = TEXTURE_SIZE;
	img.img_ptr = mlx_xpm_file_to_image((*game)->mlx_ptr,
			"./textures/door.xpm", &size, &size);
	if (!img.img_ptr)
		clean_and_exit("Check door texture", game);
	img.img_pixels_ptr = mlx_get_data_addr(img.img_ptr,
			&img.bits_per_pixel, &img.line_len, &img.endian);
	if (!img.img_pixels_ptr)
		clean_and_exit("Check door texture", game);
	(*game)->door_img = malloc(sizeof(t_img));
	*((*game)->door_img) = img;
}

void	create_open_door_texture_img(t_game **game)
{
	t_img	img;
	int		size;

	size = TEXTURE_SIZE;
	img.img_ptr = mlx_xpm_file_to_image((*game)->mlx_ptr,
			"./textures/open_door.xpm", &size, &size);
	if (!img.img_ptr)
		clean_and_exit("Check open door texture", game);
	img.img_pixels_ptr = mlx_get_data_addr(img.img_ptr,
			&img.bits_per_pixel, &img.line_len, &img.endian);
	if (!img.img_pixels_ptr)
		clean_and_exit("Check open door texture", game);
	(*game)->open_door_img = malloc(sizeof(t_img));
	*((*game)->open_door_img) = img;
}
