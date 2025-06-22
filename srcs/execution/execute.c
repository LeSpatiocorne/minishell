/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-brie <mle-brie@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 20:53:46 by mle-brie          #+#    #+#             */
/*   Updated: 2025/06/22 15:07:53 by mle-brie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	child_process(t_cmd *cmd, t_cmd *cmd_list,
						t_env_list *env, t_token **tokens)
{
	char	*path;
	char	**envp;
	int		status;

	status = 0;
	close_pipes_except_current(cmd, cmd_list);
	dup2_helper_function(cmd, tokens, env);
	if (is_child_builtin(cmd->args[0]))
	{
		status = handle_child_builtin(cmd->args, env);
		free_all(tokens, cmd_list, env);
		exit(status);
	}
	path = get_path(cmd, env);
	if (!path)
	{
		free_all(tokens, cmd_list, env);
		exit(get_exit_status());
	}
	envp = env_list_to_tab(env);
	execve(path, cmd->args, envp);
	free_tab(envp);
	free(path);
	perror_failure("minishell: execve", tokens, cmd_list, env);
}

int	single_cmd(t_cmd *cmd, t_cmd *cmd_list, t_env_list *env, t_token **tokens)
{
	pid_t	pid;
	int		status;
	int		exit_status;

	signal(SIGINT, SIG_IGN);
	exit_status = 0;
	pid = fork();
	if (pid == -1)
		return (perror("mew-nishell: fork()"), 1);
	if (pid == 0)
	{
		set_signal_child();
		child_process(cmd, cmd_list, env, tokens);
	}
	waitpid(pid, &status, 0);
	if (WIFSIGNALED(status))
		exit_status = 128 + WTERMSIG(status);
	else if (WIFEXITED(status))
		exit_status = WEXITSTATUS(status);
	else
		exit_status = status;
	signal(SIGINT, handle_sigint);
	signal(SIGQUIT, handle_sigquit);
	return (set_exit_status(exit_status));
}

int	multiple_cmds(t_cmd *cmd_list, t_env_list *env, t_token **tokens)
{
	int		cmd_count;
	pid_t	*pids;

	cmd_count = count_cmd(cmd_list);
	pids = fork_all_cmds(cmd_list, env, tokens);
	if (!pids)
		return (1);
	return (wait_for_all_children(pids, cmd_count));
}

int	execute(t_cmd *cmd, t_env_list *env, t_token **tokens)
{
	if (cmd->input_fd == -1 || cmd->output_fd == -1)
		return (1);
	if (!cmd->next && is_parent_builtin(cmd->args[0]))
		return (handle_parent_builtin(cmd, env, tokens));
	else if (!cmd->next)
		return (single_cmd(cmd, cmd, env, tokens));
	else
		return (multiple_cmds(cmd, env, tokens));
}

/*
norminette work :
all multiple cmds things belong together in a multiple_command.c file
/!\
	fork_all_cmds() is very long, separate in two, thx /!\

child_process(), single_cmd() and execute() stay here
*/