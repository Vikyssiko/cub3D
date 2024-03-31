/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkozlova <vkozlova@student.42wolfsburg.d>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 22:10:32 by vkozlova          #+#    #+#             */
/*   Updated: 2024/03/30 22:10:32 by vkozlova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3D.h"

void	check_color_len(char **rgb, t_game **game)
{
	int	i;

	i = 0;
	while (rgb[i])
		i++;
	if (i != 3)
		clean_and_exit("Colors in the map are not correct", game);
}

int	rgb_to_decimal(char *color_rgb, t_game **game)
{
	char	**rgb;
	int		i;
	int		color;
	int		multiplier;
	int		num;

	multiplier = 1;
	color = 0;
	rgb = ft_split(color_rgb, ',');
	check_color_len(rgb, game);
	i = 2;
	while (i >= 0)
	{
		num = ft_atoi(rgb[i]);
		if (num < 0 || num > 255)
			clean_and_exit("Colors in the map are not correct", game);
		color += num % 16 * multiplier;
		multiplier *= 16;
		color += num / 16 * multiplier;
		multiplier *= 16;
		i--;
	}
	free(color_rgb);
	free_string_array(rgb);
	return (color);
}
