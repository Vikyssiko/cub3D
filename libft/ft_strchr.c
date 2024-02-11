/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkozlova <vkozlova@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 12:13:31 by vkozlova          #+#    #+#             */
/*   Updated: 2023/05/25 11:29:33 by vkozlova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*str;

	str = (char *)s;
	while (*str)
	{
		if (*str == (char)c)
			return (str);
		str++;
	}
	if (!(char)c)
		return (str);
	return (NULL);
}

// #include <string.h>
// int main(void)
// {
// 	printf("%s\n", ft_strchr("Hello world!", 'l'));
// 	printf("%s\n", ft_strchr("Hello world!", '\0'));
// 	printf("%s\n", strchr("Hello world!", '\0'));
// 	printf("%d\n", strchr("Hello world!", '\0') 
// == ft_strchr("Hello world!", '\0'));
// 	printf("%s\n", ft_strchr("Hello world!", 'e'));
// 	printf("%s\n", ft_strchr("Hello world!", ' '));
// 	printf("%s\n", ft_strchr("Hello world!", 'a'));
// 	return (0);
// }