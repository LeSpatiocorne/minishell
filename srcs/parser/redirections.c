/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-brie <mle-brie@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 12:32:30 by mle-brie          #+#    #+#             */
/*   Updated: 2025/06/23 16:07:44 by mle-brie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	handle_redir_in(t_token *token, t_cmd *cmd)
{
	int	fd;

	fd = open(token->next->value, O_RDONLY);
	if (fd < 0)
	{
		perror(token->next->value);
		cmd->input_fd = -1;
	}
	else
	{
		if (cmd->input_fd != STDIN_FILENO)
			safe_close(cmd->input_fd);
		cmd->input_fd = fd;
	}
}

void	handle_redir_out(t_token *token, t_cmd *cmd)
{
	int	fd;

	fd = open(token->next->value, O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (fd < 0)
	{
		perror(token->next->value);
		cmd->output_fd = -1;
	}
	else
	{
		if (cmd->output_fd != STDOUT_FILENO)
			safe_close(cmd->output_fd);
		cmd->output_fd = fd;
	}
}

void	handle_append(t_token *token, t_cmd *cmd)
{
	int	fd;

	fd = open(token->next->value, O_CREAT | O_RDWR | O_APPEND, 0644);
	if (fd < 0)
	{
		perror(token->next->value);
		cmd->output_fd = -1;
	}
	else
	{
		if (cmd->output_fd != STDOUT_FILENO)
			safe_close(cmd->output_fd);
		cmd->output_fd = fd;
	}
}

bool	helper_handling(t_token *token, t_cmd *cmd)
{
	if (token->type == REDIR_IN && token->next && token->next->type == ARG)
	{
		handle_redir_in(token, cmd);
		return (true);
	}
	else if (token->type == HEREDOC && token->next && token->next->type == ARG)
	{
		handle_heredoc(token, cmd);
		return (true);
	}
	return (false);
}

void	handle_redirs_per_cmd(t_token *start, t_token *end, t_cmd *cmd)
{
	t_token	*token;

	token = start;
	while (token && token != end)
	{
		if (helper_handling(token, cmd))
			token = token->next;
		else if ((token->type == REDIR_OUT || token->type == APPEND)
			&& token->next && token->next->type == ARG)
		{
			if (token->type == APPEND)
				handle_append(token, cmd);
			else
				handle_redir_out(token, cmd);
			if (cmd->output_fd == -1)
				break ;
			token = token->next;
			continue ;
		}
		if (cmd->input_fd == -1 || cmd->output_fd == -1)
			break ;
		token = token->next;
	}
}
