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

int	check_all_instructions(t_game *game)
{
	if (game->north && game->south && game->west && game->east
		&& game->floor >= 0 && game->ceiling >= 0)
		return (1);
	return (0);
}

int	parse_instruction(char *line, char	**instruction, t_game **game)
{
	if (instruction[2] != NULL || instruction[0] == NULL
		|| instruction[1] == NULL)
		clean_and_exit(
			"Invalid instruction: an instruction and texture required", game);
	check_cardinal_directions(game, instruction);
	check_floor_ceiling(game, instruction);
	if (check_all_instructions(*game))
	{
		clean_instructions(instruction);
		free(line);
		return (1);
	}
	return (0);
}

char	*free_instruction_get_next(char *line, char	**instruction, int fd)
{
	clean_instructions(instruction);
	free(line);
	return (get_next_line(fd));
}

void	check_textures(char *line, int fd, t_game **game)
{
	char	**instruction;

	while (line)
	{
		if (ft_strlen(line) != 0)
		{
			instruction = ft_split(line, ' ');
			if (ft_strlen(instruction[0]) == 1 && instruction[0][0] == '\n')
			{
				line = free_instruction_get_next(line, instruction, fd);
				continue ;
			}
			if (parse_instruction(line, instruction, game))
				break ;
		}
		line = free_instruction_get_next(line, instruction, fd);
	}
}

t_game	*parse_textures(char *map_name)
{
	int		fd;
	char	*line;
	t_game	*game;

	fd = open(map_name, O_RDONLY);
	if (fd < 0)
		exit_with_error("Couldn't open file", 0);
	line = get_next_line(fd);
	if (!line)
		exit_with_error("Map is empty", fd);
	game = create_game(fd);
	check_textures(line, fd, &game);
	if (!check_all_instructions(game))
		clean_and_exit(
			"Invalid instruction: not all instructions present", &game);
	return (game);
}
