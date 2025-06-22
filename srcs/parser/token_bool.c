/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_bool.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-brie <mle-brie@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 22:02:05 by nidruon           #+#    #+#             */
/*   Updated: 2025/06/22 15:34:52 by mle-brie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	is_quote(char c)
{
	return (c == '\'' || c == '"');
}

bool	is_space_operator(char c)
{
	if (c == ' ' || c == '\t'
		|| c == '<' || c == '>' || c == '|')
		return (true);
	return (false);
}

static void	syntax_error_message(char *token)
{
	ft_putstr_fd("mew-nishell: ", 2);
	ft_putstr_fd("syntax error near unexpected token '", 2);
	ft_putstr_fd(token, 2);
	ft_putstr_fd("'\n", 2);
}

bool	validate_syntax(t_token *tokens)
{
	t_token	*current;

	current = tokens;
	while (current)
	{
		if (current->type == PIPE)
		{
			if (!current->next || current->next->type != CMD)
			{
				syntax_error_message("|");
				return (false);
			}
		}
		else if (current->type == REDIR_IN || current->type == HEREDOC
			|| current->type == REDIR_OUT || current->type == APPEND)
		{
			if (!current->next || current->next->type != ARG)
			{
				syntax_error_message("redir");
				return (false);
			}
		}
		current = current->next;
	}
	return (true);
}
