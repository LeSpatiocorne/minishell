/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-brie <mle-brie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 11:41:51 by mle-brie          #+#    #+#             */
/*   Updated: 2024/11/20 12:18:12 by mle-brie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n = -n;
	}
	if (n >= 10)
		ft_putnbr_fd((n / 10), fd);
	ft_putchar_fd((n % 10 + '0'), fd);
}

// int	num_size(int n)
// {
// 	int	len;

// 	len = 0;
// 	if (n < 0)
// 		n = -n;
// 	while (n != 0)
// 	{
// 		n /= 10;
// 		len++;
// 	}
// 	return (len);
// }

// int	main(void)
// {
// 	int	test = 2147483647;
// 	int	fd;
// 	size_t	len;

// 	len = num_size(test);
// 	fd = open("test.txt", O_WRONLY);
// 	if (fd == -1)
// 		return (1);
// 	ft_putnbr_fd(test, fd);
// 	if (close(fd) == -1)
// 		return (1);
// 	fd = open("test.txt", O_RDONLY);
// 	if (fd == -1)
// 		return (1);
// 	char	buffer[len + 1];
// 	ssize_t	bytes_read = read(fd, buffer, len + 1);
// 	if (bytes_read == -1)
// 	{
// 		close(fd);
// 		return (1);
// 	}
// 	buffer[bytes_read] = '\0';
// 	printf("The file shall transform: %s\n", buffer);
// 	close(fd);
// 	return (0);
// }