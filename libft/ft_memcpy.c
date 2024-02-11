/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkozlova <vkozlova@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 10:39:26 by vkozlova          #+#    #+#             */
/*   Updated: 2023/05/22 14:46:23 by vkozlova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned const char	*chars;
	unsigned char		*to_char;

	chars = src;
	to_char = dst;
	if (dst == src)
		return (dst);
	while (n)
	{
		*to_char++ = *chars++;
		n--;
	}
	return (dst);
}

// int main () {
//    char dst[50] = "This is lidft.h library function";
//    char src[50] = "It isn't lidft.h library function";
//    printf("%s\n", dst);

//    ft_memcpy(dst, src, 10);
//    printf("%s\n", dst);
//    return(0);
// }