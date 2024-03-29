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

#include "../header/cub3D.h"
#include <stdio.h>
#include <X11/keysym.h>
#include <X11/X.h>

t_game	*create_game(int fd)
{
	t_game	*game;

	game = malloc(sizeof(t_game));
	if (!game)
		exit_with_error("Error of malloc", fd);
	game->map_width = 0;
	game->stack = NULL;
	game->fd = fd;
	game->west = NULL;
	game->ceiling = 0;
	game->east = NULL;
	game->floor = 0;
	game->north = NULL;
	game->south = NULL;
	game->player_x = 0;
	game->player_y = 0;
	game->player_angle = 0;
	game->north_img = NULL;
	game->south_img = NULL;
	game->west_img = NULL;
	game->east_img = NULL;
	game->n_pixels = NULL;
	game->s_pixels = NULL;
	game->w_pixels = NULL;
	game->e_pixels = NULL;
	game->map = NULL;
	game->mlx_ptr = NULL;
	game->img = NULL;
	game->window_ptr = NULL;
	game->door_open = 0;
	return (game);
}

double fix_angle(double angle)
{
	double	radian;

	radian = 0.0174533;
	if (angle > 2 * M_PI - radian / 10)
		angle -= 2 * M_PI;
	else if (angle < 0)
		angle += 2 * M_PI;
//	else if (angle > M_PI - radian / 10 && angle < M_PI)
//		angle -= radian / 10;
	return (angle);
}

static int a;

void	draw_doors(t_game **game)
{
	double	ray_angle;
	t_dist 	dist;
	double 	line_height;
	double 		y_start;
	int		x;
	double line;

	ray_angle = fix_angle((*game)->player_angle + M_PI_2 / 3);
	x = 0;
	while (x < MAP_WIDTH)
	{
		dist = find_min_dist(vertical_hit_dist(game, ray_angle, 1),
							 horizontal_hit_dist(game, ray_angle, 1));
		if (dist.dist < 0)
		{
			ray_angle = fix_angle(ray_angle - 0.0002);
			continue ;
		}
		if (dist.direction != 'D') {
			x++;
			ray_angle = fix_angle(ray_angle - 0.00058177);
			continue;
		}
		dist.dist = dist.dist * cos(fix_angle((*game)->player_angle - ray_angle));
		if (dist.dist < 0)
		{
			ray_angle = fix_angle(ray_angle - 0.0002);
			continue ;
		}
		line_height = CUBE * (MAP_WIDTH / 2 / tan(M_PI_2 / 3)) / dist.dist;
		int color;
		double ratio = TEXTURE_SIZE / line_height;
		y_start = MAP_HEIGHT / 2 - (line_height / 2);
		int y_end = MAP_HEIGHT / 2 + (line_height / 2);
		line = dist.hit_point;
		if (y_start < 0)
			y_start = 0;
		if (y_end > MAP_HEIGHT)
			y_end = MAP_HEIGHT - 1;
		int	**array;
		if ((*game)->door_open == 1)
			array = (*game)->od_pixels;
		else
			array = (*game)->d_pixels;
		double texture_pos = (y_start - MAP_HEIGHT / 2 + line_height / 2) * ratio;
		if (texture_pos < 0)
			texture_pos = 0.0;
		while (y_start < y_end)
		{
			color = array[(int)(texture_pos)][(int)line % TEXTURE_SIZE];
			if (color != 0) {
				my_mlx_pixel_put((*game)->img, x, y_start, color);
			}
			texture_pos += ratio;
			y_start++;
		}
		x += 1;
		ray_angle = fix_angle(ray_angle - 0.00058177);
	}
}

void	draw_rays(t_game **game)
{
	double	ray_angle;
	int		i;
	t_dist 	dist;
	double 	line_height;
	double 		y_start;
	int		x;

	double line;

	i = 0;
	ray_angle = fix_angle((*game)->player_angle + M_PI_2 / 3);
	x = 0;
	while (i < MAP_WIDTH)
	{
		dist = find_min_dist(vertical_hit_dist(game, ray_angle, 0),
						horizontal_hit_dist(game, ray_angle, 0));
//		double fixed_angle = fix_angle((*game)->player_angle - ray_angle);
//		if ((fixed_angle > M_PI_2 && fixed_angle < M_PI_2 * 3)
//			|| fixed_angle < M_PI_2 || fixed_angle > M_PI_2 * 3)
			dist.dist = dist.dist * cos(fix_angle((*game)->player_angle - ray_angle));
		if (dist.dist < 0)
		{
			ray_angle = fix_angle(ray_angle - 0.0002);
			continue ;
		}
		line_height = CUBE * (MAP_WIDTH / 2 / tan(M_PI_2 / 3)) / dist.dist;
		int color;
		double ratio = TEXTURE_SIZE / line_height;
		y_start = MAP_HEIGHT / 2 - (line_height / 2);
		int y_end = MAP_HEIGHT / 2 + (line_height / 2);
		line = dist.hit_point;
		if (y_start < 0)
			y_start = 0;
		if (y_end > MAP_HEIGHT)
			y_end = MAP_HEIGHT - 1;
		int	**array;
		if (dist.direction == 'N')
			array = (*game)->n_pixels;
		else if (dist.direction == 'S')
			array = (*game)->s_pixels;
		else if (dist.direction == 'W')
			array = (*game)->w_pixels;
		else if (dist.direction == 'E')
			array = (*game)->e_pixels;
		double texture_pos = (y_start - MAP_HEIGHT / 2 + line_height / 2) * ratio;
		if (texture_pos < 0)
			 texture_pos = 0.0;
		while (y_start < y_end)
		{
			color = array[(int)(texture_pos)][(int)line % TEXTURE_SIZE];
			my_mlx_pixel_put((*game)->img, x, y_start, color);
			texture_pos += ratio;
			y_start++;
		}
		x += 1;
		ray_angle = fix_angle(ray_angle - 0.00058177);
		i++;
	}
}

void	draw_black(t_game **game)
{
	int	color;
	int y;
	int x;

	y = 0;
	color = (*game)->ceiling;
	while (y < MAP_HEIGHT)
	{
		x = 0;
		if (y > MAP_HEIGHT / 2)
			color = (*game)->floor;
		while (x < MAP_WIDTH)
		{
			my_mlx_pixel_put((*game)->img, x, y, color);
			x++;
		}
		y++;
	}
}

static int i;
static int a;

int	draw(t_game **game)
{
	if ((*game)->door_open && (*game)->door_close_anim) {
		if (i % 14000 < 2000) {
			(*game)->od_pixels = (*game)->doors_pixels[5];
		} else if (i % 14000 < 4000) {
			(*game)->od_pixels = (*game)->doors_pixels[4];
		} else if (i % 14000 < 6000) {
			(*game)->od_pixels = (*game)->doors_pixels[3];
		} else if (i % 14000 < 8000) {
			(*game)->od_pixels = (*game)->doors_pixels[2];
		} else if (i % 14000 < 10000) {
			(*game)->od_pixels = (*game)->doors_pixels[1];
		} else if (i % 14000 < 12000) {
			(*game)->od_pixels = (*game)->doors_pixels[0];
		} else {
			(*game)->door_open = ((*game)->door_open + 1) % 2;
			(*game)->od_pixels = (*game)->doors_pixels[6];
			(*game)->door_close_anim = 0;
		}
	} else if (!(*game)->door_open && (*game)->door_open_anim) {
		if (i % 21000 < 3000) {
			(*game)->d_pixels = (*game)->doors_pixels[0];
		} else if (i % 21000 < 6000) {
			(*game)->d_pixels = (*game)->doors_pixels[1];
		} else if (i % 21000 < 9000) {
			(*game)->d_pixels = (*game)->doors_pixels[2];
		} else if (i % 21000 < 12000) {
			(*game)->d_pixels = (*game)->doors_pixels[3];
		} else if (i % 21000 < 15000) {
			(*game)->d_pixels = (*game)->doors_pixels[4];
		} else if (i % 21000 < 18000) {
			(*game)->d_pixels = (*game)->doors_pixels[5];
		} else {
			(*game)->door_open = ((*game)->door_open + 1) % 2;
			(*game)->d_pixels = (*game)->doors_pixels[0];
			(*game)->door_open_anim = 0;
		}
	}
	if (a % 500 == 0)
	{
		keys(game);
		a = 0;
		draw_black(game);
		draw_rays(game);
		draw_doors(game);
		draw_map(game);
		mlx_put_image_to_window((*game)->mlx_ptr, (*game)->window_ptr, (*(*game)->img).img_ptr, 0, 0);
	}
	a++;
	i++;
	return (0);
}

int	handle_input(int key, t_game **game)
{
	if (key == XK_Escape)
		clean_and_exit_no_error(game);
	else if (key == XK_Left)
		(*game)->keys.left_pressed = 1;
	else if (key == XK_Right)
		(*game)->keys.right_pressed = 1;
	else if (key == XK_w)
		(*game)->keys.w_pressed = 1;
	else if (key == XK_s)
		(*game)->keys.s_pressed = 1;
	else if (key == XK_d)
		(*game)->keys.d_pressed = 1;
	else if (key == XK_a)
		(*game)->keys.a_pressed = 1;
	else if (key == XK_space) {
		if (!(*game)->door_open && !(*game)->door_open_anim) {
			i = 0;

			(*game)->door_open_anim = 1;
		}
		else if ((*game)->door_open && !(*game)->door_close_anim) {
			i = 0;
			(*game)->door_close_anim = 1;

		}
	}
	return (0);
}

int	handle_release(int key, t_game **game)
{
	if (key == XK_Escape)
		clean_and_exit_no_error(game);
	else if (key == XK_Left)
		(*game)->keys.left_pressed = 0;
	else if (key == XK_Right)
		(*game)->keys.right_pressed = 0;
	else if (key == XK_w)
		(*game)->keys.w_pressed = 0;
	else if (key == XK_s)
		(*game)->keys.s_pressed = 0;
	else if (key == XK_d)
		(*game)->keys.d_pressed = 0;
	else if (key == XK_a)
		(*game)->keys.a_pressed = 0;
	return (0);
}

int	mouse_move_hook(int x, int y, t_game **game)
{
	int	delta_x;
	int	y_pos;

	y_pos = y;
	delta_x = x - (*game)->mouse_x;
	(*game)->mouse_x = x;
	if (delta_x > 0)
		(*game)->player_angle = fix_angle((*game)->player_angle - 0.1);
	else if (delta_x < 0)
		(*game)->player_angle = fix_angle((*game)->player_angle + 0.1);
	return (0);
}

int main(int args, char *argv[])
{
	t_game	*game;
	t_img	img;

	if (args != 2)
		exit_with_error("Specify one map", 0);
	game = parse_textures(argv[1]);
	parse_map(&game);
	check_map(&game);
	game->mlx_ptr = mlx_init();
	init_textures(&game);
	game->img = &img;
	img.img_ptr = mlx_new_image(game->mlx_ptr, MAP_WIDTH, MAP_HEIGHT);
	img.img_pixels_ptr = mlx_get_data_addr(img.img_ptr, &img.bits_per_pixel, &img.line_len,
								 &img.endian);
	game->window_ptr = mlx_new_window(game->mlx_ptr, MAP_WIDTH, MAP_HEIGHT, "cub3D");
	mlx_put_image_to_window(game->mlx_ptr, game->window_ptr, img.img_ptr, 0, 0);
	mlx_hook(game->window_ptr, MotionNotify, PointerMotionMask, mouse_move_hook, &game);
	mlx_hook(game->window_ptr, KeyPress, KeyPressMask, handle_input, &game);
	mlx_hook(game->window_ptr, KeyRelease, KeyReleaseMask, handle_release, &game);
	mlx_loop_hook(game->mlx_ptr, draw, &game);
	mlx_hook(game->window_ptr,
			 DestroyNotify, ButtonPressMask, clean_and_exit_no_error, &game);
	mlx_loop(game->mlx_ptr);
	return (0);
}
