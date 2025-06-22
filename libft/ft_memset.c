/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-brie <mle-brie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 14:03:51 by mle-brie          #+#    #+#             */
/*   Updated: 2024/11/06 15:17:28 by mle-brie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*p;

	p = s;
	while (n--)
		*p++ = c;
	return (s);
}
/*int	main(void)
{
	char	test[] = "Password vibes here";

	printf("%s\n", test);
	ft_memset(test, '*', 8);
	printf("%s\n", test);
	memset(test, '*', 8);
	printf("%s\n", test);
	return (0);
}*/