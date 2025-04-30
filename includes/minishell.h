/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nidruon <nidruon@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 23:16:29 by nidruon           #+#    #+#             */
/*   Updated: 2025/04/30 23:23:12 by nidruon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <signal.h>

/*
****************|	 GLOBAL VARIABLE	|****************
* Work as a security to avoid multiple signals to		* 
* be executed at the same time							*
* When a signal is processed, it sets g_sig to 1		*
* Any other signal will be Queued and executed in		*
* order after the previous one.							*
*********************************************************
*/
extern int g_sig;

#endif