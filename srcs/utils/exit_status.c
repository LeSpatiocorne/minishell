/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_status.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-brie <mle-brie@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 15:03:44 by mle-brie          #+#    #+#             */
/*   Updated: 2025/06/20 23:32:45 by mle-brie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	exit_status(int i)
{
	static int	status = 0;

	if (i >= 0)
		status = i;
	return (status);
}

int	set_exit_status(int status)
{
	exit_status(status);
	return (status);
}

int	get_exit_status(void)
{
	return (exit_status(-1));
}
