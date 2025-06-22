/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-brie <mle-brie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 13:31:39 by mle-brie          #+#    #+#             */
/*   Updated: 2024/11/07 14:05:32 by mle-brie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*str1;
	const unsigned char	*str2;

	str1 = s1;
	str2 = s2;
	while (n--)
	{
		if (*str1 != *str2)
			return (*str1 - *str2);
		str1++;
		str2++;
	}
	return (0);
}
/*int	main(void)
{
	char	test1[] = "phase test";
	char	test2[] = "phrase teste";
	
	int	res_or = memcmp(test1, test2, 25);
	int	res_cop = ft_memcmp(test1, test2, 25);
	printf("%d\n", res_or);
	printf("%d\n", res_cop);
	return (0);
}*/