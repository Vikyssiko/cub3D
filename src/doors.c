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
