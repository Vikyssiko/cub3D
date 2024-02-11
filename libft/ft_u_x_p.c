/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_u_x_p.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkozlova <vkozlova@student.42wolfsburg.d>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 21:41:06 by vkozlova          #+#    #+#             */
/*   Updated: 2023/08/09 21:41:06 by vkozlova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "header/libft.h"

int	print_unsigned_int(unsigned int i, int len)
{
	unsigned char	c;
	int				temp_len;

	c = i % 10 + 48;
	if (i / 10)
	{
		temp_len = print_unsigned_int(i / 10, len);
		if (temp_len < 0)
			return (-1);
		len += temp_len;
	}
	len += write(1, &c, 1);
	return (len);
}

int	print_hex(unsigned int x, int len, char symbol)
{
	unsigned char	c;
	int				temp_len;

	c = x % 16;
	if (c <= 9)
		c += 48;
	else
		c += symbol - 10;
	if (x / 16)
	{
		temp_len = print_hex(x / 16, len, symbol);
		if (temp_len < 0)
			return (-1);
		len += temp_len;
	}
	len += write(1, &c, 1);
	return (len);
}

int	print_ptr(unsigned long long x, int len)
{
	unsigned char	c;
	int				temp_len;

	c = x % 16;
	if (c <= 9)
		c += 48;
	else
		c += 87;
	if (x / 16)
	{
		temp_len = print_ptr(x / 16, len);
		if (temp_len < 0)
			return (-1);
		len += temp_len;
	}
	len += write(1, &c, 1);
	return (len);
}

int	print_int(int x, int space, int sign)
{
	char	*str;
	int		len;

	len = 0;
	str = ft_itoa(x);
	if (!str)
		return (-1);
	if (*str >= (0 + 48) && space == 1)
		len = write(1, " ", 1);
	if (*str >= (0 + 48) && sign == 1)
		len = write(1, "+", 1);
	if (len < 0)
		return (-1);
	len += print_string(str);
	free(str);
	return (len);
}
