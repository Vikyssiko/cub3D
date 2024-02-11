/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkozlova <vkozlova@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 18:21:17 by vkozlova          #+#    #+#             */
/*   Updated: 2023/05/25 19:13:39 by vkozlova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/libft.h"

static int		find_end_index(char const *s1, char const *set, int set_index);

static int		find_start_index(char const *s1, char const *set);

static char		*create_string(char const *s1, int size, int start_index);

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*result;
	int		start_index;
	int		size;

	size = ft_strlen(s1);
	if (!s1)
		return (NULL);
	if (ft_strlen(set) == 0 || size == 0)
		return (create_string(s1, size, 0));
	start_index = find_start_index(s1, set);
	size = find_end_index(s1, set, 0) - start_index + 1;
	if (size < 1)
	{
		result = malloc(1);
		if (result == NULL)
			return (NULL);
		*result = '\0';
		return (result);
	}
	return (create_string(s1, size, start_index));
}

static char	*create_string(char const *s1, int size, int start_index)
{
	char	*result;
	int		index;

	index = 0;
	result = malloc(size + 1);
	if (result == NULL)
		return (NULL);
	while (index < size)
		result[index++] = s1[start_index++];
	result[index] = '\0';
	return (result);
}

static int	find_start_index(char const *s1, char const *set)
{
	int	index;
	int	set_index;
	int	set_size;

	index = 0;
	set_index = 0;
	set_size = ft_strlen(set);
	while (s1[index])
	{
		while (set_index < set_size)
		{
			if (s1[index] != set[set_index])
			{
				set_index++;
				if (set_index == set_size)
					return (index);
			}
			else
				break ;
		}
		set_index = 0;
		index++;
	}
	return (index);
}

static int	find_end_index(char const *s1, char const *set, int set_index)
{
	int	index;
	int	set_size;
	int	s1_size;

	set_size = ft_strlen(set);
	s1_size = ft_strlen(s1);
	index = s1_size - 1;
	while (s1 + index)
	{
		while (set[set_index])
		{
			if (s1[index] != set[set_index])
			{
				set_index++;
				if (set_index == set_size)
					return (index);
			}
			else
				break ;
		}
		set_index = 0;
		index--;
	}
	return (index);
}

// int main(void)
// {
// 	printf("%s\n", ft_strtrim("", ""));
// 	printf("%s\n", ft_strtrim("./.a./....b/.", "/.c"));
// 	printf("%s\n", ft_strtrim("./../....b/.", "/.c"));
// 	printf("%s\n", ft_strtrim("c/", "/.c"));
// 	printf("%s\n", ft_strtrim(".", "/.c"));
// 	printf("%s\n", ft_strtrim("c", "/.c"));
// 	printf("%s\n", ft_strtrim("", "/.c"));
// 	printf("%s\n", ft_strtrim("|", "/.c"));
// }