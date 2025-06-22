/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-brie <mle-brie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 11:56:50 by mle-brie          #+#    #+#             */
/*   Updated: 2024/11/15 13:53:27 by mle-brie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// size_t	ft_strlen(const char *str)
// {
// 	size_t	len;

// 	len = 0;
// 	while (str[len] != '\0')
// 		len++;
// 	return (len);
// }

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*joined;
	size_t	i;

	joined = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (joined == NULL)
		return (NULL);
	i = 0;
	while (*s1)
	{
		joined[i] = *s1++;
		i++;
	}
	while (*s2)
	{
		joined[i] = *s2++;
		i++;
	}
	joined[i] = '\0';
	return (joined);
}
// int	main(void)
// {
// 	const char	*test1 = "this is a";
// 	const char	*test2 = "a sentence";

// 	printf("%s\n", ft_strjoin(test1, test2));
// 	return (0);
// }