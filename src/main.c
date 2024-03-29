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
//		dist = horizontal_hit_dist(game, ray_angle, 1);
//		int vert = vertical_hit_dist(game, ray_angle, 1).dist;
//		int hor = horizontal_hit_dist(game, ray_angle, 1).dist;
//		if (vert < hor && dist.direction == 'D') {
//			printf("vert: %d, hor: %d, angle: %f\n", vert, hor, ray_angle);
//		}
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
//		if (a % 200000 < 100000)
		if ((*game)->door_open == 1)
		{
			array = (*game)->od_pixels;
		}
		else
		{
			a = 0;
			array = (*game)->d_pixels;
		}
//		else if (a % 10000 == 0) {
//			array = (*game)->od_pixels;
//		}
		a++;
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
//	t_img n = *((*game)->north_img);
//	t_img s = *((*game)->south_img);
//	t_img w = *((*game)->west_img);
//	t_img e = *((*game)->east_img);
	while (i < MAP_WIDTH)
	{
//		line = 0.0;
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
//		if (dist.direction == 'S' || dist.direction == 'N')
//			printf("hit point: %f, line: %f\n", line, (*game)->player_x + cos(ray_angle) * dist.dist);
//		else if (dist.direction == 'E' || dist.direction == 'W')
//			printf("hit point: %f, line: %f\n", line, (*game)->player_y - sin(ray_angle) * dist.dist);
//		if (line_height > MAP_HEIGHT)
//			line_height = MAP_HEIGHT;
		if (y_start < 0)
			y_start = 0;
		if (y_end > MAP_HEIGHT)
			y_end = MAP_HEIGHT - 1;
//		t_img texture;
		int	**array;
//		if (dist.direction == 'N')
//			texture = n;
//		else if (dist.direction == 'S')
//			texture = s;
//		else if (dist.direction == 'W')
//			texture = w;
//		else if (dist.direction == 'E')
//			texture = e;
//		if (dist.direction == 'E' || dist.direction == 'W')
//			line = (((*game)->player_y - sin(ray_angle) * dist.dist));
//		else if (dist.direction == 'S' || dist.direction == 'N')
//			line = (((*game)->player_x + cos(ray_angle) * dist.dist));
		if (dist.direction == 'N')
			array = (*game)->n_pixels;
		else if (dist.direction == 'S')
			array = (*game)->s_pixels;
		else if (dist.direction == 'W')
			array = (*game)->w_pixels;
		else if (dist.direction == 'E')
			array = (*game)->e_pixels;
//		else if (dist.direction == 'D')
//			array = (*game)->d_pixels;
		double texture_pos = (y_start - MAP_HEIGHT / 2 + line_height / 2) * ratio;
		if (texture_pos < 0)
			 texture_pos = 0.0;
		while (y_start < y_end)
		{
//			if (line >= (double)TEXTURE_SIZE)
//				line = line - (((int)line >> BITS) << BITS);
//				line = line - ((int)(line / TEXTURE_SIZE)) * TEXTURE_SIZE;
//				line = (int)line % TEXTURE_SIZE;
//			if ((int)(texture_pos) >= 510 || (int)(line) >= 510 || (int)(texture_pos) < 0 || (int)(line) < 0)
//				printf("ratio: %f, texture position: %f, line: %f\n", ratio, texture_pos, line);
//			if (line >= TEXTURE_SIZE)
//				line = 0.0;
//			color = array[(int)((double)((y_end - y_start) / ratio) * (double)TEXTURE_SIZE + line) - 1];
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

int	draw(t_game **game)
{

//	if (i % 10000)
//	{
//
//	}
	if (i % 500 == 0)
	{
		i = 0;
		draw_black(game);
		draw_rays(game);
		draw_doors(game);
		draw_map(game);
//		mlx_clear_window((*game)->mlx_ptr, (*game)->window_ptr);
		mlx_put_image_to_window((*game)->mlx_ptr, (*game)->window_ptr, (*(*game)->img).img_ptr, 0, 0);
	}
//	mlx_put_image_to_window((*game)->mlx_ptr, (*game)->window_ptr, ((*game)->anim)[0], 0, 0);
	i++;
	return (0);
}

int	handle_input(int key, t_game **game)
{
//	int mouse_x;
//	int mouse_y;

//	mouse_x = malloc(sizeof(int));
//	mouse_y = malloc(sizeof(int));
//	if ((*game) && (*game)->window_ptr)
//		mlx_mouse_get_pos((*game)->window_ptr, &mouse_x, &mouse_y);
	if (key == XK_Escape)
		clean_and_exit_no_error(game);
	else if (key == XK_Left)
		(*game)->player_angle = fix_angle((*game)->player_angle + 0.1);
	else if (key == XK_Right)
		(*game)->player_angle = fix_angle((*game)->player_angle - 0.1);
	else if (key == XK_w)
		go_straight(game);
	else if (key == XK_s)
		go_back(game);
	else if (key == XK_d)
		go_right(game);
	else if (key == XK_a)
		go_left(game);
	else if (key == XK_space)
		(*game)->door_open = ((*game)->door_open + 1) % 2;
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

//	game->anim = create_anim_array(&game);
	game->window_ptr = mlx_new_window(game->mlx_ptr, MAP_WIDTH, MAP_HEIGHT, "cub3D");
//	draw(&game);
	mlx_put_image_to_window(game->mlx_ptr, game->window_ptr, img.img_ptr, 0, 0);
//	mou
	mlx_hook(game->window_ptr, KeyPress, KeyPressMask, handle_input, &game);
	mlx_loop_hook(game->mlx_ptr, draw, &game);
	mlx_hook(game->window_ptr,
			 DestroyNotify, ButtonPressMask, clean_and_exit_no_error, &game);
	mlx_loop(game->mlx_ptr);
	return (0);
}

//	int i = 0;
//	t_stack	*stack = game->stack;
//	while (stack)
//	{
//		if (game->map->map)
//			printf("%s\n", game->map->map[i]);
//		stack = stack->next;
//		i++;
//	}
