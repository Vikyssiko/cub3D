/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkozlova <vkozlova@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 13:39:58 by vkozlova          #+#    #+#             */
/*   Updated: 2023/05/17 09:41:58 by vkozlova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	char			*chars;
	unsigned char	int_to_char;

	chars = b;
	int_to_char = (unsigned char)c;
	while (len > 0)
	{
		*chars++ = int_to_char;
		len--;
	}
	return (b);
}

// int main () {
//    char str[50] = "This is lidft.h library function";
//    printf("%s\n", str);

//    ft_memset(str,'.',10);
//    printf("%s\n", str);
//    return(0);
// }