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
# include <math.h>
//# include <mathcalls.h>
# include "../libft/header/libft.h"
# include "../minilibx/mlx.h"

# define FOV					60
# define WALL					64
# define PLAYER					32
//# define PROJECTION_HEIGHT		1000
//# define PROJECTION_WIDTH		1600
# define PI						3.1415926
# define MAP_HEIGHT				1000
# define MAP_WIDTH				1800
# define CELL_SIZE				8
# define MINIMAP_COLOR			0xFF9933
# define TEXTURE_SIZE			510

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

typedef struct s_img
{
	void	*img_ptr;
	char	*img_pixels_ptr;
	int		bits_per_pixel;
	int		endian;
	int		line_len;
}	t_img;

typedef struct s_dist {
	double	dist;
	char	direction;
	int		color;
//    t_img	*texture;
}	t_dist;

//typedef struct s_ray {
//	double	x;
//	double 	y;
//}	t_ray;

typedef struct s_ray {
	double	x;
	double 	y;
	double 	x_diff;
	double 	y_diff;
}	t_ray;

typedef struct s_player {
	int	x;
	int	y;
	int	angle;
	int	xd;
	int	yd;
}	t_player;

typedef struct s_game {
	int			player_x;
	int			player_y;
	double		player_angle;
//	double		player_xd;
//	double		player_yd;
	int			fd;
	int			map_width;
	char		*north;
	t_img		*north_img;
	char		*south;
	t_img		*south_img;
	char		*west;
	t_img		*west_img;
	char		*east;
	t_img		*east_img;
	int			*n_pixels;
	int			*s_pixels;
	int			*w_pixels;
	int			*e_pixels;
//	char		*floor;
//	char		*ceiling;
	int			floor;
	int			ceiling;
	t_map		*map;
	t_stack		*stack;
	void		*mlx_ptr;
	t_img		*img;
	void		*window_ptr;
	double		cos_array[360];
}	t_game;

t_game	*parse_textures(char *map_name);
t_game	*create_game(int fd);
int		ft_strcmp(const char *s1, const char *s2);
void	check_cardinal_directions(t_game **game, char **instructions);
void	check_floor_ceiling(t_game **game, char **instructions);
void 	clean_and_exit(char *message, t_game **game);
int		clean_and_exit_no_error(t_game **game);
void	exit_with_error(char *message, int fd);
void	parse_map(t_game **game);
void	check_symbol(char *line, t_game **game);
void	check_first_last_wall(t_game **game);
char	*strdupn(const char *s1);
void	ft_strcpy(char *dst, const char *src);
void	check_surrounding_walls(t_game **game);
void	check_corners(t_game **game);
void	check_map(t_game **game);
t_dist 	horizont_hit_dist(t_game **game, double angle);
t_dist 	vertical_hit_dist(t_game **game, double angle);
double	find_min(double a, double b);
void	create_cos_array(t_game **game);
t_dist 	find_dist(t_game **game, t_ray *ray, double angle, t_dist dist);
t_dist	find_min_dist(t_dist vert, t_dist hor);
int 	rgb_to_decimal(char *color_rgb, t_game **game);
void	init_textures(t_game **game);
void	create_array_of_pixels(t_game **game);

t_stack	*ft_stcknew(char *content);
void	ft_stckadd_front(t_stack **stck, t_stack *new);
void	ft_stckadd_back(t_stack **stack, t_stack *new);
t_stack	*ft_stcklast(t_stack *stack);
int		ft_stcksize(t_stack *stck);

#endif
