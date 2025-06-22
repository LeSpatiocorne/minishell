/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nidruon <nidruon@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 22:03:23 by nidruon           #+#    #+#             */
/*   Updated: 2025/06/20 20:29:48 by nidruon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	process_extracted_quote(char *start, char **line_ptr,
	t_token **tokens)
{
	char	*word;

	if (**line_ptr)
	{
		(*line_ptr)++;
		word = ft_strndup(start, *line_ptr - start);
		add_token(tokens, ARG, word);
		free(word);
	}
	else
	{
		ft_putstr_fd("mew-nishell: unclosed quotes\n", 2);
		free_token_list(tokens);
		return (1);
	}
	return (0);
}

static int	handle_quoted_token(char **line_ptr, t_token **tokens)
{
	char			*start;
	t_quote_state	state;

	if (**line_ptr == '\'')
		state = SINGLE_QUOTE;
	else
		state = DOUBLE_QUOTE;
	start = *line_ptr;
	(*line_ptr)++;
	while (**line_ptr && ((state == SINGLE_QUOTE && **line_ptr != '\'')
			|| (state == DOUBLE_QUOTE && **line_ptr != '"')))
		(*line_ptr)++;
	return (process_extracted_quote(start, line_ptr, tokens));
}

static void	handle_unquoted_token(char **line_ptr, t_token **tokens)
{
	char	*start;
	char	*word;

	start = *line_ptr;
	while (**line_ptr && !is_space_operator(**line_ptr)
		&& !is_quote(**line_ptr))
		(*line_ptr)++;
	if (*line_ptr > start)
	{
		word = ft_strndup(start, *line_ptr - start);
		add_token(tokens, ARG, word);
		free(word);
	}
}

void	tokenization(t_token **tokens, char *readline)
{
	char	*line_ptr;

	line_ptr = readline;
	while (*line_ptr)
	{
		if (*line_ptr == ' ' || *line_ptr == '\t')
		{
			line_ptr++;
			continue ;
		}
		if (handle_signs(&line_ptr, tokens))
			continue ;
		if (is_quote(*line_ptr))
		{
			if (handle_quoted_token(&line_ptr, tokens))
				return ;
		}
		else
			handle_unquoted_token(&line_ptr, tokens);
	}
	set_type_to_cmd(tokens);
}
