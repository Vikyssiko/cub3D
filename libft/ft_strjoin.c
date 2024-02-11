/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkozlova <vkozlova@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 16:11:48 by vkozlova          #+#    #+#             */
/*   Updated: 2023/05/19 11:41:52 by vkozlova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*result;
	size_t	s1_size;
	size_t	s2_size;
	int		index;

	index = 0;
	s1_size = ft_strlen((char *)s1);
	s2_size = ft_strlen((char *)s2);
	result = malloc(s1_size + s2_size + 1);
	if (result == NULL)
		return (NULL);
	while (*s1)
	{
		result[index++] = *s1;
		s1++;
	}
	while (*s2)
	{
		result[index++] = *s2;
		s2++;
	}
	result[index] = '\0';
	return (result);
}

// int main(void)
// {
// 	printf("%s\n", ft_strjoin("Hello ", "world!"));
// 	printf("%s\n", ft_strjoin("", "world!"));
// 	printf("%s\n", ft_strjoin("Hello ", "!"));
// }