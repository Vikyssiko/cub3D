/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strdupn.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkozlova <vkozlova@student.42wolfsburg.d>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 23:07:15 by vkozlova          #+#    #+#             */
/*   Updated: 2024/02/11 23:07:33 by vkozlova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3D.h"

char	*strdupn(const char *s1)
{
	int		index;
	char	*s2;
	char	*s1_ptr;
	int		len;

	s1_ptr = (char *)s1;
	index = 0;
	len = ft_strlen(s1_ptr);
	if (s1[len - 1] == '\n')
		len--;
	s2 = malloc(len * sizeof(char) + 1);
	if (!s2)
		return (NULL);
	while (index < len)
	{
		s2[index] = s1[index];
		index++;
	}
	s2[index] = '\0';
	return (s2);
}
