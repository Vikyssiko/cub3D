/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkozlova <vkozlova@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 14:59:51 by vkozlova          #+#    #+#             */
/*   Updated: 2023/05/26 21:06:33 by vkozlova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/libft.h"
#include <stdlib.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*substring;
	unsigned int	index;
	int				sub_index;

	if (ft_strlen(s) < len)
		len = ft_strlen(s);
	substring = malloc(len + 1);
	if (substring == NULL)
		return (NULL);
	sub_index = 0;
	index = 0;
	while (s[index] && index != start)
		index++;
	while (index >= start && len && s[index])
	{
		substring[sub_index++] = s[index++];
		len--;
	}
	substring[sub_index++] = '\0';
	return (substring);
}

// int main(void)
// {
// 	printf("%s\n", ft_substr("Hello Wolfsburg!", 1, 15));
// 	printf("%s\n", ft_substr("Hello Wolfsburg!", 1, 15));

// 	printf("%s\n", ft_substr("Hello Wolfsburg!", 6, 10));
// 	printf("%s\n", ft_substr("Hello Wolfsburg!", 6, 10));

// 	printf("%s\n", ft_substr("Hello Wolfsburg!", 6, 5));
// 	printf("%s\n", ft_substr("Hello Wolfsburg!", 6, 5));
// }