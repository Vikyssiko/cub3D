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

#include "../../header/cub3D.h"

void	ft_strcpy(char *dst, const char *src)
{
	int		i;
	int 	src_len;

	i = 0;
	src_len = ft_strlen((char *)src);
	if (src[src_len - 1] == '\n')
		src_len--;
	while (i < src_len)
	{
		dst[i] = src[i];
		i++;
	}
}

void	check_corner_symbol(int *cnt, int *wall_cnt, char symbol)
{
	if (symbol != '1' && symbol != ' ')
		(*cnt)++;
	else if (symbol == '1')
		(*wall_cnt)++;
}

void	init_player_position(t_game **game, int i, int j)
{
	char	**array;

	array = (*game)->map->map;
	if (array[i][j] == 'N')
		(*game)->player_angle = M_PI_2;
	else if (array[i][j] == 'S')
		(*game)->player_angle = M_PI_2 * 3;
	else if (array[i][j] == 'W')
		(*game)->player_angle = 0.008;
	else if (array[i][j] == 'E')
		(*game)->player_angle = M_PI_2 * 2;
	(*game)->player_y = i * CUBE + CUBE / 2;
	(*game)->player_x = j * CUBE + CUBE / 2;
}
