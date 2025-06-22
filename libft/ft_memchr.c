/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-brie <mle-brie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 11:34:55 by mle-brie          #+#    #+#             */
/*   Updated: 2024/11/14 16:20:17 by mle-brie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*str;

	str = s;
	while (n--)
	{
		if (*str == (unsigned char)c)
			return ((unsigned char *)str);
		str++;
	}
	return (NULL);
}
// int main(void)
// {
// 	unsigned char	test[] = "ceci est un test";
// 	char	*res_ori = memchr(test, 'i', 6);
// 	char	*res_cop = ft_memchr(test, 'i', 6);

// 	printf("%p\n", test);
// 	printf("%p\n", res_ori);
// 	printf("%p\n", res_cop);
// 	return (0);
// }