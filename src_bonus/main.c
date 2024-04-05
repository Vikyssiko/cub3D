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

void	draw_background(t_game **game)
{
	int	color;
	int	y;
	int	x;

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

t_game	*parse_check_map(int args, char *argv[])
{
	t_game	*game;
	int		len;

	if (args != 2)
		exit_with_error("Specify one map", 0);
	len = ft_strlen(argv[1]);
	if (argv[1][len - 1] != 'b' || argv[1][len - 2] != 'u'
		|| argv[1][len - 3] != 'c' || argv[1][len - 4] != '.')
		exit_with_error("Map has to be in \".cub\" extension", 0);
	game = parse_textures(argv[1]);
	parse_map(&game);
	check_map(&game);
	return (game);
}

int	main(int args, char *argv[])
{
	t_game	*game;
	t_img	img;

	game = parse_check_map(args, argv);
	game->time = 0;
	game->mlx_ptr = mlx_init();
	init_textures(&game);
	game->img = &img;
	img.img_ptr = mlx_new_image(game->mlx_ptr, MAP_WIDTH, MAP_HEIGHT);
	img.img_pixels_ptr = mlx_get_data_addr(img.img_ptr, &img.bits_per_pixel,
			&img.line_len, &img.endian);
	game->window_ptr = mlx_new_window(game->mlx_ptr, MAP_WIDTH,
			MAP_HEIGHT, "cub3D");
	mlx_put_image_to_window(game->mlx_ptr, game->window_ptr, img.img_ptr, 0, 0);
	mlx_hook(game->window_ptr, MotionNotify, PointerMotionMask,
		mouse_move_hook, &game);
	mlx_hook(game->window_ptr, KeyPress, KeyPressMask,
		handle_input, &game);
	mlx_hook(game->window_ptr, KeyRelease, KeyReleaseMask,
		handle_release, &game);
	mlx_loop_hook(game->mlx_ptr, draw, &game);
	mlx_hook(game->window_ptr,
		DestroyNotify, ButtonPressMask, clean_and_exit_no_error, &game);
	mlx_loop(game->mlx_ptr);
	return (0);
}
