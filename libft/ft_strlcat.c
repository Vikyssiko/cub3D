/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkozlova <vkozlova@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 16:08:35 by vkozlova          #+#    #+#             */
/*   Updated: 2023/05/25 08:56:48 by vkozlova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/libft.h"
// #include <string.h>

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t			dst_len;
	unsigned int	i;
	unsigned int	x;

	i = 0;
	x = 0;
	while (dst[x])
		x++;
	dst_len = x;
	while (src[i])
		i++;
	if (dstsize <= x)
		return (i + dstsize);
	while (*src && x < dstsize - 1)
	{
		dst[x++] = *src;
		src++;
	}
	dst[x] = '\0';
	return (dst_len + i);
}

// int main () {
//    char dst[20] = "HI ";
//    char src[20] = "Hello world!";
//    printf("%zu\n", ft_strlcat(dst, src, 10));
//    printf("%s\n", dst);

//    char dst_o[20] = "HI ";
//    char src_o[20] = "Hello world!";
//    printf("%zu\n", strlcat(dst_o, src_o, 10));
//    printf("%s\n", dst_o);

//    char dst1[20] = "HI ";
//    char src1[20] = "Hello world!";
//    printf("%zu\n", ft_strlcat(dst1, src1, 5));
//    printf("%s\n", dst1);

//    char dst_o1[20] = "HI ";
//    char src_o1[20] = "Hello world!";
//    printf("%zu\n", strlcat(dst_o1, src_o1, 5));
//    printf("%s\n", dst_o1);

//    char dst2[20] = "HI ";
//    char src2[20] = "Hello world!";
//    printf("%zu\n", ft_strlcat(dst2, src2, 30));
//    printf("%s\n", dst2);

// 	char dst2_o[20] = "HI ";
// 	char src2_o[20] = "Hello world!";
// 	printf("%zu\n", strlcat(dst2_o, src2_o, 30));
// 	printf("%s\n", dst2_o);
// }