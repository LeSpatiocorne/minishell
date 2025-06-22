/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-brie <mle-brie@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 14:05:31 by mle-brie          #+#    #+#             */
/*   Updated: 2025/06/22 14:52:36 by mle-brie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	perror_failure(const char *error, t_token **tokens,
						t_cmd *cmd, t_env_list *env)
{
	perror(error);
	free_all(tokens, cmd, env);
	exit(EXIT_FAILURE);
}

void	dup2_helper_function(t_cmd *cmd, t_token **tokens, t_env_list *env)
{
	if (cmd->input_fd != STDIN_FILENO && cmd->input_fd != -1)
	{
		if (dup2(cmd->input_fd, STDIN_FILENO) == -1)
			perror_failure("mew-nishell: dup2 input", tokens, cmd, env);
		safe_close(cmd->input_fd);
	}
	if (cmd->output_fd != STDOUT_FILENO && cmd->output_fd != -1)
	{
		if (dup2(cmd->output_fd, STDOUT_FILENO) == -1)
			perror_failure("mew-nishell: dup2 output", tokens, cmd, env);
		safe_close(cmd->output_fd);
	}
}

//other?