/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_parsing.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkozlova <vkozlova@student.42wolfsburg.d>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 18:15:49 by vkozlova          #+#    #+#             */
/*   Updated: 2024/02/10 18:15:55 by vkozlova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3D.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	while (s1 || s2)
	{
		if (*s1 != *s2 || !*s1 || !*s2)
			return ((unsigned char)*s1 - (unsigned char)*s2);
		s1++;
		s2++;
	}
	return (0);
}

int	check_all_instructions(t_game *game)
{
	if (game->north && game->south && game->west && game->east
		&& game->floor && game->ceiling)
		return (1);
	return (0);
}

int rgb_to_decimal(char *color_rgb, t_game **game)
{
	char	**rgb;
	int		i;
	int 	color;
	int		multiplier;
	int		num;

	i = 0;
	multiplier = 1;
	color = 0;
	rgb = ft_split(color_rgb, ',');
	while (rgb[i])
		i++;
	if (i != 3)
		clean_and_exit("Colors in the map are not correct", game);
	i = 2;
	while (i >= 0)
	{
		num = ft_atoi(rgb[i]);
		if (num < 0 || num > 255)
			clean_and_exit("Colors in the map are not correct", game);
		color += num % 16 * multiplier;
		multiplier *= 16;
		color += num / 16 * multiplier;
		multiplier *= 16;
		i--;
	}
	free(color_rgb);
	free_string_array(rgb);
	return (color);
}

t_game	*parse_textures(char *map_name)
{
	int		fd;
	char	*line;
	t_game	*game;
	char	**instruction;

	fd = open(map_name, O_RDONLY);
	if (fd < 0)
		exit_with_error("Couldn't open file", 0);
	line = get_next_line(fd);
	if (!line)
		exit_with_error("Map is empty", fd);
	game = create_game(fd);
	while (line)
	{
		if (ft_strlen(line) != 0)
		{
			instruction = ft_split(line, ' ');
			if (ft_strlen(instruction[0]) == 1 && instruction[0][0] == '\n')
			{
				free(line);
				line = get_next_line(fd);
				clean_instructions(instruction);
				continue ;
			}
			if (instruction[2] != NULL || instruction[0] == NULL || instruction[1] == NULL)
				clean_and_exit("Invalid instruction: an instruction and texture required", &game);
			check_cardinal_directions(&game, instruction);
			check_floor_ceiling(&game, instruction);
			if (check_all_instructions(game))
			{
				clean_instructions(instruction);
				free(line);
				break ;
			}
		}
		clean_instructions(instruction);
		free(line);
		line = get_next_line(fd);
	}
	if (!check_all_instructions(game))
		clean_and_exit("Invalid instruction: not all instructions present", &game);
	return (game);
}
