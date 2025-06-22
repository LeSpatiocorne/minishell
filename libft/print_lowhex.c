/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_lowhex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-brie <mle-brie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 14:02:23 by mle-brie          #+#    #+#             */
/*   Updated: 2024/11/27 10:57:27 by mle-brie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	print_lowhex(va_list args)
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
			len++;
		write(1, result, len);
	}
	else
		write(1, "(null)", 6);
	free(result);
	return (len);
}
