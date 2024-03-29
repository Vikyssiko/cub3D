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

//static int i;

void	open_doors(t_game **game, int i) {
//	while (1) {
		if (i % 35000 < 5000) {
			(*game)->d_pixels = (*game)->doors_pixels[0];
		} else if (i % 35000 < 10000) {
			(*game)->d_pixels = (*game)->doors_pixels[1];
		} else if (i % 35000 < 15000) {
			(*game)->d_pixels = (*game)->doors_pixels[2];
		} else if (i % 35000 < 20000) {
			(*game)->d_pixels = (*game)->doors_pixels[3];
		} else if (i % 35000 < 25000) {
			(*game)->d_pixels = (*game)->doors_pixels[4];
		} else if (i % 35000 < 30000) {
			(*game)->d_pixels = (*game)->doors_pixels[5];
		} else {
			(*game)->d_pixels = (*game)->od_pixels;
			(*game)->door_open = ((*game)->door_open + 1) % 2;
			(*game)->d_pixels = (*game)->doors_pixels[0];
//			break;
		}
//		i++;
//	}
}
