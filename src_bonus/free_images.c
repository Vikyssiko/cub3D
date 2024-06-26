/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkozlova <vkozlova@student.42wolfsburg.d>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 23:03:01 by vkozlova          #+#    #+#             */
/*   Updated: 2024/03/30 23:03:01 by vkozlova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3D.h"

void	free_img(t_img *img, t_game **game)
{
	if (img)
	{
		mlx_destroy_image((*game)->mlx_ptr, img->img_ptr);
		free(img);
	}
}

void	free_images(t_game **game)
{
	free_img((*game)->north_img, game);
	free_img((*game)->south_img, game);
	free_img((*game)->west_img, game);
	free_img((*game)->east_img, game);
	if ((*game)->anim)
	{
		free_img((*game)->anim[1], game);
		free_img((*game)->anim[2], game);
		free_img((*game)->anim[3], game);
		free_img((*game)->anim[4], game);
		free_img((*game)->anim[5], game);
		free((*game)->anim);
	}
	free_img((*game)->door_img, game);
	free_img((*game)->open_door_img, game);
}

void	free_array_ptr(t_game **game)
{
	int	i;

	i = 0;
	free((*game)->n_pixels);
	free((*game)->s_pixels);
	free((*game)->w_pixels);
	free((*game)->e_pixels);
	while (i < 7)
		free((*game)->doors_pixels[i++]);
	free((*game)->doors_pixels);
}

void	free_pixel_arrays(t_game **game)
{
	int	y;
	int	i;

	y = 0;
	while (y < TEXTURE_SIZE + 1)
	{
		i = 0;
		free((*game)->n_pixels[y]);
		free((*game)->s_pixels[y]);
		free((*game)->w_pixels[y]);
		free((*game)->e_pixels[y]);
		while (i < 7)
			free((*game)->doors_pixels[i++][y]);
		y++;
	}
	free_array_ptr(game);
}
