/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkozlova <vkozlova@student.42wolfsburg.d>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 19:08:38 by vkozlova          #+#    #+#             */
/*   Updated: 2024/02/22 19:08:38 by vkozlova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3D.h"

void	create_north_texture_img(t_game **game)
{
	t_img	img;
	int		size;

	size = TEXTURE_SIZE;
	img.img_ptr = mlx_xpm_file_to_image((*game)->mlx_ptr, (*game)->north, &size, &size);
	free((*game)->north);
	if (!img.img_ptr)
		clean_and_exit("Check north texture", game);
	img.img_pixels_ptr = mlx_get_data_addr(img.img_ptr, &img.bits_per_pixel, &img.line_len,
										   &img.endian);
	if (!img.img_pixels_ptr)
		clean_and_exit("Check north texture", game);
	(*game)->north_img = malloc(sizeof(t_img));
	*((*game)->north_img) = img;
}

void	create_south_texture_img(t_game **game)
{
	t_img	img;
	int		size;

	size = TEXTURE_SIZE;
	img.img_ptr = mlx_xpm_file_to_image((*game)->mlx_ptr, (*game)->south, &size, &size);
	free((*game)->south);
	if (!img.img_ptr)
		clean_and_exit("Check south texture", game);
	img.img_pixels_ptr = mlx_get_data_addr(img.img_ptr, &img.bits_per_pixel, &img.line_len,
										   &img.endian);
	if (!img.img_pixels_ptr)
		clean_and_exit("Check south texture", game);
	(*game)->south_img = malloc(sizeof(t_img));
	*((*game)->south_img) = img;
}

void	create_west_texture_img(t_game **game)
{
	t_img	img;
	int		size;

	size = TEXTURE_SIZE;
	img.img_ptr = mlx_xpm_file_to_image((*game)->mlx_ptr, (*game)->west, &size, &size);
	free((*game)->west);
	if (!img.img_ptr)
		clean_and_exit("Check west texture", game);
	img.img_pixels_ptr = mlx_get_data_addr(img.img_ptr, &img.bits_per_pixel, &img.line_len,
										   &img.endian);
	if (!img.img_pixels_ptr)
		clean_and_exit("Check west texture", game);
	(*game)->west_img = malloc(sizeof(t_img));
	*((*game)->west_img) = img;
}

void	create_east_texture_img(t_game **game)
{
	t_img	img;
	int		size;

	size = TEXTURE_SIZE;
	img.img_ptr = mlx_xpm_file_to_image((*game)->mlx_ptr, (*game)->east, &size, &size);
	free((*game)->east);
	if (!img.img_ptr)
		clean_and_exit("Check east texture", game);
	img.img_pixels_ptr = mlx_get_data_addr(img.img_ptr, &img.bits_per_pixel, &img.line_len,
										   &img.endian);
	if (!img.img_pixels_ptr)
		clean_and_exit("Check east texture", game);
	(*game)->east_img = malloc(sizeof(t_img));
	*((*game)->east_img) = img;
}

void	init_textures(t_game **game)
{
	create_north_texture_img(game);
	create_south_texture_img(game);
	create_west_texture_img(game);
	create_east_texture_img(game);
	create_array_of_pixels(game);
}
