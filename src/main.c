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

//void	move(t_game **game)
//{
//	if ()
//}

void	draw_player(t_game **game, t_img img)
{
	int y_start = (*game)->player_y + 2;
	int y_end = (*game)->player_y - 2;
	int x_start = (*game)->player_x + 2;
	while (y_end <= y_start)
	{
		int x_end = (*game)->player_x - 2;
		while (x_end <= x_start)
		{
			my_mlx_pixel_put(&img, x_end, y_end, 0x00FFFFFF);
			x_end++;
		}
		y_end++;
	}
}

int	handle_input(int key, t_game **game)
{
	printf("%i\n", key);
	(void )game;
//	if (key == XK_Escape)
//		clean_and_exit_no_error(map);
//	if (!(*map)->dead)
//	{
//		if (key == XK_w)
//			up(map);
//		else if (key == XK_s)
//			down(map);
//		else if (key == XK_a)
//			left(map);
//		else if (key == XK_d)
//			right(map);
//	}
	return (0);
}

int	keydown_hook(t_game **game)
{
	int	y = (*game)->player_y - 5;
	if ((*game)->map->map[y / 64][(*game)->player_x] != '1')
		(*game)->player_y -= 5;
	return (0);
}

int	keyup_hook(t_game **game)
{
	int	y = (*game)->player_y + 5;
	if ((*game)->map->map[y / 64][(*game)->player_x] != '1')
		(*game)->player_y += 5;
	return (0);
}

//int	escape(t_game **game)
//{
//	clean_and_exit("", game);
//	return (0);
//}


//int	find_dist(t_game **game)
//{
//
//}

int main(int args, char *argv[]) {
	t_game	*game;

	if (args != 2)
		exit_with_error("Specify one map", 0);
//	game = initialize_game(argv[1]);
	game = parse_textures(argv[1]);
	parse_map(&game);
	check_map(&game);
	create_cos_array(&game);
//	double i = 1.5;
//	modf(i, &i);
//	printf("%f\n", cos(0));



	game->mlx_ptr = mlx_init();
	t_img	img;

	img.img_ptr = mlx_new_image(game->mlx_ptr, 2048, 1024);
	img.img_pixels_ptr = mlx_get_data_addr(img.img_ptr, &img.bits_per_pixel, &img.line_len,
								 &img.endian);
	game->window_ptr = mlx_new_window(game->mlx_ptr, 2048, 1024, "cub3D");
	int y = 0;
	while (y < 1024)
	{
		int x = 0;
		while (x < 2048)
		{
			my_mlx_pixel_put(&img, x, y, 0x00FF0000);
			x++;
		}
		y++;
	}
	draw_player(&game, img);
//	int x = 200;

//	int angle = 15;
//	while (angle <= 75)
//	{
////		printf("here 6\n");
//		double dist = find_min(vertical_hit_dist(&game, angle), horizont_hit_dist(&game, angle));
////		printf("here 7\n");
////		double 	correct_dist = dist * cos((90 - angle) * 0.0174533);
////		printf("correct dist: %i\n", correct_dist);
////		printf("here\n");
//		int wall_height = 64 * 554 / dist;
////		printf("here 1\n");
//		int start_height = 200 - wall_height / 2;
////		printf("here 2\n");
//		while (wall_height)
//		{
////		printf("here\n");
////			printf("here 3\n");
//			my_mlx_pixel_put(&img, x, start_height++, 0x00FFFFFF);
////			printf("here 5\n");
//			wall_height--;
//		}
////		printf("wall height: %i\n", wall_height);
////		printf("start height: %i\n", start_height);
//		printf("angle: %i\n", angle);
//		angle++;
//		x--;
//	}
//	printf("here 4\n");
	mlx_put_image_to_window(game->mlx_ptr, game->window_ptr, img.img_ptr, 0, 0);
//	mlx_pixel_put(game->mlx_ptr, game->window_ptr, 300, 300, 0x00FFFFFF);
//	mlx_hook(game->mlx_ptr, 2, 1L << 0, keydown_hook, game);
//	mlx_hook(game->mlx_ptr, 3, 1L << 1, keyup_hook, game);
//	mlx_hook(game->mlx_ptr, 53, 1L << 0, escape, game);
	mlx_key_hook(game->mlx_ptr, keydown_hook, &game);
//	mlx_hook(game->window_ptr, KeyPress, KeyPressMask, handle_input, game);
//	mlx_hook(game->window_ptr,
//			 DestroyNotify, ButtonPressMask, clean_and_exit("", &game), game);
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
