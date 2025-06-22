/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-brie <mle-brie@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 16:10:16 by mle-brie          #+#    #+#             */
/*   Updated: 2025/05/14 16:33:11 by mle-brie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(char *src, size_t len)
{
	char		*dup;
	size_t		i;

	if (!src)
		return (NULL);
	i = 0;
	while (src[i])
		i++;
	if (i < len)
		exit(1);
	dup = (char *)malloc((len + 1) * sizeof(char));
	if (dup == NULL)
		return (NULL);
	i = 0;
	while (src[i] && i < len)
	{
		dup[i] = src[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

// int	main(void)
// {
// 	char	*test = "This is a test, thank you very much";
// 	char	*ndup = ft_strndup(test, 45);
// 	char	*true = strndup(test, 45);

// 	printf("mine : >>%s<<\n", ndup);
// 	printf("original : >>%s<<\n", true);
// 	return (0);
// }