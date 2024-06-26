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
# include "../libft/header/libft.h"
# include "../minilibx/mlx.h"
# include <X11/keysym.h>
# include <X11/X.h>

# define FOV					60
# define CUBE					512
# define BITS					9
# define PLAYER					0xFF0000
# define PI						3.1415926
# define MAP_HEIGHT				1000
# define MAP_WIDTH				1800
# define CELL_SIZE				8
# define MINIMAP_COLOR			0xFFFAAA
# define TEXTURE_SIZE			512

typedef struct s_stack
{
	char			*str;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

typedef struct s_map
{
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

typedef struct s_dist
{
	double	dist;
	double	hit_point;
	char	direction;
}	t_dist;

typedef struct s_ray
{
	double	x;
	double	y;
	double	x_diff;
	double	y_diff;
}	t_ray;

typedef struct s_player
{
	int	x;
	int	y;
	int	angle;
	int	xd;
	int	yd;
}	t_player;

typedef struct s_key_pressed
{
	int	w_pressed;
	int	s_pressed;
	int	a_pressed;
	int	d_pressed;
	int	left_pressed;
	int	right_pressed;
}	t_key_pressed;

typedef struct s_game
{
	int				player_x;
	int				player_y;
	double			player_angle;
	int				fd;
	int				map_width;
	char			*north;
	t_img			*north_img;
	char			*south;
	t_img			*south_img;
	char			*west;
	t_img			*west_img;
	char			*east;
	t_img			*east_img;
	t_img			*door_img;
	t_img			*open_door_img;
	t_img			**anim;
	int				***doors_pixels;
	int				**n_pixels;
	int				**s_pixels;
	int				**w_pixels;
	int				**e_pixels;
	int				**d_pixels;
	int				**od_pixels;
	int				floor;
	int				ceiling;
	t_map			*map;
	t_stack			*stack;
	void			*mlx_ptr;
	t_img			*img;
	void			*window_ptr;
	int				door_open;
	int				door_open_anim;
	int				door_close_anim;
	t_key_pressed	keys;
	int				mouse_x;
	int				time;
}	t_game;

t_game	*parse_textures(char *map_name);
t_game	*create_game(int fd);
int		ft_strcmp(const char *s1, const char *s2);
void	check_cardinal_directions(t_game **game, char **instructions);
void	check_floor_ceiling(t_game **game, char **instructions);
void	clean_and_exit(char *message, t_game **game);
int		clean_and_exit_no_error(t_game **game);
void	exit_with_error(char *message, int fd);
void	parse_map(t_game **game);
void	check_symbol(char *line, t_game **game);
void	check_doors(t_game **game);
void	check_first_last_wall(t_game **game);
void	ft_strcpy(char *dst, const char *src);
void	check_surrounding_walls(t_game **game);
void	check_corners(t_game **game);
void	check_map(t_game **game);
t_dist	horizontal_hit_dist(t_game **game, double angle, int door);
t_dist	vertical_hit_dist(t_game **game, double angle, int door);
double	find_min(double a, double b);
t_dist	find_min_dist(t_dist vert, t_dist hor);
int		rgb_to_decimal(char *color_rgb, t_game **game);
void	init_textures(t_game **game);
void	create_array_of_pixels(t_game **game);
void	check_corner_symbol(int *cnt, int *wall_cnt, char symbol);
void	init_player_position(t_game **game, int i, int j);
void	change_position(t_game **game, int x, int y);
void	my_mlx_pixel_put(t_img *img, int x, int y, int color);
void	draw_map(t_game **game);
void	draw_rays(t_game **game);
int		draw(t_game **game);
void	draw_doors(t_game **game);
void	draw_background(t_game **game);

int		get_pixel_color(int x, int y, char *data_addr, t_img *img);

t_stack	*ft_stcknew(char *content);
void	ft_stckadd_back(t_stack **stack, t_stack *new);
int		ft_stcksize(t_stack *stck);

void	create_open_door_texture_img(t_game **game);

void	clean_instructions(char **instructions);
void	free_string_array(char **str);
void	free_stack(t_stack **stack);

void	create_anim_array(t_game **game);
void	create_door_list(t_game **game);
t_img	create_door_texture(t_game **game, char *texture);
void	create_door_texture_img(t_game **game);
void	create_anim_pixels_array(t_game **game);
void	put_color(t_game **game, int x, int y);

void	open_doors(t_game **game, int i);
void	close_doors(t_game **game, int i);

double	fix_angle(double angle);
void	keys(t_game **game);

void	free_game(t_game **game);
void	free_map(t_game **game);
void	free_images(t_game **game);
void	free_pixel_arrays(t_game **game);
int		rgb_to_decimal(char *color_rgb, t_game **game);

int		mouse_move_hook(int x, int y, t_game **game);
int		handle_release(int key, t_game **game);
int		handle_input(int key, t_game **game);

#endif
