/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-brie <mle-brie@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 17:39:35 by mle-brie          #+#    #+#             */
/*   Updated: 2025/06/22 15:55:23 by mle-brie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static bool	is_it_path(t_cmd *cmd)
{
	if (ft_strchr(cmd->args[0], '/'))
		return (true);
	return (false);
}

void	path_error_exit_status(char *cmd, char *message, int error)
{
	ft_putstr_fd("mew-nishell: ", 2);
	ft_putstr_fd(cmd, 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd(message, 2);
	ft_putstr_fd("\n", 2);
	set_exit_status(error);
}

static char	*check_valid_path(char *cmd)
{
	struct stat	file;

	if (stat(cmd, &file) != 0)
	{
		path_error_exit_status(cmd, "No such file or directory", 127);
		return (NULL);
	}
	if (S_ISDIR(file.st_mode))
	{
		path_error_exit_status(cmd, "Is a directory", 126);
		return (NULL);
	}
	if (access(cmd, F_OK | X_OK) != 0)
	{
		path_error_exit_status(cmd, "Permission denied", 126);
		return (NULL);
	}
	set_exit_status(0);
	return (ft_strdup(cmd));
}

char	*find_path_in_env(t_env_list *env)
{
	while (env)
	{
		if (ft_strcmp(env->key, "PATH") == 0)
			return (env->value);
		env = env->next;
	}
	return (NULL);
}

char	*get_path(t_cmd *cmd, t_env_list *env)
{
	char	**path_dirs;
	char	*full_path;
	char	*path_value;
	char	*path_part;
	size_t	i;

	path_value = find_path_in_env(env);
	if (!path_value || !cmd || !cmd->args[0])
		return (NULL);
	if (is_it_path(cmd))
		return (check_valid_path(cmd->args[0]));
	path_dirs = ft_split(path_value, ':');
	i = -1;
	while (path_dirs[++i])
	{
		path_part = ft_strjoin(path_dirs[i], "/");
		full_path = ft_strjoin(path_part, cmd->args[0]);
		free(path_part);
		if (access(full_path, F_OK | X_OK) == 0)
			return (free_tab(path_dirs), full_path);
		free(full_path);
	}
	free_tab(path_dirs);
	path_error_exit_status(cmd->args[0], "Command not found", 127);
	return (NULL);
}
