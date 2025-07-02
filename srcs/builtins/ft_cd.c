/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nidruon <nidruon@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 20:00:26 by nidruon           #+#    #+#             */
/*   Updated: 2025/06/23 14:19:23 by nidruon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
Should work, right now cd command without args will return Undefined error in
the current version of main in this branch.
Main reason is that this main is a single time execution not working within
the minishell pipeline so args[1] is cd instead of correct path when nothing
is inputed.
*/

int	ft_cd(char **args, t_env_list *env)
{
	char	*target;
	char	buf[PATH_MAX];

	if (args[2])
		return (write(2, "mew-nishell: Too Many Arguments\n", 32));
	if (!args[1])
		target = get_env_value(env, "HOME");
	else if (ft_strcmp(args[1], "-") == 0)
		target = get_env_value(env, "OLDPWD");
	else
		target = args[1];
	if (!target || chdir(target) != 0)
		return (perror("minishell: cd"), 1);
	update_env_value(env, "OLDPWD", get_env_value(env, "PWD"));
	update_env_value(env, "PWD", getcwd(buf, PATH_MAX));
	return (0);
}
