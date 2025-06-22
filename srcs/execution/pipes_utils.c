/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-brie <mle-brie@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 09:46:01 by mle-brie          #+#    #+#             */
/*   Updated: 2025/06/22 14:53:55 by mle-brie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	setup_pipes(t_cmd *cmd, t_token **tokens, t_env_list *env)
{
	t_cmd	*current;

	current = cmd;
	while (current)
	{
		if (current->next)
		{
			if (pipe(current->pipe_fd) == -1)
			{
				perror("mew-nishell: pipe");
				free_all(tokens, cmd, env);
				exit(EXIT_FAILURE);
			}
			current->next->input_fd = current->pipe_fd[0];
			current->output_fd = current->pipe_fd[1];
		}
		current = current->next;
	}
}

void	close_pipes(t_cmd *cmd)
{
	t_cmd	*current;

	current = cmd;
	while (current)
	{
		if (current->pipe_fd[0] != -1)
			safe_close(current->pipe_fd[0]);
		if (current->pipe_fd[1] != -1)
			safe_close(current->pipe_fd[1]);
		current = current->next;
	}
}

void	close_pipes_except_current(t_cmd *cmd, t_cmd *cmd_list)
{
	t_cmd	*tmp;

	tmp = cmd_list;
	while (tmp)
	{
		if (tmp->pipe_fd[0] != -1 && tmp->pipe_fd[0] != cmd->input_fd)
			safe_close(tmp->pipe_fd[0]);
		if (tmp->pipe_fd[1] != -1 && tmp->pipe_fd[1] != cmd->output_fd)
			safe_close(tmp->pipe_fd[1]);
		tmp = tmp->next;
	}
}
