/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-brie <mle-brie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 12:18:44 by mle-brie          #+#    #+#             */
/*   Updated: 2024/11/27 10:42:41 by mle-brie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	print_string(va_list args)
{
	char	*str;
	int		len;

	str = va_arg(args, char *);
	len = 0;
	if (!str)
	{
		ft_putstr_fd("(null)", 1);
		return (6);
	}
	while (str[len])
		len++;
	ft_putstr_fd(str, 1);
	return (len);
}

// int	main(void)
// {
// 	char	*test = "all is good in FunLand";

// 	printf("%s\n", test);
// 	printf("%d\n", print_string(test));
// 	return (0);
// }