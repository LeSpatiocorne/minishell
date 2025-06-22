/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-brie <mle-brie@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 03:52:00 by nidruon           #+#    #+#             */
/*   Updated: 2025/05/15 13:15:49 by mle-brie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_env(t_env_list *env)
{
	t_env_list	*current;

	if (!env)
		return (1);
	current = env;
	while (current)
	{
		if (current->value)
		{
			ft_putstr_fd(current->key, 1);
			ft_putstr_fd("=", 1);
			ft_putstr_fd(current->value, 1);
			ft_putchar_fd('\n', 1);
		}
		current = current->next;
	}
	return (0);
}

/*
notes:
by using a text comparator, I see that there are some missing things:
WT_SESSION is in bash, not in ours
WSLENV= is empty for us
WT_PROFILE_ID is also missing
(+WSL_INTEROP is not same code, but I think it's normal
same for the _=, but seems pretty logical too honestly)
*/