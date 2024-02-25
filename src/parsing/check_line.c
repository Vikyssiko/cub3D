/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkozlova <vkozlova@student.42wolfsburg.d>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 17:51:09 by vkozlova          #+#    #+#             */
/*   Updated: 2024/02/11 17:51:12 by vkozlova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3D.h"

void	check_symbol(char *line, t_game **game)
{
	int	i;
	int	width;

	i = 0;
	width = ft_strlen(line) - 1;
	while (i < width)
	{
		if (line[i] != '1' && line[i] != '0' && line[i] != 'N'
			&& line[i] != 'S' && line[i] != 'E' && line[i] != 'W' && line[i] != ' ')
			clean_and_exit("Some symbols are not allowed", game);
		if (line[i] == 'N' || line[i] == 'S' || line[i] == 'E' || line[i] == 'W')
		{
			if ((*game)->map->start != 0)
				clean_and_exit("There can't be more than one starting position", game);
			(*game)->map->start = line[i];
		}
		i++;
	}
}
