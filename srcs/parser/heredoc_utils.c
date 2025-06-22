/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-brie <mle-brie@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 22:35:31 by mle-brie          #+#    #+#             */
/*   Updated: 2025/06/22 15:12:56 by mle-brie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	my_getc(FILE *stream)
{
	char	c;
	ssize_t	n;

	(void)stream;
	n = read(STDIN_FILENO, &c, 1);
	if (n == 1)
		return ((unsigned char)c);
	if (n == 0)
		return (EOF);
	if (errno == EINTR)
	{
		write(1, "^C\n", 3);
		return (EOF);
	}
	return (EOF);
}

static void	hd_child_message(char *delim)
{
	write(2, "mew-nishell: warning: heredoc limited by EOF (wanted '", 54);
	write(2, delim, ft_strlen(delim));
	write(2, "')\n", 3);
}

void	heredoc_child(t_token *token, int pipe_fd[2])
{
	char	*line;
	char	*delim;

	delim = token->next->value;
	safe_close(pipe_fd[0]);
	rl_getc_function = my_getc;
	while (1)
	{
		line = readline("> ");
		if (!line)
		{
			hd_child_message(delim);
			break ;
		}
		if (ft_strcmp(line, delim) == 0)
		{
			free(line);
			break ;
		}
		write(pipe_fd[1], line, ft_strlen(line));
		write(pipe_fd[1], "\n", 1);
		free(line);
	}
	safe_close(pipe_fd[1]);
	exit (0);
}

void	heredoc_parent(t_cmd *cmd, pid_t pid, int pipe_fd[2])
{
	int	status;

	safe_close(pipe_fd[1]);
	waitpid(pid, &status, 0);
	if (WIFSIGNALED(status) && WTERMSIG(status) == SIGINT)
	{
		cmd->input_fd = -1;
		safe_close(pipe_fd[0]);
		set_exit_status(130);
	}
	else
	{
		if (cmd->input_fd != STDIN_FILENO && cmd->input_fd != -1)
			safe_close(cmd->input_fd);
		cmd->input_fd = pipe_fd[0];
	}
}
