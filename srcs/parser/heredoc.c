/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-brie <mle-brie@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 11:33:38 by mle-brie          #+#    #+#             */
/*   Updated: 2025/06/16 22:41:32 by mle-brie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	parent_sigaction(struct sigaction *old_sigint,
						struct sigaction *old_sigquit)
{
	struct sigaction	sa_ignore;

	sa_ignore.sa_handler = SIG_IGN;
	sigemptyset(&sa_ignore.sa_mask);
	sa_ignore.sa_flags = 0;
	sigaction(SIGINT, &sa_ignore, old_sigint);
	sigaction(SIGQUIT, &sa_ignore, old_sigquit);
}

void	child_sigaction(void)
{
	struct sigaction	sa_default;

	sa_default.sa_handler = SIG_DFL;
	sigemptyset(&sa_default.sa_mask);
	sa_default.sa_flags = 0;
	sigaction(SIGINT, &sa_default, NULL);
	sigaction(SIGQUIT, &sa_default, NULL);
}

void	heredoc_perror_helper(t_cmd *cmd)
{
	perror("mew-nishell: heredoc: pipe");
	cmd->input_fd = -1;
}

void	handle_heredoc(t_token *token, t_cmd *cmd)
{
	int					pipe_fd[2];
	pid_t				pid;
	struct sigaction	old_sigint;
	struct sigaction	old_sigquit;

	if (pipe(pipe_fd) == -1)
		return (heredoc_perror_helper(cmd));
	parent_sigaction(&old_sigint, &old_sigquit);
	pid = fork();
	if (pid == -1)
		return (heredoc_perror_helper(cmd));
	if (pid == 0)
	{
		child_sigaction();
		heredoc_child(token, pipe_fd);
	}
	else
	{
		heredoc_parent(cmd, pid, pipe_fd);
		sigaction(SIGINT, &old_sigint, NULL);
		sigaction(SIGQUIT, &old_sigquit, NULL);
	}
}
