/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkozlova <vkozlova@student.42wolfsburg.d>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 18:02:58 by vkozlova          #+#    #+#             */
/*   Updated: 2024/02/10 18:10:10 by vkozlova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdlib.h>
# include <fcntl.h>
# include "../libft/header/libft.h"

typedef struct s_stack
{
	char			*str;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

typedef struct s_map {
	char	**map;
	char	start;
	int		length;
}	t_map;

typedef struct s_game {
	int		fd;
	char	*north;
	char	*south;
	char	*west;
	char	*east;
	char	*floor;
	char	*ceiling;
	t_map	*map;
	t_stack	*stack;
}	t_game;

t_game	*parse_textures(char *map_name);
t_game	*create_game(int fd);
int		ft_strcmp(const char *s1, const char *s2);
void	check_cardinal_directions(t_game **game, char **instructions);
void	check_floor_ceiling(t_game **game, char **instructions);
void	clean_and_exit(char *message, t_game **game);
void	exit_with_error(char *message, int fd);
void	parse_map(t_game **game);
void	check_symbol(char *line, t_game **game);
void	check_map(t_game **game);
char	*strdupn(const char *s1);

t_stack	*ft_stcknew(char *content);
void	ft_stckadd_front(t_stack **stck, t_stack *new);
void	ft_stckadd_back(t_stack **stack, t_stack *new);
t_stack	*ft_stcklast(t_stack *stack);
int		ft_stcksize(t_stack *stck);

#endif
