/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nidruon <nidruon@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 16:47:05 by nidruon           #+#    #+#             */
/*   Updated: 2025/06/22 19:03:39 by nidruon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_cmd	*create_cmd_node(char **args)
{
	t_cmd	*new_node;

	new_node = malloc(sizeof(t_cmd));
	if (!new_node)
		return (NULL);
	new_node->args = args;
	new_node->prev = NULL;
	new_node->next = NULL;
	new_node->input_fd = STDIN_FILENO;
	new_node->output_fd = STDOUT_FILENO;
	new_node->pipe_fd[0] = -1;
	new_node->pipe_fd[1] = -1;
	return (new_node);
}

void	free_cmd_list(t_cmd *cmd)
{
	t_cmd	*tmp;

	if (!cmd)
		return ;
	while (cmd)
	{
		tmp = cmd;
		cmd = cmd->next;
		if (tmp->input_fd > 2)
			close(tmp->input_fd);
		if (tmp->output_fd > 2)
			close(tmp->output_fd);
		if (tmp->pipe_fd[0] > 2)
			close(tmp->pipe_fd[0]);
		if (tmp->pipe_fd[1] > 2)
			close(tmp->pipe_fd[1]);
		free_tab(tmp->args);
		free(tmp);
	}
}

void	add_cmd_node(t_cmd **cmd_list, t_cmd **current, char **args)
{
	t_cmd	*new_node;

	if (!*cmd_list)
	{
		*cmd_list = create_cmd_node(args);
		*current = *cmd_list;
	}
	else
	{
		new_node = create_cmd_node(args);
		new_node->prev = *current;
		(*current)->next = new_node;
		*current = new_node;
	}
}

static void	helper_parse(t_token **token_ptr, char **args, int *argc,
	t_env_list *env)
{
	t_token	*token;
	char	*expanded_value;

	token = *token_ptr;
	if (!token)
		return ;
	if (token->type == REDIR_IN || token->type == HEREDOC
		|| token->type == APPEND || token->type == REDIR_OUT)
	{
		if (token->next)
			token = token->next;
	}
	else if (token->type == CMD || token->type == ARG)
	{
		expanded_value = expand_variables(token->value, env);
		args[(*argc)++] = expanded_value;
	}
	*token_ptr = token;
}

t_cmd	*parse_cmd_from_token(t_token *token, t_token *cmd_start,
			t_env_list *env)
{
	t_parsing_data	*p_data;

	p_data = init_parsing_data();
	if (!p_data)
		return (NULL);
	p_data->cmd_start = cmd_start;
	while (token)
	{
		helper_parse(&token, p_data->args, &p_data->argc, env);
		if (token->type == PIPE || !token->next)
		{
			p_data->args = process_pipe_or_end(p_data, token);
			if (!p_data->args)
			{
				free(p_data);
				return (NULL);
			}
		}
		token = token->next;
	}
	return (free_parsing_data(p_data));
}

//##############################################################
//# 				norminette compliant					   #
//##############################################################