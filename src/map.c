/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkozlova <vkozlova@student.42wolfsburg.d>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 20:48:24 by vkozlova          #+#    #+#             */
/*   Updated: 2024/02/11 20:48:28 by vkozlova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3D.h"

void	check_first_last_line(char *line, t_game **game)
{
	int	i;
	int	len;

	len = ft_strlen(line);
	i = 0;
	while (i < len)
	{
		if (line[i] != '1' && line[i] != ' ')
			clean_and_exit("Map has to be surrounded by walls", game);
		i++;
	}
}

void	check_map(t_game **game)
{
	int		i;
	int		line_index;
	char	**divided_line;

	line_index = 1;
	check_first_last_line((*game)->map->map[0], game);
	check_first_last_line((*game)->map->map[(*game)->map->length - 1], game);
	while (line_index < (*game)->map->length - 1)
	{
		i = 0;
		divided_line = ft_split((*game)->map->map[line_index], ' ');
		while (divided_line[i])
		{
			if (divided_line[i][0] != '1' || divided_line[i][ft_strlen(divided_line[i]) - 1] != '1')
				clean_and_exit("Map has to be surrounded by walls", game);
			i++;
		}
		line_index++;
	}
}
