/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-brie <mle-brie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 15:47:12 by mle-brie          #+#    #+#             */
/*   Updated: 2024/11/14 16:01:14 by mle-brie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	while (*str != '\0')
	{
		if (*str == (char)c)
			return ((char *)str);
		str++;
	}
	if ((char)c == '\0')
		return ((char *)str);
	return (NULL);
}

// int	main(void)
// {
// 	char	letter = '\0';
// 	const char	*test = "voila un petit test";

// 	printf("%p\n", strchr(test, letter));
// 	printf("%p\n", ft_strchr(test, letter));
// 	return (0);
// }