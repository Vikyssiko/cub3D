/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkozlova <vkozlova@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 13:12:35 by vkozlova          #+#    #+#             */
/*   Updated: 2023/05/26 19:49:08 by vkozlova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/libft.h"
// #include <string.h>

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	unsigned int	i;
	size_t			src_len;

	i = 0;
	src_len = ft_strlen((char *)src);
	if (dstsize == 0)
		return (src_len);
	while (src[i] != '\0' && i < dstsize - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (src_len);
}

// int main () {
//    char dst[30] = "HI";
//    char src[20] = "Hello world!";
//    printf("%zu\n", ft_strlcpy(dst, src, 10));
//    printf("%s\n", dst);

//    char dst_o[30] = "HI";
//    char src_o[20] = "Hello world!";
//    printf("%zu\n", ft_strlcpy(dst_o, src_o, 10));
//    printf("%s\n", dst_o);

//    char dst1[30] = "HI";
//    char src1[20] = "Hello world!";
//    printf("%zu\n", ft_strlcpy(dst1, src1, 20));
//    printf("%s\n", dst1);

//    char dst_o1[30] = "HI";
//    char src_o1[20] = "Hello world!";
//    printf("%zu\n", ft_strlcpy(dst_o1, src_o1, 20));
//    printf("%s\n", dst_o1);

//    char dst2[30] = "HI";
//    char src2[20] = "Hello world!";
//    printf("%zu\n", ft_strlcpy(dst2, src2, 3));
//    printf("%s\n", dst2);

//    char dst_o2[30] = "HI";
//    char src_o2[20] = "Hello world!";
//    printf("%zu\n", ft_strlcpy(dst_o2, src_o2, 3));
//    printf("%s\n", dst_o2);
// }