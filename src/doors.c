/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doors.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkozlova <vkozlova@student.42wolfsburg.d>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 12:37:47 by vkozlova          #+#    #+#             */
/*   Updated: 2024/03/29 12:37:47 by vkozlova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3D.h"

void	open_doors(t_game **game, int i)
{
	if (i % 21000 < 3000)
		(*game)->d_pixels = (*game)->doors_pixels[0];
	else if (i % 21000 < 6000)
		(*game)->d_pixels = (*game)->doors_pixels[1];
	else if (i % 21000 < 9000)
		(*game)->d_pixels = (*game)->doors_pixels[2];
	else if (i % 21000 < 12000)
		(*game)->d_pixels = (*game)->doors_pixels[3];
	else if (i % 21000 < 15000)
		(*game)->d_pixels = (*game)->doors_pixels[4];
	else if (i % 21000 < 18000)
		(*game)->d_pixels = (*game)->doors_pixels[5];
	else
	{
		(*game)->door_open = ((*game)->door_open + 1) % 2;
		(*game)->d_pixels = (*game)->doors_pixels[0];
		(*game)->door_open_anim = 0;
	}
}

void	close_doors(t_game **game, int i)
{
	if (i % 14000 < 2000)
		(*game)->od_pixels = (*game)->doors_pixels[5];
	else if (i % 14000 < 4000)
		(*game)->od_pixels = (*game)->doors_pixels[4];
	else if (i % 14000 < 6000)
		(*game)->od_pixels = (*game)->doors_pixels[3];
	else if (i % 14000 < 8000)
		(*game)->od_pixels = (*game)->doors_pixels[2];
	else if (i % 14000 < 10000)
		(*game)->od_pixels = (*game)->doors_pixels[1];
	else if (i % 14000 < 12000)
		(*game)->od_pixels = (*game)->doors_pixels[0];
	else
	{
		(*game)->door_open = ((*game)->door_open + 1) % 2;
		(*game)->od_pixels = (*game)->doors_pixels[6];
		(*game)->door_close_anim = 0;
	}
}

int	handle_release(int key, t_game **game)
{
	if (key == XK_Escape)
		clean_and_exit_no_error(game);
	else if (key == XK_Left)
		(*game)->keys.left_pressed = 0;
	else if (key == XK_Right)
		(*game)->keys.right_pressed = 0;
	else if (key == XK_w)
		(*game)->keys.w_pressed = 0;
	else if (key == XK_s)
		(*game)->keys.s_pressed = 0;
	else if (key == XK_d)
		(*game)->keys.d_pressed = 0;
	else if (key == XK_a)
		(*game)->keys.a_pressed = 0;
	return (0);
}

int	mouse_move_hook(int x, int y, t_game **game)
{
	int	delta_x;
	int	y_pos;

	y_pos = y;
	delta_x = x - (*game)->mouse_x;
	(*game)->mouse_x = x;
	if (delta_x > 0)
		(*game)->player_angle = fix_angle((*game)->player_angle - 0.1);
	else if (delta_x < 0)
		(*game)->player_angle = fix_angle((*game)->player_angle + 0.1);
	return (0);
}
