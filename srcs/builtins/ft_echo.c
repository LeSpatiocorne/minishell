/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nidruon <nidruon@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 02:55:44 by nidruon           #+#    #+#             */
/*   Updated: 2025/06/20 20:07:52 by nidruon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	is_n_option(char *str)
{
	int	i;

	if (!str || str[0] != '-' || str[1] != 'n')
		return (0);
	i = 2;
	while (str[i])
	{
		if (str[i] != 'n')
			return (0);
		i++;
	}
	return (1);
}

int	ft_echo(char **args, t_env_list *env)
{
	int		i;
	int		newline;
	char	*expanded;

	i = 0;
	newline = 1;
	while (i++, args[i] && is_n_option(args[i]))
		newline = 0;
	while (args[i])
	{
		expanded = expand_variables(args[i], env);
		if (expanded)
		{
			ft_putstr_fd(expanded, 1);
			free(expanded);
		}
		else
			ft_putstr_fd(args[i], 1);
		if (args[i + 1])
			ft_putchar_fd(' ', 1);
		i++;
	}
	if (newline)
		ft_putchar_fd('\n', 1);
	return (0);
}
