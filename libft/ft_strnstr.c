/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-brie <mle-brie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 11:31:57 by mle-brie          #+#    #+#             */
/*   Updated: 2024/11/15 11:28:37 by mle-brie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	if (*little == '\0')
		return ((char *)big);
	i = 0;
	while (big[i] != '\0')
	{
		j = 0;
		while (little[j] != '\0' && i + j < len)
		{
			if (big[i + j] != little[j])
				break ;
			j++;
		}
		if (little[j] == '\0')
			return ((char *)big + i);
		i++;
	}
	return (NULL);
}

// int	main(void)
// {
// 	const char	*hay = "dans la botte de foin, il y a une aiguille qui danse";
// 	const char	*needle = "danse";
	// 
// 	printf("%p\n", ft_strnstr(hay, needle, 100));
// 	return (0);
// }

/*len concerns big, not little
	hence i + j*/