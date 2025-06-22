/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-brie <mle-brie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 13:53:36 by mle-brie          #+#    #+#             */
/*   Updated: 2024/11/05 14:47:54 by mle-brie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	len;

	len = 0;
	while (src[len] != '\0')
		len++;
	if (size == 0)
		return (len);
	i = 0;
	while ((i < size - 1) && i < len)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (len);
}
/*int	main(void)
{
	char	dest[0];
	char	source[] = "Testing";
	size_t	result;
	
	result = ft_strlcpy(dest, source, sizeof(dest));
	printf("source says : <<%s>>\n", source);
	printf("with its length being : %zu\n", result);
	printf("dest reads : <<%s>>\n", dest);
	printf("with its size of : %zu\n", sizeof(dest));
	return (0);
}*/

/*strlcpy : copies in dest, a SIZE amount of characters from source
SIZE being the buffer of dest, so an imuable quantity
	determined by >sizeof(dest)<
so you do a strcpy and a strlen at the same time,
	returning the len because that's what we need
coz strlcpy purposes is to see if there's a difference
	between the buffer of dest, and the return value (len)
	--> check is there's any truncation//losses*/