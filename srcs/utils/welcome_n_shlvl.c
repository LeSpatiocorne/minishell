/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   welcome_n_shlvl.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nidruon <nidruon@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 21:33:59 by nidruon           #+#    #+#             */
/*   Updated: 2025/06/03 14:59:34 by nidruon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	handle_shlvl_edge_cases(int *level)
{
	if (*level < 0)
		*level = 0;
	else if (*level >= 1000)
	{
		ft_putstr_fd("mew-nishell: warning: shell level (", 2);
		ft_putnbr_fd(*level + 1, 2);
		ft_putstr_fd(") too high, resetting to 1\n", 2);
		*level = 1;
	}
}

static void	update_shlvl(t_env_list *env)
{
	char	*shlvl_str;
	int		level;
	char	*new_level;

	shlvl_str = get_env_value(env, "SHLVL");
	if (!shlvl_str || !*shlvl_str)
		level = 0;
	else
		level = ft_atoi(shlvl_str);
	level++;
	handle_shlvl_edge_cases(&level);
	new_level = ft_itoa(level);
	if (!new_level)
		return ;
	update_env_value(env, "SHLVL", new_level);
	free(new_level);
}

static void	print_welcome(void)
{
	int		fd;
	char	*line;

	fd = open("art/mew-nishell", O_RDONLY);
	if (fd == -1)
		return ;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		ft_putstr_fd(line, 1);
		free(line);
	}
	close(fd);
}

void	startup_minishell(t_env_list *env)
{
	print_welcome();
	update_shlvl(env);
}
