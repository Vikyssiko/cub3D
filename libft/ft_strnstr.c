/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkozlova <vkozlova@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 21:12:12 by vkozlova          #+#    #+#             */
/*   Updated: 2023/05/26 19:50:13 by vkozlova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	char	*haystack_copy;
	char	*needle_copy;
	size_t	needle_size;

	haystack_copy = (char *)haystack;
	needle_copy = (char *)needle;
	needle_size = ft_strlen(needle_copy);
	if (!*needle)
		return ((char *)haystack);
	while (*haystack_copy && len && len >= needle_size)
	{
		if (ft_strncmp(haystack_copy, needle_copy, needle_size) == 0)
			return (haystack_copy);
		if (len - needle_size <= 0)
			return (NULL);
		haystack_copy++;
		needle_copy = (char *)needle;
		len--;
	}
	return (NULL);
}

// #include <string.h>
// int	main(void)
// {
// 	printf("%s\n", ft_strnstr("abcdefgh", "abc", 2));
// 	printf("%s\n", strnstr("abcdefgh", "abc", 2));

// 	printf("%s\n", ft_strnstr("Hello 42Wolfsburg", "Hello", 5));
// 	printf("%s\n", strnstr("Hello 42Wolfsburg", "Hello", 5));

// 	printf("%s\n", ft_strnstr("Hello 42Wolfsburg", "Hello", 6));
// 	printf("%s\n", strnstr("Hello 42Wolfsburg", "Hello", 6));

// 	printf("%s\n", ft_strnstr("Hello 42Wolfsburg", "42", 5));
// 	printf("%s\n", strnstr("Hello 42Wolfsburg", "42", 5));

// 	printf("%s\n", ft_strnstr("Hello 42Wolfsburg", "42Wolfsburg", 20));
// 	printf("%s\n", strnstr("Hello 42Wolfsburg", "42Wolfsburg", 20));

// 	printf("%s\n", ft_strnstr("abcd SSSAB", "SSAC", 3));
// 	printf("%s\n", strnstr("abcd SSSAB", "SSAC", 3));

// 	printf("%s\n", ft_strnstr("SSSA", "SSA", 3));
// 	printf("%s\n", strnstr("SSSA", "SSA", 3));

// 	printf("%s\n", ft_strnstr("SSSA", "SSA", 4));
// 	printf("%s\n", strnstr("SSSA", "SSA", 4));

// 	printf("%s\n", ft_strnstr("", "SSA", 4));
// 	printf("%s\n", strnstr("", "SSA", 4));

// 	printf("%s\n", ft_strnstr("SSSA", "", 3));
// 	printf("%s\n", strnstr("SSSA", "", 3));
// 	return (0);
// }