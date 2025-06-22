/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-brie <mle-brie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 13:54:48 by mle-brie          #+#    #+#             */
/*   Updated: 2024/11/14 11:57:37 by mle-brie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
	if (c < 32 || c > 126)
		return (0);
	else
		return (1);
}
/*#include <stdio.h>

int main(void)
{
	char	test = '...';
	if (ft_isprint(test))
		printf("%c is printable\n", test);
	else
		printf("%c is not printable\n", test);
	return (0);
}*/