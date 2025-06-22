/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtok.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-brie <mle-brie@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 16:09:31 by mle-brie          #+#    #+#             */
/*   Updated: 2025/05/14 16:09:36 by mle-brie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_delimiter(char c, const char *delim)
{
	while (*delim)
	{
		if (c == *delim)
			return (1);
		delim++;
	}
	return (0);
}

char	*ft_strtok(char *str, const char *delim)
{
	static char	*last;
	char		*token;

	if (str != NULL)
		last = str;
	else if (last == NULL)
		return (NULL);
	while (*last && is_delimiter(*last, delim))
		last++;
	if (*last == '\0')
	{
		last = NULL;
		return (NULL);
	}
	token = last;
	while (*last && !is_delimiter(*last, delim))
		last++;
	if (*last != '\0')
	{
		*last = '\0';
		last++;
	}
	else
		last = NULL;
	return (token);
}
/*
int	main(void)
{
	char	str[] = "cat infile.txt | grep hello > out.txt";
	char	*token;

	token = ft_strtok(str, " ");
	while (token != NULL)
	{
		printf("token: %s\n", token);
		token = ft_strtok(NULL, " ");
	}
	return (0);
}
*/