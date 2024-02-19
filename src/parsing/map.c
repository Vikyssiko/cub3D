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
			if (divided_line[i][0] != '1' || divided_line[i][ft_strlen(divided_line[i]) - 1] != '1')
				clean_and_exit("Map has to be surrounded by walls", game);
			i++;
		}
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
			if (array[i][j] != '1' && array[i][j] != ' ')
			{
				if (array[i - 1][j] == ' ' || array[i + 1][j] == ' ')
					clean_and_exit("Map has to be surrounded by walls", game);
			}
			if (array[i][j] == 'N' || array[i][j] == 'S'
				|| array[i][j] == 'E' || array[i][j] == 'W')
			{
				if (array[i][j] == 'N')
					(*game)->player_angle = M_PI_2;
				if (array[i][j] == 'S')
					(*game)->player_angle = M_PI_2 * 3;
				if (array[i][j] == 'W')
					(*game)->player_angle = 0;
				if (array[i][j] == 'E')
					(*game)->player_angle = M_PI_2 * 2;
//				printf("i: %i, player_y: %i\n", i, i * 64 + 32);
				(*game)->player_y = i * 64 + 32;
				(*game)->player_x = j * 64 + 32;
			}
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
			if (array[i][j] != '1' && array[i][j] != ' ')
				cnt++;
			else if (array[i][j] == '1')
				wall_cnt++;
			if (array[i][j + 1] != '1' && array[i][j + 1] != ' ')
				cnt++;
			else if (array[i][j + 1] == '1')
				wall_cnt++;
			if (array[i + 1][j] != '1' && array[i + 1][j] != ' ')
				cnt++;
			else if (array[i + 1][j] == '1')
				wall_cnt++;
			if (array[i + 1][j + 1] != '1' && array[i + 1][j + 1] != ' ')
				cnt++;
			else if (array[i + 1][j + 1] == '1')
				wall_cnt++;
			if (cnt == 1 && wall_cnt < 3)
				clean_and_exit("Please check corners", game);
			j++;
		}
		i++;
	}
}

void	check_map(t_game **game)
{
	check_first_last_wall(game);
	check_surrounding_walls(game);
	check_corners(game);
}
