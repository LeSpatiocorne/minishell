/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-brie <mle-brie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 14:21:20 by mle-brie          #+#    #+#             */
/*   Updated: 2024/11/19 16:51:44 by mle-brie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

int	num_length(int n)
{
	int	len;

	len = 0;
	if (n == 0)
		len = 1;
	if (n < 0)
	{
		len++;
		n = -n;
	}
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*oddities(int n)
{
	if (n == 0)
		return (ft_strdup("0"));
	if (n == INT_MIN)
		return (ft_strdup("-2147483648"));
	if (n == INT_MAX)
		return (ft_strdup("2147483647"));
	return (NULL);
}

static void	putnbr(int number, int length, char *result)
{
	while (length--)
	{
		result[length] = (number % 10) + '0';
		number /= 10;
	}
}

char	*ft_itoa(int n)
{
	char	*result;
	int		len;
	long	num;

	result = oddities(n);
	if (result)
		return (result);
	len = num_length(n);
	num = n;
	if (n < 0)
		num = -n;
	result = (char *)malloc(sizeof(char) * (len + 1));
	if (!result)
		return (NULL);
	result[len] = '\0';
	putnbr(num, len, result);
	if (n < 0)
		result[0] = '-';
	return (result);
}

// int	main(void)
// {
// 	int	test1 = -45631681;
// 	int	test2 = INT_MIN;
// 	int	test3 = '\0';
// 	int	test4 = 0;
// 	int	test5 = 5642312;

// 	printf("%s\n", ft_itoa(test1));
// 	printf("INT_MIN is : %d\n", INT_MIN);
// 	printf("my ITOA is : %s\n", ft_itoa(test2));
// 	printf("%s\n", ft_itoa(test3));
// 	printf("%s\n", ft_itoa(test4));
// 	printf("%s\n", ft_itoa(test5));
// 	return (0);
// }