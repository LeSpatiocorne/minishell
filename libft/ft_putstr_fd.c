/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-brie <mle-brie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 10:12:51 by mle-brie          #+#    #+#             */
/*   Updated: 2024/11/20 10:39:37 by mle-brie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		write(fd, &s[i], 1);
		i++;
	}
}

// int	main(void)
// {
// 	int		fd;
// 	char	*test = "Hello World!";
// 	int		len = ft_strlen(test);

// 	fd = open("test.txt", O_WRONLY);
// 	if (fd == -1)
// 		return (1);
// 	ft_putstr_fd(test, fd);
// 	if (close(fd) == -1)
// 		return (1);
// 	fd = open("test.txt", O_RDONLY);
// 	char	buffer[len + 1];
// 	ssize_t	bytes_read = read(fd, buffer, len);
// 	if (bytes_read == -1)
// 	{
// 		close(fd);
// 		return (1);
// 	}
// 	buffer[bytes_read] = '\0';
// 	printf("open the file and thou shall find :%s\n", buffer);
// 	close(fd);
// 	return (0);
// }