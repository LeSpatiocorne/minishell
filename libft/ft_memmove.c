/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-brie <mle-brie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 16:12:49 by mle-brie          #+#    #+#             */
/*   Updated: 2024/11/14 14:55:08 by mle-brie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;

	d = dest;
	s = src;
	if (d > s)
	{
		while (n--)
			d[n] = s[n];
	}
	else
		ft_memcpy(dest, src, n);
	return (d);
}
/*int	main(void)
{
	unsigned char	test[] = "Hello, World!";
	unsigned char	try[] = "Bitches!";

	printf("%s\n", test);
	memmove(test + 7, try, 7);
	printf("%s\n", test);
	ft_memmove(test + 7, try, 7);
	printf("%s\n", test);
}*/