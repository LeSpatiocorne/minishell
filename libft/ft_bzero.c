/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-brie <mle-brie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 15:20:01 by mle-brie          #+#    #+#             */
/*   Updated: 2024/11/06 15:32:53 by mle-brie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*p;

	p = s;
	while (n--)
		*p++ = 0;
}
/*int	main(void)
{
	char	test[] = "memset is undoutbtly better";

	printf("%s\n", test);
	ft_bzero(test, 6);
	printf("%s\n", test);
	return (0);
}*/