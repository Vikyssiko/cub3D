/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkozlova <vkozlova@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 12:55:50 by vkozlova          #+#    #+#             */
/*   Updated: 2023/05/22 19:08:59 by vkozlova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/libft.h"
// #include <string.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	while (n && (s1 || s2))
	{
		if (*s1 != *s2 || !*s1 || !*s2)
			return ((unsigned char)*s1 - (unsigned char)*s2);
		n--;
		s1++;
		s2++;
	}
	return (0);
}

// int	main(void)
// {
// 	printf("%d\n", ft_strncmp("test", "testss", 5));
	// printf("%d\n", ft_strncmp("abcdef", "abc\375xx", 5));
// 	printf("%d\n", ft_strncmp("Hello", "Hello world", 5));
// 	printf("%d\n", strncmp("Hello", "Hello world", 5));

// 	printf("%d\n", ft_strncmp("Hello", "Hello world", 6));
// 	printf("%d\n", strncmp("Hello", "Hello world", 6));

// 	printf("%d\n", ft_strncmp("", "", 5));
// 	printf("%d\n", strncmp("", "", 5));

// 	printf("%d\n", ft_strncmp("Hello\0abc", "Hello world", 10));
// 	printf("%d\n", strncmp("Hello\0abc", "Hello world", 10));

// 	printf("%d\n", ft_strncmp("Hello\0abc", "Hello\0world", 10));
// 	printf("%d\n", strncmp("Hello\0abc", "Hello\0world", 10));

// 	printf("%d\n", ft_strncmp("Helo\0abc", "Hello world", 10));
// 	printf("%d\n", strncmp("Helo\0abc", "Hello world", 10));

// 	printf("%d\n", ft_strncmp("Helo abc", "Hello\0world", 10));
// 	printf("%d\n", strncmp("Helo abc", "Hello\0world", 10));
// }