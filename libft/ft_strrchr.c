/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-brie <mle-brie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 15:40:18 by mle-brie          #+#    #+#             */
/*   Updated: 2024/11/14 15:19:31 by mle-brie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, char c)
{
	char	*here;

	here = NULL;
	while (*str != '\0')
	{
		if (*str == c)
			here = (char *)str;
		str++;
	}
	if (c == '\0')
		here = (char *)str;
	return (here);
}

// int	main(void)
// {
// 	char	letter = '\0';
// 	const char	*test = "voila un petit test";

// 	printf("%p\n", strrchr(test, letter));
// 	printf("%p\n", ft_strrchr(test, letter));
// 	return (0);
// }