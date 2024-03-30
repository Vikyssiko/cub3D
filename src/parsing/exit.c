/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkozlova <vkozlova@student.42wolfsburg.d>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 12:26:05 by vkozlova          #+#    #+#             */
/*   Updated: 2024/02/11 12:26:11 by vkozlova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3D.h"

void	clean_and_exit(char *message, t_game **game)
{
	write(2, "Error\n", 6);
	write(2, message, ft_strlen(message));
	close((*game)->fd);
	if ((*game)->map)
		free_map(game);
	free_card_dir_img(game);
//	free_game(game);
	free(*game);
	exit(1);
}

int	clean_and_exit_no_error(t_game **game)
{
	close((*game)->fd);
	free_game(game);
	free(*game);
	exit(1);
}

void	exit_with_error(char *message, int fd)
{
	write(2, "Error\n", 6);
	write(2, message, ft_strlen(message));
	write(2, "\n", 1);
	if (fd)
		close(fd);
	exit(1);
}
