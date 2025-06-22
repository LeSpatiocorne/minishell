/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-brie <mle-brie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 10:40:43 by mle-brie          #+#    #+#             */
/*   Updated: 2024/11/20 11:21:48 by mle-brie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	ft_putstr_fd(s, fd);
	write(fd, "\n", 1);
}

// int	main(void)
// {
// 	int		fd;
// 	char	*test = "Hello World!";
// 	size_t	len = ft_strlen(test);

// 	fd = open("test.txt", O_WRONLY);
// 	if (fd == -1)
// 		return (1);
// 	ft_putendl_fd(test, fd);
// 	if (close(fd) == -1)
// 		return (1);
// 	fd = open("test.txt", O_RDONLY);
// 	if (fd == -1)
// 		return (1);
// 	char	buffer[len + 2];
// 	ssize_t	bytes_read = read(fd, buffer, len + 1);
// 	if (bytes_read == -1)
// 	{
// 		close(fd);
// 		return (1);
// 	}
// 	buffer[bytes_read] = '\0';
// 	printf("open the file and thou shall find: %s", buffer);
// 	close(fd);
// 	return (0);
// }