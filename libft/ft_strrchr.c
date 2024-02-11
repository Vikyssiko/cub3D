/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkozlova <vkozlova@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 12:30:44 by vkozlova          #+#    #+#             */
/*   Updated: 2023/05/23 21:35:15 by vkozlova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/libft.h"
// #include <string.h>

char	*ft_strrchr(const char *s, int c)
{
	char	*str;
	char	*res;

	str = (char *)s;
	res = NULL;
	while (*str)
	{
		if (*str == (char)c)
			res = str;
		str++;
	}
	if ((char)c == '\0')
		return (str);
	return (res);
}

// int main(void)
// {
// 	printf("%s\n", ft_strchr("Hello world!", 'l'));
// 	printf("%s\n", ft_strchr("Hello world!", '\0'));
// 	printf("%s\n", strchr("Hello world!", '\0'));
// 	printf("%s\n", ft_strchr("Hello world!", 'e'));
// 	printf("%s\n", ft_strchr("Hello world! I am a student", ' '));
// 	printf("%s\n", ft_strchr("Hello world! I am a student", 'a'));
// 	return (0);
// }