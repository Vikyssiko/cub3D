/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkozlova <vkozlova@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 12:54:41 by vkozlova          #+#    #+#             */
/*   Updated: 2023/05/26 19:48:31 by vkozlova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/libft.h"

static int		count_words(char const *s, char c);

static int		find_word_size(char const *s, char c);

static char		*copy(char const *s, int len);

char	**ft_split(char const *s, char c)
{
	char	**result;
	int		words;
	int		index;
	int		len;

	index = 0;
	if (s == NULL)
		return (NULL);
	words = count_words(s, c);
	result = malloc(sizeof(char *) * (words + 1));
	if (result == NULL)
		return (NULL);
	while (*s)
	{
		if (*s != c)
		{
			len = find_word_size(s, c);
			result[index++] = copy(s, len);
			s = s + len;
		}
		else
			s++;
	}
	result[index] = NULL;
	return (result);
}

static int	find_word_size(char const *s, char c)
{
	int	size;

	size = 0;
	while (*s && *s != c)
	{
		size++;
		s++;
	}
	return (size);
}

static int	count_words(char const *s, char c)
{
	int		index;
	int		size;
	char	prev;

	index = 0;
	size = 0;
	prev = c;
	while (s[index])
	{
		if (s[index] != c && prev == c)
			size++;
		prev = s[index++];
	}
	return (size);
}

static char	*copy(char const *s, int len)
{
	int		index;
	char	*word;

	index = 0;
	word = malloc(sizeof(char) * (len + 1));
	if (word == NULL)
		return (NULL);
	while (index < len)
	{
		word[index] = s[index];
		index++;
	}
	word[index] = '\0';
	return (word);
}

//int main()
//{
//	char **array = ft_split("  NO  hoho ", ' ');
//	printf("%i\n", array[5] == NULL);
//}

// int main()
// {
// 	char	*str = "......";
// 	char	**result = ft_split(str, '.');
// 	int		index = 0;
// 	while (result[index])
// 	{
// 		printf("%s\n", result[index]);
// 		index++;
// 	}

// 	char	*str1 = "   lorem   ipsum dolor     sit  ";
// 	char	**result1 = ft_split(str1, ' ');
// 	int		index1 = 0;
// 	while (result1[index1])
// 	{
// 		printf("%s\n", result1[index1]);
// 		index1++;
// 	}

// 	char	*str0 = "abc";
// 	char	**result0 = ft_split(str0, '.');
// 	int		index0 = 0;
// 	while (result0[index0])
// 	{
// 		printf("%s\n", result[index]);
// 		index++;
// 	}
// 	char	*str1 = "abc..hello.baby...";
// 	char	**result1 = ft_split(str1, '.');
// 	int		index1 = 0;
// 	while (result1[index1])
// 	{
// 		printf("%s\n", result1[index1]);
// 		index1++;
// 	}

// 	char	*str2 = ".......hello";
// 	char	**result2 = ft_split(str2, '.');
// 	int		index2 = 0;
// 	while (result2[index2])
// 	{
// 		printf("%s\n", result2[index2]);
// 		index2++;
// 	}

// 	char	*str3 = "......";
// 	char	**result3 = ft_split(str3, '.');
// 	int		index3 = 0;
// 	while (result3[index3])
// 	{
// 		printf("%s\n", result3[index3]);
// 		index3++;
// 	}

// 	char	*str4 = "";
// 	char	**result4 = ft_split(str4, '.');
// 	int		index4 = 0;
// 	while (result4[index4])
// 	{
// 		printf("%s\n", result4[index4]);
// 		index4++;
// 	}	
// }