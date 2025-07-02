/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_parsing_util.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nidruon <nidruon@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 18:27:25 by nidruon           #+#    #+#             */
/*   Updated: 2025/06/22 19:02:52 by nidruon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_parsing_data	*init_parsing_data(void)
{
	t_parsing_data	*p_data;

	p_data = malloc(sizeof(t_parsing_data));
	if (!p_data)
		return (NULL);
	p_data->argc = 0;
	p_data->args = malloc(sizeof(char *) * MAX_ARGS);
	if (!p_data->args)
	{
		free(p_data);
		return (NULL);
	}
	p_data->current = NULL;
	p_data->cmd_list = NULL;
	return (p_data);
}

char	**process_pipe_or_end(t_parsing_data *p_data, t_token *token)
{
	t_token	*cmd_end;
	char	**new_args;

	p_data->args[p_data->argc] = NULL;
	add_cmd_node(&p_data->cmd_list, &p_data->current, p_data->args);
	cmd_end = token;
	handle_redirs_per_cmd(p_data->cmd_start, cmd_end, p_data->current);
	p_data->argc = 0;
	new_args = malloc(sizeof(char *) * MAX_ARGS);
	if (!new_args)
	{
		free_cmd_list(p_data->cmd_list);
		return (NULL);
	}
	p_data->cmd_start = token->next;
	return (new_args);
}

t_cmd	*free_parsing_data(t_parsing_data *p_data)
{
	t_cmd	*cmd_list;

	if (p_data->args)
		free(p_data->args);
	cmd_list = p_data->cmd_list;
	free(p_data);
	return (cmd_list);
}
