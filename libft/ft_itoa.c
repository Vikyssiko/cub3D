/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkozlova <vkozlova@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 20:17:18 by vkozlova          #+#    #+#             */
/*   Updated: 2023/05/23 11:11:23 by vkozlova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/libft.h"

static int		find_length(int n);

char	*ft_itoa(int n)
{
	char	*str;
	int		length;

	length = find_length(n);
	str = malloc(length + 1);
	if (str == NULL)
		return (NULL);
	if (n == 0)
		str[0] = 48;
	str[length--] = '\0';
	while (n != 0)
	{
		if (n < 0)
		{
			*str = '-';
			str[length--] = (n % 10) * (-1) + 48;
			n = n / (-10);
			n *= -1;
			continue ;
		}
		str[length--] = n % 10 + 48;
		n = n / 10;
	}
	return (str);
}

static int	find_length(int n)
{
	int	length;

	length = 0;
	if (n == -2147483648)
		return (11);
	if (n <= 0)
	{
		length++;
		n *= -1;
	}
	while (n > 0)
	{
		n = n / 10;
		length++;
	}
	return (length);
}

// int main()
// {
// 	printf("%s\n", ft_itoa(-9874));
// 	printf("%s\n", ft_itoa(12345));
// 	printf("%s\n", ft_itoa(0));
// 	printf("%s\n", ft_itoa(1));
// 	printf("%s\n", ft_itoa(-1));
// 	printf("%s\n", ft_itoa(2));
// 	printf("%s\n", ft_itoa(-2));
// 	printf("%s\n", ft_itoa(-1234));
// 	printf("%s\n", ft_itoa(2147483647));
// 	printf("%s\n", ft_itoa(-2147483648));
// }