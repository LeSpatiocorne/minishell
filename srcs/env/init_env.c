/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nidruon <nidruon@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 03:08:13 by nidruon           #+#    #+#             */
/*   Updated: 2025/05/04 03:22:30 by nidruon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_env_list	*new_env_node(char *env_var)
{
	t_env_list	*node;
	int			i;

	node = malloc(sizeof(t_env_list));
	if (!node)
		return (NULL);
	i = 0;
	while (env_var[i] && env_var[i] != '=')
		i++;
	node->key = ft_substr(env_var, 0, i);
	node->value = NULL;
	if (env_var[i] == '=')
		node->value = ft_strdup(env_var + i + 1);
	node->next = NULL;
	return (node);
}

t_env_list	*init_env(char **envp)
{
	t_env_list	*head;
	t_env_list	*current;
	t_env_list	*new;

	head = NULL;
	while (*envp)
	{
		new = new_env_node(*envp);
		if (!new)
			return (perror("minishell: env"), NULL);
		if (!head)
			head = new;
		else
			current->next = new;
		current = new;
		envp++;
	}
	return (head);
}
