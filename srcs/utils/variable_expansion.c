/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   variable_expansion.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nidruon <nidruon@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 13:25:00 by nidruon           #+#    #+#             */
/*   Updated: 2025/06/22 16:52:37 by nidruon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*handle_expansion(char *str, int *i, t_env_list *env);
static char	*process_no_quotes(char *str, t_env_list *env, int i, char *result);
static char	*process_single_quotes(char *str);
static char	*process_double_quotes(char *str, t_env_list *env);

char	*expand_variables(char *str, t_env_list *env)
{
	if (!str)
		return (NULL);
	if (str[0] == '\'')
		return (process_single_quotes(str));
	if (str[0] == '\"')
		return (process_double_quotes(str, env));
	return (process_no_quotes(str, env, 0, ft_strdup("")));
}

static char	*process_single_quotes(char *str)
{
	int		len;
	char	*unquoted;

	len = ft_strlen(str);
	if (len >= 2 && str[0] == '\'' && str[len - 1] == '\'')
	{
		unquoted = ft_substr(str, 1, len - 2);
		return (unquoted);
	}
	return (ft_strdup(str));
}

static char	*process_double_quotes(char *str, t_env_list *env)
{
	int		len;
	char	*sub;
	char	*result;

	len = ft_strlen(str);
	if (len < 2)
		return (ft_strdup(str));
	sub = ft_substr(str, 1, len - 2);
	if (!sub)
		return (ft_strdup(""));
	result = process_no_quotes(sub, env, 0, ft_strdup(""));
	free(sub);
	return (result);
}

static char	*process_no_quotes(char *str, t_env_list *env, int i, char *result)
{
	char	*temp;
	char	*part;
	int		j;

	while (str[i])
	{
		j = i;
		while (str[j] && str[j] != '$')
			j++;
		part = ft_substr(str, i, j - i);
		temp = ft_strjoin(result, part);
		free(result);
		free(part);
		result = temp;
		i = j;
		if (str[i] == '$')
		{
			part = handle_expansion(str, &i, env);
			temp = ft_strjoin(result, part);
			free(result);
			free(part);
			result = temp;
		}
	}
	return (result);
}

static char	*handle_expansion(char *str, int *i, t_env_list *env)
{
	char	*var_name;
	char	*var_value;
	int		j;

	(*i)++;
	if (str[*i] == '?')
	{
		(*i)++;
		return (ft_itoa(get_exit_status()));
	}
	if (!ft_isalpha(str[*i]) && str[*i] != '_')
		return (ft_strdup("$"));
	j = *i;
	while (ft_isalnum(str[j]) || str[j] == '_')
		j++;
	var_name = ft_substr(str, *i, j - *i);
	*i = j;
	if (!var_name)
		return (ft_strdup(""));
	var_value = get_env_value(env, var_name);
	free(var_name);
	if (var_value)
		return (ft_strdup(var_value));
	return (ft_strdup(""));
}
