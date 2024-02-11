/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkozlova <vkozlova@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 20:20:36 by vkozlova          #+#    #+#             */
/*   Updated: 2023/05/20 20:46:27 by vkozlova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	int	index;

	index = 0;
	while (*s)
	{
		f(index++, s++);
	}
}

// void function(unsigned int i, char *c)
// {
// 	*c = *c + i;
// }

// int main()
// {
// 	char str[20] = "12345abcABC";
// 	ft_striteri(str, function);
// 	printf("%s\n", str);

// 	char str1[7] = "111111";
// 	ft_striteri(str1, function);
// 	printf("%s\n", str1);

// 	char str2[7] = "";
// 	ft_striteri(str2, function);
// 	printf("%s\n", str2);
// }