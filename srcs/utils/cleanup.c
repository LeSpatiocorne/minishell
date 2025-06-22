/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-brie <mle-brie@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 12:01:04 by mle-brie          #+#    #+#             */
/*   Updated: 2025/06/22 14:19:24 by mle-brie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_tab(char **tab)
{
	size_t	i;

	i = -1;
	if (!tab)
		return ;
	while (tab[++i])
		free(tab[i]);
	free(tab);
}

void	free_all(t_token **tokens, t_cmd *cmd_list, t_env_list *env)
{
	if (tokens && *tokens)
		free_token_list(tokens);
	if (cmd_list)
		free_cmd_list(cmd_list);
	if (env)
		free_env_list(env);
}

void	safe_close(int fd)
{
	if (fd >= 0)
		close(fd);
}

//###################