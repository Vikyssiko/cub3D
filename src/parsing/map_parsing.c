/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkozlova <vkozlova@student.42wolfsburg.d>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 15:14:14 by vkozlova          #+#    #+#             */
/*   Updated: 2024/02/11 15:14:20 by vkozlova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3D.h"

t_map	*create_map(void)
{
	t_map	*map;

	map = malloc(sizeof(t_map));
	map->map = NULL;
	map->start = 0;
	map->length = 0;
//	map->width = 0;
//	if (!game)
//		exit_with_error("Error of malloc");
//	game->map_name = map_name;
//	game->west = NULL;
//	game->ceiling = NULL;
//	game->east = NULL;
//	game->floor = NULL;
//	game->north = NULL;
//	game->south = NULL;
	return (map);
}

char	*skip_empty_lines(t_game **game)
{
	char	*line;

	line = get_next_line((*game)->fd);
	if (!line)
		exit_with_error("There is no map", (*game)->fd);
	(*game)->map = create_map();
	while (line)
	{
		if (ft_strlen(line) == 1 && line[0] == '\n')
		{
			free(line);
			line = get_next_line((*game)->fd);
		}
		else
			break ;
	}
	if (!line)
		exit_with_error("There is no map", (*game)->fd);
	return (line);
}

void	creating_map_array(t_game **game)
{
	int		i;
	t_stack	*stack;

	i = 0;
	(*game)->map->length = ft_stcksize((*game)->stack);
	(*game)->map->map = malloc(sizeof(char *) * (*game)->map->length);
	stack = (*game)->stack;
	while (stack)
	{
		(*game)->map->map[i] = malloc((*game)->map_width);
		ft_memset((*game)->map->map[i], ' ', (*game)->map_width - 1);
		(*game)->map->map[i][(*game)->map_width - 1] = '\0';
		ft_strcpy((*game)->map->map[i], stack->str);
		stack = stack->next;
		i++;
	}
}

int		find_max(int a, int b)
{
	if (a >= b)
		return (a);
	return (b);
}

void	parse_map(t_game **game)
{
	char	*line;

	line = skip_empty_lines(game);
	(*game)->map_width = find_max((*game)->map_width, ft_strlen(line));
	(*game)->stack = ft_stcknew(line);
	check_symbol(line, game);
//	free(line);
	line = get_next_line((*game)->fd);
	while (line)
	{
		(*game)->map_width = find_max((*game)->map_width, ft_strlen(line));
		check_symbol(line, game);
		ft_stckadd_back((&(*game)->stack), ft_stcknew(line));
		line = get_next_line((*game)->fd);
	}
	creating_map_array(game);
}
