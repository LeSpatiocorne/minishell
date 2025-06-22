/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-brie <mle-brie@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 15:46:17 by mle-brie          #+#    #+#             */
/*   Updated: 2025/06/22 15:15:42 by mle-brie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	handle_pipes(char **line_ptr, t_token **current)
{
	if (**line_ptr == '|')
	{
		add_token(current, PIPE, "|");
		(*line_ptr)++;
		return (true);
	}
	return (false);
}

bool	handle_in(char **line_ptr, t_token **current)
{
	if (**line_ptr == '<')
	{
		if (*(*line_ptr + 1) == '<')
		{
			add_token(current, HEREDOC, "<<");
			(*line_ptr) += 2;
		}
		else
		{
			add_token(current, REDIR_IN, "<");
			(*line_ptr)++;
		}
		return (true);
	}
	return (false);
}

bool	handle_out(char **line_ptr, t_token **current)
{
	if (**line_ptr == '>')
	{
		if (*(*line_ptr + 1) == '>')
		{
			add_token(current, APPEND, ">>");
			(*line_ptr) += 2;
		}
		else
		{
			add_token(current, REDIR_OUT, ">");
			(*line_ptr)++;
		}
		return (true);
	}
	return (false);
}

bool	handle_signs(char **line_ptr, t_token **current)
{
	return (handle_pipes(line_ptr, current)
		|| handle_in(line_ptr, current)
		|| handle_out(line_ptr, current));
}

void	set_type_to_cmd(t_token **tokens)
{
	t_token	*current;
	bool	expecting_cmd;

	expecting_cmd = true;
	current = *tokens;
	while (current)
	{
		if (expecting_cmd && current->type == ARG)
		{
			current->type = CMD;
			expecting_cmd = false;
		}
		if (current->type == PIPE)
			expecting_cmd = true;
		current = current->next;
	}
}
