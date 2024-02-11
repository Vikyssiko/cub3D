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

#include "../header/cub3D.h"

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

//int	is_valid_instruction(char **instruction)
//{
//
//}

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
				continue ;
			}
			if (instruction[2] != NULL || instruction[0] == NULL || instruction[1] == NULL)
				clean_and_exit("Invalid instruction: only instruction and texture required", &game);
//			printf("instruction: %s - %s\n", instruction[0], instruction[1]);
			check_cardinal_directions(&game, instruction);
			check_floor_ceiling(&game, instruction);
			if (check_all_instructions(game))
				break ;
		}
		//free_instructions
		free(line);
		line = get_next_line(fd);
	}
//	printf("north: %s\n", game->north);
//	printf("south: %s\n", game->south);
//	printf("east: %s\n", game->east);
//	printf("west: %s\n", game->west);
//	printf("floor: %s\n", game->floor);
//	printf("ceiling: %s\n", game->ceiling);
	if (!check_all_instructions(game))
		clean_and_exit("Invalid instruction: not all instructions present", &game);
	return (game);
}
