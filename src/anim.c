/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkozlova <vkozlova@student.42wolfsburg.d>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 23:07:15 by vkozlova          #+#    #+#             */
/*   Updated: 2024/02/12 17:28:10 by vkozlova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3D.h"

void 	*create_anim_array(t_game **game)
{
	void **array = malloc(sizeof(void *) * 6);
	int width = 1719;
	int height = 835;

	array[0] = mlx_xpm_file_to_image((*game)->mlx_ptr, "anim_pictures/1.xpm", &width, &height);
	array[1] = mlx_xpm_file_to_image((*game)->mlx_ptr, "anim_pictures/2.xpm", &width, &height);
	array[2] = mlx_xpm_file_to_image((*game)->mlx_ptr, "anim_pictures/3.xpm", &width, &height);
	array[3] = mlx_xpm_file_to_image((*game)->mlx_ptr, "anim_pictures/4.xpm", &width, &height);
	array[4] = mlx_xpm_file_to_image((*game)->mlx_ptr, "anim_pictures/5.xpm", &width, &height);
	array[5] = mlx_xpm_file_to_image((*game)->mlx_ptr, "anim_pictures/6.xpm", &width, &height);
	return (array);
}
