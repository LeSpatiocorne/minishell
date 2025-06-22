/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-brie <mle-brie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 15:34:02 by mle-brie          #+#    #+#             */
/*   Updated: 2024/11/19 12:14:12 by mle-brie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;
	size_t				i;

	d = dest;
	s = src;
	i = 0;
	if (!dest && !src)
		return (NULL);
	while (n--)
	{
		d[i] = s[i];
		i++;
	}
	return (dest);
}

/*int	main(void)
{
	unsigned char	test[] = "oh, oh, tiens voila quelqu'un!";
	unsigned char	dest[50];
	unsigned char	*test1 = (void*)0;
	unsigned char	*dest1 = (void*)0;

	printf("%s\n", test);
	ft_memcpy(dest, test, 25);
	printf("%s\n", dest);
	memcpy(dest, test, 25);
	printf("%s\n", dest);
	ft_memcpy(dest1, test1, 3);
	printf("%s\n", dest1);
	return (0);
}*/