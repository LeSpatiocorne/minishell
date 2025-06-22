/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hexa_convert.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-brie <mle-brie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 08:46:45 by mle-brie          #+#    #+#             */
/*   Updated: 2024/11/27 10:56:30 by mle-brie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*hexformula(unsigned long n)
{
	char			*hex;
	char			*result;
	unsigned long	temp;
	int				len;

	hex = "0123456789abcdef";
	temp = n;
	len = 1;
	while (temp > 15)
	{
		temp /= 16;
		len++;
	}
	result = (char *)malloc(len + 1);
	if (!result)
		return (NULL);
	result[len] = '\0';
	while (len-- > 0)
	{
		result[len] = hex[n % 16];
		n /= 16;
	}
	return (result);
}

// int	main(void)
// {
// 	int	test = 123456789;

// 	printf("decimal number: %d\n", test);
// 	printf("hexadecimal version: %s\n", hexformula(test));
// 	return (0);
// }

/*
result[] is set to 9 because hex digits are max 8 for some reason ????????
	and we're polite, we let \0 be
set i to 9 because we'll start by the end, say 9 is \0
now, deal with the n=0 situation, by returning the char 0
now, the magic happens : while n is a concept and that i isn't 0
	we modulo n by 16 inside hex to use it as a sort of array
	and this applies inside result[--i] because we start from the end
	=> then, divide n by 16 to go to the next character so it loops
as such, we have stocked every number inside result[i] in the *right* order
	so we return the adress(es) of [i].
*/