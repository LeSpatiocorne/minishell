/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-brie <mle-brie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 11:53:07 by mle-brie          #+#    #+#             */
/*   Updated: 2024/11/15 16:16:34 by mle-brie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// void	*ft_memset(void *s, int c, size_t n)
// {
// 	unsigned char	*p;

// 	p = s;
// 	while (n--)
// 		*p++ = c;
// 	return (s);
// }

void	*ft_calloc(size_t numelem, size_t size)
{
	size_t	total;
	void	*ptr;

	total = numelem * size;
	ptr = malloc(total);
	if (ptr == NULL)
		return (NULL);
	else
		ft_memset(ptr, '\0', total);
	return (ptr);
}

/*
calloc initializes the concerned memories to 0
so, I have to get a total size of the memory needed
	using a malloc to the multiplication of both components
and then, use a memset to change every bytes of memory to a 0
	-> ft_memset for the pointer, 0 as a character, and the total size
and return the pointer I guess?
*/