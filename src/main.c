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
//	if (!game)
//		exit_with_error("Error of malloc");
	game->map_width = 0;
	game->stack = NULL;
	game->fd = fd;
	game->west = NULL;
	game->ceiling = NULL;
	game->east = NULL;
	game->floor = NULL;
	game->north = NULL;
	game->south = NULL;
	return (game);
}

//void find_players_pos(t_game **game)
//{
//	while ()
//}

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	int	offset;

//	printf("img->line_len: %i\n", img->line_len);
//	img->line_len = 16384;
	offset = (img->line_len * y) + (x * (img->bits_per_pixel / 8));
	*((unsigned int *)(offset + img->img_pixels_ptr)) = color;
}

double fix_angle(double angle)
{
	double	radian;

	radian = 0.0174533;
	if(angle > 2 * M_PI - radian)
		angle -= 2 * M_PI;
	if(angle < 0)
		angle += 2 * M_PI;
	return (angle);
}

void	draw_rays(t_game **game)
{
	double	ray_angle;
	int		i;
	t_dist 	dist;
	int		line_height;
	int		y_start;
	int		x;

	i = 0;
	ray_angle = fix_angle((*game)->player_angle + M_PI_2 / 3);
	x = 0;
	dist.color = 0xCCB3FF;
//	printf("here 1\n");
	while (i < 1800)
	{
//		printf("here 1\n");
//		dist = find_min(vertical_hit_dist(game, ray_angle),
//						horizont_hit_dist(game, ray_angle));
//		if (ray_angle > M_PI_2 - 0.0174533 && ray_angle < M_PI_2 + 0.0349)
//			ray_angle -= 0.0174533;
		dist = find_min_dist(vertical_hit_dist(game, ray_angle),
						horizont_hit_dist(game, ray_angle));
//		printf("here 2\n");
		if (fix_angle((*game)->player_angle - ray_angle) != M_PI_2 && fix_angle((*game)->player_angle - ray_angle) != M_PI_2 * 3)
			dist.dist = dist.dist * cos(fix_angle((*game)->player_angle - ray_angle));
//		if (dist.dist < 0)
//		{
//			ray_angle = fix_angle(ray_angle - 0.001745);
////			i++;
//			continue ;
//		}
		line_height = 64 * (MAP_WIDTH / 2 / tan(M_PI_2 / 3)) / dist.dist;
//		printf("height: %d\n", line_height);
		if (line_height > MAP_HEIGHT)
			line_height = MAP_HEIGHT;
		y_start = MAP_HEIGHT / 2 - (line_height / 2);
//		int y_end = y_start + line_height;
//		printf("height: %d\n", line_height);
		while (y_start <= line_height)
		{
			my_mlx_pixel_put((*game)->img, x, y_start, dist.color);
			y_start++;
		}
		x += MAP_WIDTH / 1800;

		ray_angle = fix_angle(ray_angle - 0.00058177);
		i++;
	}
}

void	draw_player(t_game **game)
{

	int y_start = (*game)->player_y / 64 * CELL_SIZE;
	int y_end = (*game)->player_y / 64 * CELL_SIZE + CELL_SIZE - 1;
	int x_start = (*game)->player_x / 64 * CELL_SIZE;
	while (y_end >= y_start)
	{
		int x_end = (*game)->player_x / 64 * CELL_SIZE + CELL_SIZE - 1;
//		printf("x_end: %i, x_start: %i\n", x_end, x_start);
		while (x_end >= x_start)
		{
//			printf("drawing player\n");
			my_mlx_pixel_put((*game)->img, x_end, y_end, 0x0000FF);
			x_end--;
		}
		y_end--;
	}
//	int	i = 0;
//	while (i < 10)
//	{
//		int	y = (*game)->player_y - sin((*game)->player_angle) * 5;
//		int	x = (*game)->player_x + cos((*game)->player_angle) * 5;
//		my_mlx_pixel_put((*game)->img, x, y, 0x0000FF);
////		y += (*game)->player_y * sin;
////		x += (*game)->player_xd / 5;
//		i++;
//	}
//	draw_rays(game);
}

void	draw_cell(t_game **game, int x, int y)
{
//	printf("x: %i, y: %i\n", x, y);
	int y_end = y * CELL_SIZE + CELL_SIZE - 1;
	int x_end = x * CELL_SIZE + CELL_SIZE - 1;
//	int y_end = y * CELL_SIZE + CELL_SIZE / 2;
//	int x_end = x * CELL_SIZE + CELL_SIZE / 2;
	int x_start;
//	int y_start = y * CELL_SIZE - CELL_SIZE / 2;
	int y_start = y * CELL_SIZE;
	int	color;
//	if ((*game)->map->map[y][x] == '1')
		color = 0xFF9933;
//	else if ((*game)->map->map[y][x] != ' ')
//		color = 0xFFFFFF;
//	else
//		color = 0x778899;
//	printf("draw cell start\n");
	while (y_start < y_end)
	{
//		x_start = x * CELL_SIZE - CELL_SIZE / 2;
		x_start = x * CELL_SIZE;
		while (x_start < x_end)
		{
//			printf("x: %i, y: %i\n", x, y);
			my_mlx_pixel_put((*game)->img, x_start, y_start, color);
			x_start++;
		}
		y_start++;
	}
//	printf("draw cell end\n");
}

void	draw_black(t_game **game)
{
	int y = 0;
	while (y < MAP_HEIGHT)
	{
		int x = 0;
//		while (x < (*game)->map_width * MAP_WIDTH)
		while (x < MAP_WIDTH)
		{
			my_mlx_pixel_put((*game)->img, x, y, 0xFDEE00);
			x++;
		}
		y++;
	}
}

void	draw_map(t_game **game)
{
	int x;
	int y = 0;
	while (y < (*game)->map->length)
	{
		x = 0;
//		printf("%s\n", (*game)->map->map[y]);
		while (x < (*game)->map_width)
		{
//			printf("here 2\n");
			if ((*game)->map->map[y][x] == '1')
				draw_cell(game, x, y);
//			printf("here 2\n");
			x++;
		}
		y++;
	}
	draw_player(game);
}

static int i;

int	draw(t_game **game)
{
	if (i % 100 == 0)
	{
		i = 0;
		draw_black(game);
		draw_rays(game);
		draw_map(game);
//		printf("here\n");
		mlx_put_image_to_window((*game)->mlx_ptr, (*game)->window_ptr, (*(*game)->img).img_ptr, 0, 0);
	}
	i++;
	return (0);
}

int	handle_input(int key, t_game **game)
{
	if (key == XK_Escape)
		clean_and_exit_no_error(game);
	if (key == XK_Left)
	{
		(*game)->player_angle += 0.1;
		if ((*game)->player_angle > 2 * M_PI)
			(*game)->player_angle -= M_PI * 2;
	}
	else if (key == XK_Right)
	{
		(*game)->player_angle -= 0.1;
		if ((*game)->player_angle < 0)
			(*game)->player_angle += 2 * M_PI;
//		printf("angle: %f\n", (*game)->player_angle);
	}
	else if (key == XK_w)
	{
		int	y = (*game)->player_y - sin((*game)->player_angle) * 5;
		int	x = (*game)->player_x + cos((*game)->player_angle) * 5;
		if ((*game)->map->map[(y) / 64][(x) / 64] == '0' || (*game)->map->map[(y) / 64][(x) / 64] == 'N')
		{
			(*game)->player_y = y;
			(*game)->player_x = x;
		}
	}
	else if (key == XK_s)
	{
		int	y = (*game)->player_y + sin((*game)->player_angle) * 5;
		int	x = (*game)->player_x - cos((*game)->player_angle) * 5;
		if ((*game)->map->map[(y) / 64][(x) / 64] == '0' || (*game)->map->map[(y) / 64][(x) / 64] == 'N')
		{
			(*game)->player_y = y;
			(*game)->player_x = x;
		}
	}
	else if (key == XK_d)
	{
		int	y = (*game)->player_y + cos((*game)->player_angle) * 5;
		int	x = (*game)->player_x + sin((*game)->player_angle) * 5;
		if ((*game)->map->map[(y) / 64][(x) / 64] == '0' || (*game)->map->map[(y) / 64][(x) / 64] == 'N')
		{
			(*game)->player_y = y;
			(*game)->player_x = x;
		}
	}
	else if (key == XK_a)
	{
		int	y = (*game)->player_y - cos((*game)->player_angle) * 5;
		int	x = (*game)->player_x - sin((*game)->player_angle) * 5;
		if ((*game)->map->map[(y) / 64][(x) / 64] == '0' || (*game)->map->map[(y) / 64][(x) / 64] == 'N')
		{
			(*game)->player_y = y;
			(*game)->player_x = x;
		}
	}
//	draw(game);
	return (0);
}

//int	escape(t_game **game)
//{
//	clean_and_exit("", game);
//	return (0);
//}

int main(int args, char *argv[]) {
	t_game	*game;

	if (args != 2)
		exit_with_error("Specify one map", 0);
//	game = initialize_game(argv[1]);
	game = parse_textures(argv[1]);
	parse_map(&game);
	check_map(&game);
//	create_cos_array(&game);
//	game->player_angle = M_PI_2;

	game->mlx_ptr = mlx_init();
	t_img	img;

	game->img = &img;
	img.img_ptr = mlx_new_image(game->mlx_ptr, MAP_WIDTH, MAP_HEIGHT);
	img.img_pixels_ptr = mlx_get_data_addr(img.img_ptr, &img.bits_per_pixel, &img.line_len,
								 &img.endian);
	game->window_ptr = mlx_new_window(game->mlx_ptr, MAP_WIDTH, MAP_HEIGHT, "cub3D");
	draw(&game);
//	mlx_put_image_to_window(game->mlx_ptr, game->window_ptr, img.img_ptr, 0, 0);
	mlx_hook(game->window_ptr, KeyPress, KeyPressMask, handle_input, &game);
	mlx_loop_hook(game->mlx_ptr, draw, &game);
	mlx_hook(game->window_ptr,
			 DestroyNotify, ButtonPressMask, clean_and_exit_no_error, &game);
	mlx_loop(game->mlx_ptr);
//	int i = 0;
//	t_stack	*stack = game->stack;
//	while (stack)
//	{
//		if (game->map->map)
//			printf("%s\n", game->map->map[i]);
//		stack = stack->next;
//		i++;
//	}
//	game =
	return (0);
}
