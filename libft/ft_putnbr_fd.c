/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkozlova <vkozlova@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 12:29:09 by vkozlova          #+#    #+#             */
/*   Updated: 2023/05/23 11:50:21 by vkozlova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	rem;

	if (n == -2147483648)
		write(fd, "-2147483648", 11);
	else if (n < 0)
	{
		write(fd, "-", 1);
		ft_putnbr_fd(-(n), fd);
	}
	else if (n > 9)
	{
		ft_putnbr_fd(n / 10, fd);
		rem = n % 10 + 48;
		write(fd, &rem, 1);
	}
	else
	{
		rem = n + 48;
		write(fd, &rem, 1);
	}
}

// int main()
// {
// 	ft_putnbr_fd(0, 1);
// 	ft_putnbr_fd(12345, 1);
// 	ft_putnbr_fd(-12345, 1);
// 	ft_putnbr_fd(2147483647, 1);
// 	ft_putnbr_fd(-2147483648, 1);
// }