/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-brie <mle-brie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 10:42:13 by mle-brie          #+#    #+#             */
/*   Updated: 2024/11/27 09:52:11 by mle-brie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	print_unsigned(va_list args)
{
	unsigned int	u;
	char			*result;
	int				len;

	u = va_arg(args, unsigned int);
	result = ft_utoa(u);
	len = 0;
	if (result)
	{
		while (result[len])
			len++;
		write(1, result, len);
	}
	else
		return (write(1, "(null)", 6));
	free(result);
	return (len);
}

// int	main(void)
// {
// 	unsigned int		test = 789453455;

// 	printf("unsigned is %u\n", test);
// 	ft_printf("function to char %u\n", test);
// 	return (0);
// }