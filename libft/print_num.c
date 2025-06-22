/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_num.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-brie <mle-brie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 14:41:07 by mle-brie          #+#    #+#             */
/*   Updated: 2024/11/27 09:51:08 by mle-brie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	print_num(va_list args)
{
	int		num;
	char	*result;
	int		len;

	num = va_arg(args, int);
	result = ft_itoa(num);
	len = 0;
	if (result)
	{
		while (result[len])
			len++;
		write(1, result, len);
	}
	else
		write (1, "(null)", 6);
	free(result);
	return (len);
}
