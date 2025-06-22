/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_uphex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-brie <mle-brie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 12:45:09 by mle-brie          #+#    #+#             */
/*   Updated: 2024/11/27 10:57:39 by mle-brie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	print_uphex(va_list args)
{
	unsigned int	num;
	char			*result;
	int				len;

	num = va_arg(args, unsigned int);
	result = hexformula(num);
	len = 0;
	if (result)
	{
		while (result[len])
		{
			result[len] = ft_toupper(result[len]);
			len++;
		}
		write(1, result, len);
	}
	else
		write(1, "(null)", 6);
	free(result);
	return (len);
}
