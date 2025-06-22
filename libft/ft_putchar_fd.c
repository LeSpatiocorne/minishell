/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-brie <mle-brie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 09:53:22 by mle-brie          #+#    #+#             */
/*   Updated: 2024/11/20 10:11:54 by mle-brie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

// int	main(void)
// {
// 	int	fd = open("test.txt", O_WRONLY);
// 	if (fd == -1)
// 		return (1);

// 	ft_putchar_fd('a', fd);

// 	if (close(fd) == -1)
// 		return (1);

// 	fd = open("test.txt", O_RDONLY);
// 	if (fd == -1)
// 		return (1);

// 	char	buffer[2];
// 	ssize_t bytes_read = read(fd, buffer, 1);
// 	if (bytes_read == -1)
// 	{
// 		perror("fail");
// 		close(fd);
// 		return (1);
// 	}

// 	buffer[bytes_read] = '\0';
// 	printf("open the file to find %s\nand only this\n", buffer);
// 	close(fd);

// 	return (0);
// }