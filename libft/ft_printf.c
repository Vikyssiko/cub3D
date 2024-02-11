/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkozlova <vkozlova@student.42wolfsburg.d>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 21:22:09 by vkozlova          #+#    #+#             */
/*   Updated: 2023/07/03 21:22:09 by vkozlova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include "header/libft.h"

int	look_for_conversion(char *type, va_list ptr, int space, int sign);

int	write_str(va_list ptr, char *str);

int	check_conversion(char *str, va_list ptr, int space, int sign);

int	ft_printf(const char *format, ...)
{
	char	*str;
	va_list	ptr;
	int		length;

	va_start(ptr, format);
	str = (char *)format;
	length = write_str(ptr, str);
	va_end(ptr);
	return (length);
}

int	write_str(va_list ptr, char *str)
{
	int			length;
	int			len;

	length = 0;
	while (str && *str)
	{
		if (*str == '%')
		{
			str++;
			len = check_flag(str, ptr);
			if (*str == '#' || *str == ' ' || *str == '+')
				str++;
			if (len < 0)
				return (-1);
			length += len;
			str++;
			continue ;
		}
		if (write(1, str, 1) < 0)
			return (-1);
		length++;
		str++;
	}
	return (length);
}

int	print_character(char c)
{
	int	i;

	i = write(1, &c, 1);
	return (i);
}

int	print_string(char *str)
{
	int	length;
	int	len;

	length = 0;
	if (!str)
		length = write(1, "(null)", 6);
	while (str && *str)
	{
		len = print_character(*str);
		if (len < 0)
			return (-1);
		length += len;
		str++;
	}
	return (length);
}

int	look_for_conversion(char *type, va_list ptr, int space, int sign)
{
	if (*type == 'c' && space == 0 && sign == 0)
		return (print_character(va_arg(ptr, int)));
	if (*type == 's' && space == 0 && sign == 0)
		return (print_string(va_arg(ptr, char *)));
	if (*type == 'p' && space == 0 && sign == 0)
	{
		if (write(1, "0x", 2) < 0)
			return (-1);
		return (print_ptr(va_arg(ptr, unsigned long long), 0) + 2);
	}
	if (*type == 'i' || *type == 'd')
		return (print_int(va_arg(ptr, int), space, sign));
	if (*type == 'u')
		return (print_unsigned_int(va_arg(ptr, unsigned int), 0));
	if (*type == 'x' && space == 0 && sign == 0)
		return (print_hex(va_arg(ptr, unsigned int), 0, 'a'));
	if (*type == 'X' && space == 0 && sign == 0)
		return (print_hex(va_arg(ptr, unsigned int), 0, 'A'));
	if (*type == '%' && space == 0 && sign == 0)
		return (print_character('%'));
	return (-1);
}

//#include <stdio.h>
//int main(void)
//{
//	ft_printf("%#x\n", 0);
//	printf("%#x\n", 0);
//	ft_printf("%#x\n", 123456789);
//	printf("%#x\n", 123456789);
//	ft_printf("%#X\n", 123456789);
//	printf("%#X\n", 123456789);
//	printf("%i\n", ft_printf("%#X\n", 123456789));
//	printf("%i\n", printf("%#X\n", 123456789));
//	ft_printf("%+i\n", 0);
//	printf("%+i\n", 0);
//	ft_printf("%+i\n", -11111);
//	printf("%+i\n", -11111);
//	ft_printf("% i\n", 123);
//	printf("% i\n", 123);
//	ft_printf("% i\n", -123);
//	printf("% i\n", -123);
//	printf("%i\n", ft_printf("% i\n", 42));
//	printf("%i\n", printf("% i\n", 42));
//	printf("%i\n", ft_printf("%s", "some string with %s hehe"));
//	printf("%i\n", printf("%s", "some string with %s hehe"));
//	ft_printf("%c\n", 'a');
//	printf("%c\n", 'a');
//	ft_printf(" NULL %s NULL ", NULL);
//	printf(" NULL %s NULL ", NULL);
//	printf("%i\n", printf(" NULL %s NULL ", NULL));
//	ft_printf("%i\n", -2147483647);
//	printf("%i\n", -2147483647);
//	ft_printf("%x\n", 123456789);
//	printf("%x\n", 123456789);
//	ft_printf("%X\n", 123456789);
//	printf("%X\n", 123456789);
//    printf("%i\n", ft_printf("%x\n", 123456789)
//    == printf("%x\n", 123456789));
//}