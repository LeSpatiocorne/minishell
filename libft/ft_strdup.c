/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-brie <mle-brie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 11:25:54 by mle-brie          #+#    #+#             */
/*   Updated: 2024/11/14 11:52:29 by mle-brie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	char	*dup;
	int		len;
	int		i;

	len = 0;
	while (src[len])
		len++;
	dup = (char *)malloc((len + 1) * sizeof(char));
	if (dup == NULL)
		return (NULL);
	i = 0;
	while (src[i])
	{
		dup[i] = src[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

/*strdup() duplicates a string, and returns a pointer to this duplicated

malloc() allocates a place with enough place for what you want,
so it returns a pointer to this magic place (+1 for \0)
use sizeof to calculate what you need/want
	(char *)malloc(sizeof(smthg))
	smthg being either char or int, because it calculates the octets needed
multiply by (len + 1) to have the needed size with conversion of needed octets
	+ 1 because \0 takes a single octet in any case
	(char *) because it's a char, not anything else
you have to check if malloc is working (if *ptr of malloc == 0, returns 0)
	because computer wanky
*/

// int	main(int argc, char *argv[])
// {
// 	if (argc == 2)
// 	{
// 		printf("%s\n", ft_strdup(argv[1]));
// 		printf("%s\n", strdup(argv[1]));
// 		return (0);
// 	}
// }
