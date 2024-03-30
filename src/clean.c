/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkozlova <vkozlova@student.42wolfsburg.d>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 14:24:29 by vkozlova          #+#    #+#             */
/*   Updated: 2024/03/30 14:24:29 by vkozlova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3D.h"

void	clean_instructions(char **instructions)
{
	free(instructions[0]);
	free(instructions[1]);
	free(instructions);
}

void	free_string_array(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

void	free_stack(t_stack **stack)
{
	t_stack	*tmp;

	tmp = NULL;
	if (!(*stack))
		return ;
	while (*stack)
	{
		tmp = (*stack)->next;
		free((*stack)->str);
		free(*stack);
		*stack = tmp;
	}
}

void	free_images(t_game **game)
{
	mlx_destroy_image((*game)->mlx_ptr, (*game)->north_img->img_ptr);
	mlx_destroy_image((*game)->mlx_ptr, (*game)->south_img->img_ptr);
	mlx_destroy_image((*game)->mlx_ptr, (*game)->west_img->img_ptr);
	mlx_destroy_image((*game)->mlx_ptr, (*game)->east_img->img_ptr);
	mlx_destroy_image((*game)->mlx_ptr, (*game)->door_img->img_ptr);
	mlx_destroy_image((*game)->mlx_ptr, (*game)->open_door_img->img_ptr);
	mlx_destroy_image((*game)->mlx_ptr, (*game)->anim[1]->img_ptr);
	mlx_destroy_image((*game)->mlx_ptr, (*game)->anim[2]->img_ptr);
	mlx_destroy_image((*game)->mlx_ptr, (*game)->anim[3]->img_ptr);
	mlx_destroy_image((*game)->mlx_ptr, (*game)->anim[4]->img_ptr);
	mlx_destroy_image((*game)->mlx_ptr, (*game)->anim[5]->img_ptr);
	free((*game)->north_img);
	free((*game)->south_img);
	free((*game)->west_img);
	free((*game)->east_img);
	free((*game)->door_img);
	free((*game)->open_door_img);
	free((*game)->anim[1]);
	free((*game)->anim[2]);
	free((*game)->anim[3]);
	free((*game)->anim[4]);
	free((*game)->anim[5]);
	free((*game)->anim);
}

void	free_card_dir_img(t_game **game)
{
	if ((*game)->north_img)
	{
		mlx_destroy_image((*game)->mlx_ptr, (*game)->north_img->img_ptr);
		free((*game)->north_img);
	}
	if ((*game)->south_img)
	{
		mlx_destroy_image((*game)->mlx_ptr, (*game)->south_img->img_ptr);
		free((*game)->south_img);
	}
	if ((*game)->west_img)
	{
		mlx_destroy_image((*game)->mlx_ptr, (*game)->west_img->img_ptr);
		free((*game)->west_img);
	}
	if ((*game)->east_img)
	{
		mlx_destroy_image((*game)->mlx_ptr, (*game)->east_img->img_ptr);
		free((*game)->east_img);
	}
}

void	free_pixel_arrays(t_game **game)
{
	int	y;

	y = 0;
	while (y < TEXTURE_SIZE + 1) {
		free((*game)->n_pixels[y]);
		free((*game)->s_pixels[y]);
		free((*game)->w_pixels[y]);
		free((*game)->e_pixels[y]);
		free((*game)->d_pixels[y]);
		free((*game)->od_pixels[y]);
		free((*game)->doors_pixels[1][y]);
		free((*game)->doors_pixels[2][y]);
		free((*game)->doors_pixels[3][y]);
		free((*game)->doors_pixels[4][y]);
		free((*game)->doors_pixels[5][y++]);
	}
	free((*game)->n_pixels);
	free((*game)->s_pixels);
	free((*game)->w_pixels);
	free((*game)->e_pixels);
	free((*game)->d_pixels);
	free((*game)->od_pixels);
	free((*game)->doors_pixels[1]);
	free((*game)->doors_pixels[2]);
	free((*game)->doors_pixels[3]);
	free((*game)->doors_pixels[4]);
	free((*game)->doors_pixels[5]);
	free((*game)->doors_pixels);
}

void	free_map(t_game **game)
{
	int y;

	y = 0;
	while (y < (*game)->map->length)
	{
		free((*game)->map->map[y++]);
	}
	free((*game)->map->map);
	free((*game)->map);
}

void	free_game(t_game **game)
{
	free_images(game);
	free_pixel_arrays(game);
	free_map(game);
}

