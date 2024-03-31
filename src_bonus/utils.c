/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkozlova <vkozlova@student.42wolfsburg.d>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 22:31:26 by vkozlova          #+#    #+#             */
/*   Updated: 2024/03/30 22:31:26 by vkozlova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3D.h"

double	find_min(double a, double b)
{
	if (a <= b)
		return (a);
	return (b);
}

t_dist	find_min_dist(t_dist vert, t_dist hor)
{
	if (vert.dist <= hor.dist)
		return (vert);
	return (hor);
}

double	fix_angle(double angle)
{
	double	radian;

	radian = 0.0174533;
	if (angle > 2 * M_PI - radian / 10)
		angle -= 2 * M_PI;
	else if (angle < 0)
		angle += 2 * M_PI;
	return (angle);
}
