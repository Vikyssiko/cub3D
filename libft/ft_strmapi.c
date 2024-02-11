/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkozlova <vkozlova@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 19:05:53 by vkozlova          #+#    #+#             */
/*   Updated: 2023/05/23 21:07:20 by vkozlova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*str;
	int				size;
	unsigned int	index;

	index = 0;
	size = ft_strlen((char *)s);
	str = malloc(size + 1);
	if (str == NULL)
		return (NULL);
	while (s[index])
	{
		str[index] = f(index, s[index]);
		index++;
	}
	str[index] = '\0';
	return (str);
}

// char	function(unsigned int i, char c)
// {
// 	return (c + i);
// }

// int main()
// {
// 	printf("%s\n", ft_strmapi("11111", function));
// 	printf("%s\n", ft_strmapi("12345abcABC", function));
// 	printf("%s\n", ft_strmapi("", function));
// }