/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkozlova <vkozlova@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 11:31:20 by vkozlova          #+#    #+#             */
/*   Updated: 2023/05/21 16:10:47 by vkozlova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/libft.h"
#include <stdlib.h>

void	*ft_calloc(size_t count, size_t size)
{
	int	*memory;
	int	c;

	c = size * count;
	memory = malloc(c);
	if (memory == NULL)
		return (NULL);
	ft_bzero(memory, c);
	return (memory);
}

// int main(void)
// {
// 	int x = 12;
// 	int *mem = ft_calloc(3, 4);
// 	while (x)
// 	{
// 		printf("%c\n", *mem);
// 		x--;
// 	}
// 	printf("%s\n", "original: ");
// 	x = 12;
// 	int *m = calloc(3, 4);
// 	while (x)
// 	{
// 		printf("%c\n", *m);
// 		x--;
// 	}
// }