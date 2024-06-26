/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkozlova <vkozlova@student.42wolfsburg.d>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 23:13:56 by vkozlova          #+#    #+#             */
/*   Updated: 2024/03/30 23:13:56 by vkozlova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3D.h"

int	handle_input(int key, t_game **game)
{
	if (key == XK_Escape)
		clean_and_exit_no_error(game);
	else if (key == XK_Left)
		(*game)->keys.left_pressed = 1;
	else if (key == XK_Right)
		(*game)->keys.right_pressed = 1;
	else if (key == XK_w)
		(*game)->keys.w_pressed = 1;
	else if (key == XK_s)
		(*game)->keys.s_pressed = 1;
	else if (key == XK_d)
		(*game)->keys.d_pressed = 1;
	else if (key == XK_a)
		(*game)->keys.a_pressed = 1;
	return (0);
}

int	draw(t_game **game)
{
	static int	a;

	if (a % 500 == 0)
	{
		if ((*game)->keys.left_pressed)
			(*game)->player_angle = fix_angle((*game)->player_angle + 0.1);
		if ((*game)->keys.right_pressed)
			(*game)->player_angle = fix_angle((*game)->player_angle - 0.1);
		keys(game);
		a = 0;
		draw_background(game);
		draw_rays(game);
		mlx_put_image_to_window((*game)->mlx_ptr, (*game)->window_ptr,
			(*(*game)->img).img_ptr, 0, 0);
	}
	a++;
	(*game)->time++;
	return (0);
}
