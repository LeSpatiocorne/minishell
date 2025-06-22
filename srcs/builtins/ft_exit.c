/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-brie <mle-brie@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 03:32:53 by nidruon           #+#    #+#             */
/*   Updated: 2025/06/22 14:16:28 by mle-brie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	is_numeric(char *str)
{
	int	i;

	if (!str || !*str)
		return (0);
	if (str[0] == '+' || str[0] == '-')
		str++;
	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

static void	not_num_exit(char **args, t_env_list *env,
						t_token **tokens, t_cmd *cmd)
{
	ft_putstr_fd("mew-nishell: exit: ", 2);
	ft_putstr_fd(args[1], 2);
	ft_putstr_fd(": numeric argument required\n", 2);
	free_all(tokens, cmd, env);
	exit(255);
}

int	ft_exit(char **args, t_env_list *env, t_token **tokens, t_cmd *cmd)
{
	static int	code;

	(void)env;
	ft_putstr_fd("exit\n", 1);
	code = 0;
	if (!args[1])
	{
		free_all(tokens, cmd, env);
		exit(0);
	}
	if (!is_numeric(args[1]))
		not_num_exit(args, env, tokens, cmd);
	if (args[2])
	{
		ft_putstr_fd("mew-nishell: exit: too many arguments\n", 2);
		return (1);
	}
	code = ft_atoi(args[1]) % 256;
	while (code < 0)
		code += 256;
	free_all(tokens, cmd, env);
	exit(code);
}
