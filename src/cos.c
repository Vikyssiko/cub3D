/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cos.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkozlova <vkozlova@student.42wolfsburg.d>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 17:17:26 by vkozlova          #+#    #+#             */
/*   Updated: 2024/02/15 17:17:30 by vkozlova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3D.h"

void	create_cos_array(t_game **game)
{
	int		i;
	double	cosin;

	i = 0;
	while (i < 360)
	{
		cosin = cos(i * 0.0174533);
		if (cosin < 0)
			cosin = -cosin;
		if (i == 90 || i == 270)
			cosin = 0.000001;
		(*game)->cos_array[i] = cosin;
		i++;
	}
}
