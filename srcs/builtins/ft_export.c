/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nidruon <nidruon@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 13:50:16 by nidruon           #+#    #+#             */
/*   Updated: 2025/05/29 14:09:00 by nidruon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	add_env_var(t_env_list *env, char *key, char *value)
{
	t_env_list	*current;

	current = env;
	while (current->next)
		current = current->next;
	current->next = malloc(sizeof(t_env_list));
	current->next->key = ft_strdup(key);
	if (value)
		current->next->value = ft_strdup(value);
	else
		current->next->value = ft_strdup("");
	current->next->next = NULL;
}

static void	print_export_list(t_env_list *env)
{
	t_env_list	*cur;

	cur = env;
	while (cur)
	{
		printf("declare -x %s=\"%s\"\n", cur->key, cur->value);
		cur = cur->next;
	}
}

static void	handle_export_arg(char *arg, t_env_list *env)
{
	char	*eq;
	char	*key;

	eq = ft_strchr(arg, '=');
	if (eq)
	{
		key = ft_strndup(arg, eq - arg);
		if (get_env_value(env, key))
			update_env_value(env, key, eq + 1);
		else
			add_env_var(env, key, eq + 1);
		free(key);
	}
	else if (!get_env_value(env, arg))
		add_env_var(env, arg, "");
}

int	ft_export(char **args, t_env_list *env)
{
	int	i;

	if (!args[1])
		return (print_export_list(env), 0);
	i = 0;
	while (args[++i])
		handle_export_arg(args[i], env);
	return (0);
}
