/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-brie <mle-brie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 14:48:55 by mle-brie          #+#    #+#             */
/*   Updated: 2024/11/05 15:37:12 by mle-brie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	d_len;
	size_t	s_len;
	size_t	i;

	d_len = 0;
	while (dst[d_len] != '\0' && d_len < size)
		d_len++;
	s_len = 0;
	while (src[s_len] != '\0')
		s_len++;
	if (d_len == size)
		return (size + s_len);
	i = 0;
	while (src[i] != '\0' && (d_len + i < size - 1))
	{
		dst[d_len + i] = src[i];
		i++;
	}
	dst[d_len + i] = '\0';
	return (d_len + s_len);
}

/*int	main(void)
{
	char	dest[0] = "";
	char	source[] = "world!";
	size_t	result;
	
	printf("dest says : <<%s>>\n", dest);
	printf("source says : <<%s>>\n", source);
	result = ft_strlcat(dest, source, sizeof(dest));
	printf("we concatened : <<%s>>\n", dest);
	printf("with a total length of : %zu\n", result);
	printf("using the place in dest : %zu\n", sizeof(dest));
	return (0);
}*/