/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-brie <mle-brie@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 21:57:24 by nidruon           #+#    #+#             */
/*   Updated: 2025/06/22 16:05:35 by mle-brie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

//global var
// int	g_exit_status = 0;//by default on success?

/*
This version of main, is "in part" what the subject expect.
ctrl+D is working fine, but ctrl+c will need an implementation to work
properly.
By in part I meant that it is just handling basic commands.
As an example, we still need to update the parsing method to
create the tokens.
Right now, my effort will be focused on the builtin completion.
*/
/*
int	main(int argc, char **argv, char **envp)
{
	t_env_list	*env;
	char		*line;
	t_cmd		*cmd_list = NULL;
	t_token		*tokens = NULL;

	(void)argc;
	(void)argv;
	env = init_env(envp);
	startup_minishell(env);
	while (1)
	{
		line = readline("mew-nishell$ ");
		if (!line)
			break ;
		if (*line)
			add_history(line);
		tokenization(&tokens, line);
	//temp to check
		temp_prints(&tokens);//to be deleted, obviously
	// ^ delete temp after ^
		cmd_list = parse_cmd_from_token(tokens);//do *not* delete this one
	//temp debug
		temp_print_cmds(cmd_list);
	// ^ delete other temp ^
		if (cmd_list)
		{
			execute(cmd_list, env, &tokens);//mod
		}
		free_cmd_list(cmd_list);
		cmd_list = NULL;//necessary for the free_all to not segfault after inputs
		free_token_list(&tokens);
		free(line);
	}
	free_all(&tokens, cmd_list, env);//test
	//should free env_list only at the end of everything
	rl_clear_history();//test
	return (0);
}
*/

/*
notes on the free_()
free_token_list works with **, so we set to NULL, and that's great
free_cmd_list works with *, so we just free, and we need to set to NULL 
for the free_all check
because, something already free'd is not a NULL, 
	=>so "free(thing not NULL)" will behave with a segfault sometimes
which mean: either we keep it like this, with the supp line
or I need to modify free_cmd and pretty much everything else lol
we'll see! coz it's more of an aesthetic thing for now
*/

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
	*cmd_list = parse_cmd_from_token(*tokens, *tokens, NULL, 0);
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
