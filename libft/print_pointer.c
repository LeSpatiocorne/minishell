/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-brie <mle-brie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 13:31:05 by mle-brie          #+#    #+#             */
/*   Updated: 2024/11/27 11:06:41 by mle-brie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	print_pointer(va_list args)
{
	void			*ptr;
	unsigned long	temp;
	char			*result;
	int				len;

	ptr = va_arg(args, void *);
	len = 0;
	if (!ptr)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	temp = (unsigned long)ptr;
	result = hexformula(temp);
	if (!result)
		return (0);
	len += write(1, "0x", 2);
	len += write(1, result, ft_strlen(result));
	free(result);
	return (len);
}

/* pointer, so write "Ox", and then hexformula*/

// int	main(void)
// {
// 	char	*test1 = "test";
// 	int		test2 = INT_MIN;
// 	void	*test_pointer1 = &test1;
// 	printf("printf for pointer = %p\n", test_pointer1);
// 	ft_printf("my trials and errors for pointer = %p\n", test_pointer1);
// 	void	*test_pointer2 = &test2;
// 	printf("printf for pointer = %p\n", test_pointer2);
// 	ft_printf("my trials and errors for pointer = %p\n", test_pointer2);
// 	return(0);
// }