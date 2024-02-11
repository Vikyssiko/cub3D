/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkozlova <vkozlova@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 13:25:38 by vkozlova          #+#    #+#             */
/*   Updated: 2023/05/23 11:35:21 by vkozlova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/libft.h"
// #include <string.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	char	*str;

	str = (char *)s;
	while (n)
	{
		if (*str == (char)c)
		{
			return (str);
		}
		str++;
		n--;
	}
	return (NULL);
}

// int main(void)
// {
// 	printf("%s\n", ft_memchr("Hello world!", 'l', 15));
// 	printf("%s\n", memchr("Hello world!", 'l', 15));

// 	printf("%s\n", ft_memchr("Hello world!", '\0', 15));
// 	printf("%s\n", memchr("Hello world!", '\0', 15));

// 	printf("%d\n", memchr("Hello world!", '\0', 15) 
// == ft_memchr("Hello world!", '\0', 15));

// 	printf("%s\n", ft_memchr("Hello world!", '\0', 10));
// 	printf("%s\n", memchr("Hello world!", '\0', 10));
// 	printf("%d\n", memchr("Hello world!", '\0', 10) 
// == ft_memchr("Hello world!", '\0', 10));

// 	printf("%s\n", ft_memchr("Hello world!", 'e', 15));
// 	printf("%s\n", memchr("Hello world!", 'e', 15));

// 	printf("%s\n", ft_memchr("Hello world!", ' ', 15));
// 	printf("%s\n", memchr("Hello world!", ' ', 15));

// 	printf("%s\n", ft_memchr("Hello world!", 'a', 15));
// 	printf("%s\n", memchr("Hello world!", 'a', 15));
// 	return (0);
// }