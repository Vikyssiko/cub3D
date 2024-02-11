/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkozlova <vkozlova@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 14:42:24 by vkozlova          #+#    #+#             */
/*   Updated: 2023/05/18 19:08:15 by vkozlova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *s1)
{
	int		index;
	char	*s2;
	char	*s1_ptr;

	s1_ptr = (char *)s1;
	index = 0;
	s2 = malloc(ft_strlen(s1_ptr) * sizeof(char) + 1);
	if (!s2)
		return (NULL);
	while (s1 && s1[index])
	{
		s2[index] = s1[index];
		index++;
	}
	s2[index] = '\0';
	return (s2);
}

// int		main(void)
// {
// 	printf("%s\n", ft_strdup("Hello world"));
// 	printf("%s\n", ft_strdup(""));
// }