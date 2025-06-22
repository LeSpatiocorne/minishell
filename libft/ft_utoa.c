/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-brie <mle-brie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 10:57:09 by mle-brie          #+#    #+#             */
/*   Updated: 2025/05/01 14:34:09 by mle-brie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_utoa(unsigned int nUm)
{
	char			*result;
	int				len;
	unsigned long	temp;

	temp = nUm;
	len = 1;
	while (temp > 9)
	{
		temp /= 10;
		len++;
	}
	result = (char *)malloc(sizeof(char) * (len + 1));
	if (!result)
		return (NULL);
	result[len] = '\0';
	while (len--)
	{
		result[len] = (nUm % 10) + '0';
		nUm /= 10;
	}
	return (result);
}

// int	main(void)
// {
// 	unsigned int	test = 1234567890;
// 	char			*result = ft_utoa(test);
// 	printf("unsigned is %u\n", test);
// 	printf("function is %s\n", result);
// 	return (0);
// }