/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-brie <mle-brie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 15:44:08 by mle-brie          #+#    #+#             */
/*   Updated: 2024/11/19 14:17:51 by mle-brie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	count_words(const char *str, char c)
{
	int	inside;
	int	words;

	inside = 0;
	words = 0;
	if (!str)
		return (0);
	while (*str)
	{
		if (*str != c && !inside)
		{
			inside = 1;
			words++;
		}
		else if (*str == c)
			inside = 0;
		str++;
	}
	return (words);
}

int	word_length(const char *str, char c)
{
	int	len;

	len = 0;
	while (str[len] && str[len] != c)
		len++;
	return (len);
}

static char	**free_up(int index, char **array)
{
	while (index--)
		free(array[index]);
	free(array);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	int		i;
	int		len;

	if (!s)
		return (NULL);
	result = (char **)ft_calloc(count_words(s, c) + 1, sizeof(char *));
	if (!result)
		return (NULL);
	i = 0;
	while (*s)
	{
		if (*s != c)
		{
			len = word_length(s, c);
			result[i] = ft_substr(s, 0, len);
			if (!result[i])
				return (free_up(i, result));
			s += len;
			i++;
		}
		else
			s++;
	}
	return (result);
}

/*use a word_length for a malloc of each * inside the **
so res[i] = (char *)malloc(sizeof(char) * length)*/

// int	main(void)
// {
// 	const char	*str = "ceci est un test et j'essaie des choses";
// 	char		c = ' ';
// 	char 		**test = ft_split(str, c);
// 	int			i = 0;

// 	while (test[i])
// 	{
// 		printf("%s\n", test[i]);
// 		i++;
// 	}	
// 	return (0);
// }