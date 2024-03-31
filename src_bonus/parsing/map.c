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

#include "../../header/cub3D.h"

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

void	check_first_last_wall(t_game **game)
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
			if (divided_line[i][0] != '1'
				|| divided_line[i][ft_strlen(divided_line[i]) - 1] != '1')
			{
				free_string_array(divided_line);
				clean_and_exit("Map has to be surrounded by walls", game);
			}
			i++;
		}
		free_string_array(divided_line);
		line_index++;
	}
}

void	check_surrounding_walls(t_game **game)
{
	int		i;
	int		j;
	char	**array;

	i = 1;
	array = (*game)->map->map;
	while (i < (*game)->map->length - 1)
	{
		j = 0;
		while (j < (*game)->map_width)
		{
			if (array[i][j] != '1' && array[i][j] != ' '
				&& (array[i - 1][j] == ' ' || array[i + 1][j] == ' '))
				clean_and_exit("Map has to be surrounded by walls", game);
			if (array[i][j] == 'N' || array[i][j] == 'S'
				|| array[i][j] == 'E' || array[i][j] == 'W')
				init_player_position(game, i, j);
			j++;
		}
		i++;
	}
}

void	check_corners(t_game **game)
{
	int		i;
	int		j;
	char	**array;
	int		cnt;
	int		wall_cnt;

	i = 0;
	array = (*game)->map->map;
	while (i < (*game)->map->length - 1)
	{
		j = 0;
		while (j < (*game)->map_width - 1)
		{
			cnt = 0;
			wall_cnt = 0;
			check_corner_symbol(&cnt, &wall_cnt, array[i][j]);
			check_corner_symbol(&cnt, &wall_cnt, array[i][j + 1]);
			check_corner_symbol(&cnt, &wall_cnt, array[i + 1][j]);
			check_corner_symbol(&cnt, &wall_cnt, array[i + 1][j + 1]);
			if (cnt == 1 && wall_cnt < 3)
				clean_and_exit("Please check corners", game);
			j++;
		}
		i++;
	}
}

void	check_map(t_game **game)
{
	if ((*game)->map->start == 0)
		clean_and_exit("There is no player at the map", game);
	check_first_last_wall(game);
	check_surrounding_walls(game);
	check_corners(game);
	check_doors(game);
}
