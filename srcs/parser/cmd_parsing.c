/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-brie <mle-brie@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 16:47:05 by nidruon           #+#    #+#             */
/*   Updated: 2025/06/22 16:10:51 by mle-brie         ###   ########.fr       */
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

static void	add_cmd_node(t_cmd **cmd_list, t_cmd **current, char **args)
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

void	helper_parse(t_token *token, char **args, int *argc)
{
	if (token->type == REDIR_IN || token->type == HEREDOC
		|| token->type == APPEND || token->type == REDIR_OUT)
		token = token->next;
	else if (token->type == CMD || token->type == ARG)
		args[(*argc)++] = ft_strdup(token->value);
}

t_cmd	*parse_cmd_from_token(t_token *token, t_token *cmd_start,
								t_token *cmd_end, int argc)
{
	t_cmd	*cmd_list;
	t_cmd	*current;
	char	**args;

	args = malloc(sizeof(char *) * MAX_ARGS);
	current = NULL;
	cmd_list = NULL;
	while (token)
	{
		helper_parse(token, args, &argc);
		if (token->type == PIPE || !token->next)
		{
			args[argc] = NULL;
			add_cmd_node(&cmd_list, &current, args);
			cmd_end = token;
			handle_redirs_per_cmd(cmd_start, cmd_end, current);
			argc = 0;
			args = malloc(sizeof(char *) * MAX_ARGS);
			cmd_start = token->next;
		}
		token = token->next;
	}
	if (args)
		free(args);
	return (cmd_list);
}

//##############################################################
//# 				norminette compliant					   #
//##############################################################