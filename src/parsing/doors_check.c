/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doors_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkozlova <vkozlova@student.42wolfsburg.d>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 00:50:04 by vkozlova          #+#    #+#             */
/*   Updated: 2024/03/30 00:50:04 by vkozlova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3D.h"

void	check_doors(t_game **game)
{
	int		i;
	int		j;
	char	**array;

	i = 1;
	array = (*game)->map->map;
	while (i < (*game)->map->length - 1)
	{
		j = 1;
		while (j < (*game)->map_width - 1)
		{
			if (array[i][j] == 'D') {
				if ((array[i][j - 1] == '1' && array[i][j + 1] == '1')
					|| (array[i - 1][j] == '1' && array[i + 1][j] == '1'))
				{
					j++;
					continue;
				}
				else
					clean_and_exit("Doors should be located between walls", game);
			}
			j++;
		}
		i++;
	}
}
