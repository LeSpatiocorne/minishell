/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-brie <mle-brie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 21:57:24 by nidruon           #+#    #+#             */
/*   Updated: 2025/06/23 16:42:49 by mle-brie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static void	init_vars(t_cmd **cmd_list, t_token **tokens)
{
	*cmd_list = NULL;
	*tokens = NULL;
}

static void	process_line(char *line, t_token **tokens,
						t_cmd **cmd_list, t_env_list *env)
{
	if (*line)
		add_history(line);
	tokenization(tokens, line);
	if (!tokens || !validate_syntax((*tokens)))
		free_token_list(tokens);
	*cmd_list = parse_cmd_from_token(*tokens, *tokens, env);
	if (*cmd_list)
		execute(*cmd_list, env, tokens);
}

static void	cleanup_iteration(t_cmd **cmd_list, t_token **tokens, char *line)
{
	free_cmd_list(*cmd_list);
	*cmd_list = NULL;
	free_token_list(tokens);
	free(line);
}

int	main(int argc, char **argv, char **envp)
{
	t_env_list	*env;
	char		*line;
	t_cmd		*cmd_list;
	t_token		*tokens;

	init_vars(&cmd_list, &tokens);
	if (argc != 1 || argv[1])
	{
		printf("mew-nishell: unecessary arguments after execution\n");
		return (1);
	}
	env = init_env(envp);
	startup_minishell(env);
	setup_signals();
	while (1)
	{
		line = readline("mew-nishell$ ");
		if (!line)
			break ;
		process_line(line, &tokens, &cmd_list, env);
		cleanup_iteration(&cmd_list, &tokens, line);
	}
	rl_clear_history();
	free_all(&tokens, cmd_list, env);
	return (0);
}
