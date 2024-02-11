/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkozlova <vkozlova@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 08:42:24 by vkozlova          #+#    #+#             */
/*   Updated: 2023/05/18 10:09:30 by vkozlova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/libft.h"
// #include <string.h>

// int	atoi(const char *str);

int	ft_atoi(const char *str)
{
	int	sign;
	int	result;

	result = 0;
	sign = 1;
	while (*str && (*str == '\t' || *str == '\n' || *str == '\v'
			|| *str == '\f' || *str == '\r' || *str == ' '))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + (*str - 48);
		str++;
	}
	result *= sign;
	return (result);
}

// int main(void)
// {
// 	printf("%d\n", atoi("   -") == ft_atoi("   -"));
// 	printf("%d\n", atoi("123456789") == ft_atoi("123456789"));
// 	printf("%d\n", atoi("12345A6789") == ft_atoi("12345A6789"));
// 	printf("%d\n", atoi("-123456789") == ft_atoi("-123456789"));
// 	printf("%d\n", atoi("0123456789") == ft_atoi("0123456789"));
// 	printf("%d\n", atoi("  -+--123456789") == ft_atoi("  -+--123456789"));
// 	printf("%d\n", atoi("  ---1234 56789") == ft_atoi("  ---1234 56789"));
// 	printf("%d\n", atoi("  -+- -123456789") == ft_atoi("  -+- -123456789"));
// 	printf("%d\n", atoi("  -1234 56789") == ft_atoi("  -1234 56789"));
// 	printf("%d\n", atoi("  - -1234 56789") == ft_atoi("  - -1234 56789"));
// 	printf("%d\n", atoi("  +1234 56789") == ft_atoi("  +1234 56789"));
// 	printf("%d\n", atoi("abc") == ft_atoi("abc"));
// 	printf("%d\n", atoi("") == ft_atoi(""));
// }