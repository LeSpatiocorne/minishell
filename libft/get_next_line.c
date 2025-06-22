/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-brie <mle-brie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 14:40:42 by mle-brie          #+#    #+#             */
/*   Updated: 2025/05/01 14:35:11 by mle-brie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_read_and_update_stock(int fd, char *stock, char *buffer)
{
	int		bytes_read;
	char	*temp;

	temp = NULL;
	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read <= 0)
			break ;
		buffer[bytes_read] = '\0';
		temp = ft_strjoin(stock, buffer);
		if (!temp)
			return (free(stock), NULL);
		free(stock);
		stock = temp;
		if (ft_strchr(stock, '\n'))
			break ;
	}
	if (bytes_read < 0)
	{
		free(stock);
		stock = NULL;
	}
	return (stock);
}

char	*ft_extract_line_from_stock(char **stock)
{
	char	*line;
	char	*newline_ptr;
	char	*temp;
	size_t	line_length;

	newline_ptr = ft_strchr(*stock, '\n');
	if (!newline_ptr)
		return (NULL);
	line_length = newline_ptr - *stock + 1;
	line = (char *)malloc(sizeof(char) * (line_length + 1));
	if (!line)
		return (NULL);
	ft_strlcpy(line, *stock, line_length + 1);
	temp = ft_strdup(newline_ptr + 1);
	if (!temp)
		return (free(line), NULL);
	free(*stock);
	*stock = temp;
	if ((*stock)[0] == '\0')
	{
		free(*stock);
		*stock = NULL;
	}
	return (line);
}

char	*ft_finalize_line(char **stock, char *buffer)
{
	char	*line;

	if (*stock && **stock)
	{
		line = ft_strdup(*stock);
		if (!line)
		{
			free(*stock);
			*stock = NULL;
		}
	}
	else
		line = NULL;
	free(*stock);
	*stock = NULL;
	free(buffer);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*stock;
	char		*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	if (!stock)
	{
		stock = ft_strdup("");
		if (!stock)
			return (free(buffer), NULL);
	}
	stock = ft_read_and_update_stock(fd, stock, buffer);
	if (!stock)
		return (free(buffer), NULL);
	line = ft_extract_line_from_stock(&stock);
	if (line)
		return (free(buffer), line);
	return (ft_finalize_line(&stock, buffer));
}

// int	main(int argc, char *argv[])
// {
// 	int		fd;
// 	int		i = 1;
// 	char	*line;

// 	while (i < argc)
// 	{
// 		fd = open(argv[i], O_RDONLY);
// 		if (fd == -1)
// 		{
// 			printf("Fucked up\n");
// 			return (1);
// 		}
// 		printf("\nBegoth, the %ith file:\n", i);
// 		int	l = 0;
// 		while (l < 10)
// 		{
// 			line = get_next_line(fd);
// 			printf("%s", line);
// 			l++;
// 		}
// 		i++;
// 	}
// 	close (fd);
// 	return (0);
// }

// int	main(int argc, char **argv)
// {
// 	int		fd;
//     char **argv2 = argv;

// 	while (argc-- - 1)
// 	{
// 		if ((fd = open(*(++argv), O_RDONLY)) == -1)
// 			return (printf("Fucked up\n"));
// 		printf("\n\nBegoth, the file number %i:\n\n", (int)(argv - argv2));
//         for (char * line = get_next_line(fd);
				// ^^^^^line != NULL; line = get_next_line(fd))
//             printf("%s", line);
// 	}
// 	return (close (fd));
// }