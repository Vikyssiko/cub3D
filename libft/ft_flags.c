/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkozlova <vkozlova@student.42wolfsburg.d>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 12:27:28 by vkozlova          #+#    #+#             */
/*   Updated: 2023/08/10 12:27:28 by vkozlova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include "header/libft.h"

int	print_hex_with_flag(va_list ptr, char *buf, char symbol);

int	check_hash(va_list ptr, char *str)
{
	int				length;

	if (*str == 'x')
		length = print_hex_with_flag(ptr, "0x", 'a');
	else if (*str == 'X')
		length = print_hex_with_flag(ptr, "0X", 'A');
	else
		return (-1);
	return (length);
}

int	print_hex_with_flag(va_list ptr, char *buf, char symbol)
{
	unsigned int	num;
	int				length;
	int				len;

	length = 0;
	num = va_arg(ptr, unsigned int);
	if (num > 0)
		length = write(1, buf, 2);
	if (length < 0)
		return (-1);
	len = print_hex(num, 0, symbol);
	if (len < 0)
		return (-1);
	length += len;
	return (length);
}

int	check_conversion(char *str, va_list ptr, int space, int sign)
{
	int	len;

	if (!ft_strchr("cspdiuxX%", *str))
		return (-1);
	len = look_for_conversion(str, ptr, space, sign);
	if (len < 0)
		return (-1);
	return (len);
}

int	check_flag(char *str, va_list ptr)
{
	int		len;

	if (*str == '#')
		len = check_hash(ptr, ++str);
	else if (*str == ' ')
		len = check_conversion(++str, ptr, 1, 0);
	else if (*str == '+')
		len = check_conversion(++str, ptr, 0, 1);
	else
		len = check_conversion(str, ptr, 0, 0);
	return (len);
}
