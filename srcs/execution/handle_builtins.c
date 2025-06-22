/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_builtins.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nidruon <nidruon@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 16:55:18 by nidruon           #+#    #+#             */
/*   Updated: 2025/06/22 14:52:06 by nidruon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	is_child_builtin(char *cmd)
{
	return (ft_strcmp(cmd, "pwd") == 0
		|| ft_strcmp(cmd, "echo") == 0
		|| ft_strcmp(cmd, "env") == 0);
}

int	handle_child_builtin(char **args, t_env_list *env)
{
	if (!args || !args[0])
		return (-1);
	if (ft_strcmp(args[0], "pwd") == 0)
	{
		ft_pwd();
		write(1, "\n", 1);
		return (0);
	}
	if (ft_strcmp(args[0], "echo") == 0)
		return (ft_echo(args, env));
	if (ft_strcmp(args[0], "env") == 0)
	{
		ft_env(env);
		return (0);
	}
	return (-1);
}

bool	is_parent_builtin(char *cmd)
{
	return (ft_strcmp(cmd, "cd") == 0
		|| ft_strcmp(cmd, "exit") == 0
		|| ft_strcmp(cmd, "export") == 0
		|| ft_strcmp(cmd, "unset") == 0);
}
//those are to be executed by the parent
//because they imply external situations thingies
//and they *need to change the shell state*
//and as such, need to be caught *before* forking!

int	parent_builtin_logic(char **args, t_cmd *cmd,
						t_env_list *env, t_token **tokens)
{
	if (ft_strcmp(args[0], "exit") == 0)
		return (ft_exit(args, env, tokens, cmd));
	if (ft_strcmp(args[0], "cd") == 0)
		return (ft_cd(args, env));
	if (ft_strcmp(args[0], "export") == 0)
		return (ft_export(args, env));
	if (ft_strcmp(args[0], "unset") == 0)
		return (ft_unset(args, env));
	return (-1);
}

int	handle_parent_builtin(t_cmd *cmd, t_env_list *env, t_token **tokens)
{
	int	exit_status;

	exit_status = 0;
	if (!cmd->args || !cmd->args[0])
		return (0);
	if (is_parent_builtin(cmd->args[0]))
	{
		exit_status = parent_builtin_logic(cmd->args, cmd, env, tokens);
		return (set_exit_status(exit_status));
	}
	return (-1);
}
