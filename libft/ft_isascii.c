/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-brie <mle-brie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 13:47:37 by mle-brie          #+#    #+#             */
/*   Updated: 2024/11/14 11:57:46 by mle-brie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	else
		return (0);
}
/*#include <stdio.h>

int main(void)
{
	char	test = '...';
	if (ft_isascii(test))
		printf("%c is ascii\n", test);
	else
		printf("%c how the fuck can smthng not be ascii????\n", test);
	return (0);
}*/