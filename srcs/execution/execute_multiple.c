/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_multiple.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-brie <mle-brie@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 14:22:22 by mle-brie          #+#    #+#             */
/*   Updated: 2025/06/22 14:52:43 by mle-brie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	count_cmd(t_cmd *cmd_list)
{
	int	count;

	count = 0;
	while (cmd_list)
	{
		count++;
		cmd_list = cmd_list->next;
	}
	return (count);
}

void	fork_helper_child(t_cmd *current, t_cmd *cmd_list,
							t_env_list *env, t_token **tokens)
{
	set_signal_child();
	child_process(current, cmd_list, env, tokens);
}

void	fork_helper_parent(t_cmd **current, int *i)
{
	if ((*current)->pipe_fd[1] != STDOUT_FILENO)
		safe_close((*current)->pipe_fd[1]);
	if ((*current)->prev && (*current)->prev->pipe_fd[0] != STDIN_FILENO)
		safe_close((*current)->prev->pipe_fd[0]);
	*current = (*current)->next;
	(*i)++;
}

pid_t	*fork_all_cmds(t_cmd *cmd_list, t_env_list *env, t_token **tokens)
{
	t_cmd	*current;
	pid_t	*pids;
	int		i;

	i = 0;
	pids = malloc(sizeof(pid_t) * (count_cmd(cmd_list)));
	if (!pids)
		return (perror("mew-nishell: pids' malloc"), NULL);
	setup_pipes(cmd_list, tokens, env);
	current = cmd_list;
	while (current)
	{
		signal(SIGINT, SIG_IGN);
		pids[i] = fork();
		if (pids[i] == -1)
			return (perror("mew-nishell: fork"), free(pids), NULL);
		if (pids[i] == 0)
			fork_helper_child(current, cmd_list, env, tokens);
		else
			fork_helper_parent(&current, &i);
	}
	signal(SIGINT, handle_sigint);
	close_pipes(cmd_list);
	return (pids);
}

int	wait_for_all_children(pid_t *pids, int cmd_count)
{
	int	status;
	int	last_exit;
	int	i;

	i = 0;
	last_exit = 0;
	while (i < cmd_count)
	{
		if (waitpid(pids[i], &status, 0) == -1)
			perror("mew-nishell: waitpid");
		if (i == cmd_count - 1)
		{
			if (WIFEXITED(status))
				last_exit = WEXITSTATUS(status);
			else if (WIFSIGNALED(status))
				last_exit = 128 + WTERMSIG(status);
			else
				last_exit = status;
		}
		i++;
	}
	free(pids);
	return (set_exit_status(last_exit));
}
