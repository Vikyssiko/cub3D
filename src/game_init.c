/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkozlova <vkozlova@student.42wolfsburg.d>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 12:56:05 by vkozlova          #+#    #+#             */
/*   Updated: 2024/03/30 12:56:05 by vkozlova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3D.h"

void	init_pixels_arrays(t_game **game)
{
	(*game)->n_pixels = NULL;
	(*game)->s_pixels = NULL;
	(*game)->w_pixels = NULL;
	(*game)->e_pixels = NULL;
	(*game)->d_pixels = NULL;
	(*game)->od_pixels = NULL;
}

void	init_images(t_game **game)
{
	(*game)->east = NULL;
	(*game)->west = NULL;
	(*game)->north = NULL;
	(*game)->south = NULL;
	(*game)->north_img = NULL;
	(*game)->south_img = NULL;
	(*game)->west_img = NULL;
	(*game)->east_img = NULL;
	(*game)->door_img = NULL;
	(*game)->open_door_img = NULL;
}

void	init_keys(t_game **game)
{
	(*game)->keys.right_pressed = 0;
	(*game)->keys.left_pressed = 0;
	(*game)->keys.w_pressed = 0;
	(*game)->keys.s_pressed = 0;
	(*game)->keys.a_pressed = 0;
	(*game)->keys.d_pressed = 0;
}

t_game	*create_game(int fd)
{
	t_game	*game;

	game = malloc(sizeof(t_game));
	if (!game)
		exit_with_error("Error of malloc", fd);
	game->player_x = 0;
	game->player_y = 0;
	game->player_angle = 0;
	game->fd = fd;
	game->map_width = 0;
	game->stack = NULL;
	game->ceiling = 0;
	game->floor = 0;
	game->anim = NULL;
	game->map = NULL;
	game->mlx_ptr = NULL;
	game->img = NULL;
	game->window_ptr = NULL;
	game->door_open = 0;
	game->door_open_anim = 0;
	game->door_close_anim = 0;
//	game->keys = NULL;
	game->mouse_x = 0;
	init_images(&game);
	init_pixels_arrays(&game);
	init_keys(&game);
	return (game);
}
