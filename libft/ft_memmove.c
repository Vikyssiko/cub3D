/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkozlova <vkozlova@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 12:44:46 by vkozlova          #+#    #+#             */
/*   Updated: 2023/05/22 19:09:44 by vkozlova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	const char		*chars;
	char			*to_char;
	size_t			index;

	index = len;
	chars = src;
	to_char = (char *)dst;
	if (dst == src)
		return (dst);
	if (src < dst)
	{
		while (index-- != 0)
		{
			to_char[index] = chars[index];
		}
		return (dst);
	}
	index = 0;
	while (index < len)
	{
		to_char[index] = chars[index];
		index++;
	}
	return (dst);
}

// int main () {
	// char str[] = "memmove can be very useful......";
	// ft_memmove("Hello world!","aaaaaaa",5);
	// printf("%s\n", str);
//    char dst[50] = "This is lidft.h library function";
//    char src[50] = "It isn't lidft.h library function";
//    printf("%s\n", dst);

//    ft_memmove(dst, src, 10);
//    printf("%s\n", dst);

//    char	src1[] = "lorem ipsum dolor sit amet";
// 	char	*dst1;
// 	dst1 = src1 + 1;
// 	if (dst1 != ft_memmove(dst1, src1, 8))
// 		write(1, "dest's adress was not returned\n", 31);
// 	write(1, dst1, 22);
//    printf("%s\n", dst1);

//    ft_memmove(dst1, src1, 10);
//    printf("%s\n", dst1);
//    return(0);
// }