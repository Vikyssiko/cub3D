/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkozlova <vkozlova@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 13:39:48 by vkozlova          #+#    #+#             */
/*   Updated: 2023/05/22 19:08:04 by vkozlova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/libft.h"
// #include <string.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const char	*s1_chars;
	const char	*s2_chars;

	s1_chars = s1;
	s2_chars = s2;
	while (n)
	{
		if (*s1_chars != *s2_chars)
			return ((unsigned char)*s1_chars - (unsigned char)*s2_chars);
		n--;
		s1_chars++;
		s2_chars++;
	}
	return (0);
}

// int	main(void)
// {
// 	printf("%d\n", ft_memcmp("Hello", "Hello world", 5));
// 	printf("%d\n", memcmp("Hello", "Hello world", 5));

// 	printf("%d\n", ft_memcmp("Hello", "Hello world", 6));
// 	printf("%d\n", memcmp("Hello", "Hello world", 6));

// 	printf("%d\n", ft_memcmp("", "", 5));
// 	printf("%d\n", ft_memcmp("", "", 5));

// 	printf("%d\n", ft_memcmp("Hello\0abc", "Helloworld", 10));
// 	printf("%d\n", memcmp("Hello\0abc", "Helloworld", 10));

// 	printf("%d\n", ft_memcmp("Helo\0abc", "Hello world", 10));
// 	printf("%d\n", memcmp("Helo\0abc", "Hello world", 10));
// }