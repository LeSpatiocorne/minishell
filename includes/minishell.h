/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-brie <mle-brie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 09:14:52 by mle-brie          #+#    #+#             */
/*   Updated: 2025/06/23 16:51:10 by mle-brie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../libft/libft.h"
# include <readline/readline.h>
# include <readline/history.h>
# include <unistd.h>
# include <limits.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <sys/wait.h>
# include <sys/ioctl.h>
# include <errno.h>
# include <stdbool.h>
# include <signal.h>
# include <linux/limits.h>//just for my PC, please ignore
# define G		"\033[0;32m"//green colour
# define RES	"\033[0m"//put back to normal text
// use as such: printf(CYAN "test\n" RES);

# define MAX_ARGS 256//max number of args in bash
//global variable
extern int		g_signal;

//parsing struct
typedef enum e_token_type
{
	CMD,
	PIPE,
	REDIR_IN,
	REDIR_OUT,
	APPEND,
	HEREDOC,
	ARG,
	type_EOF
}	t_token_type;

typedef struct s_token
{
	char			*value;
	t_token_type	type;//not a pointer
	struct s_token	*next;//navigate
}	t_token;

//env struct
typedef struct s_env_list
{
	char				*key;//'PATH='
	char				*value;//everything after
	struct s_env_list	*next;//to navigate	
}	t_env_list;

// Structure pour les commandes
typedef struct s_cmd
{
	char			**args;
	struct s_cmd	*next;
	struct s_cmd	*prev;//double listed
	int				pipe_fd[2];
	int				input_fd;
	int				output_fd;
}	t_cmd;

typedef struct s_parsing_data
{
	t_cmd	*cmd_list;
	t_cmd	*current;
	char	**args;
	int		argc;
	t_token	*cmd_start;
}	t_parsing_data;

// enum  for the quote handle
typedef enum e_quote_state
{
	NORMAL,
	SINGLE_QUOTE,
	DOUBLE_QUOTE
}	t_quote_state;

// token specific validations booleans
bool			is_quote(char c);
bool			is_space_operator(char c);
bool			validate_syntax(t_token *tokens);

//redirs here
void			handle_redirs_per_cmd(t_token *start, t_token *end, t_cmd *cmd);
//heredoc
void			handle_heredoc(t_token *token, t_cmd *cmd);
void			heredoc_child(t_token *token, int pipe_fd[2]);
void			heredoc_parent(t_cmd *cmd, pid_t pid, int pipe_fd[2]);

//parsing here
//cmd parsing
char			*get_path(t_cmd *cmd, t_env_list *env);
// cmd functions
t_cmd			*parse_cmd_from_token(t_token *token, t_token *cmd_start,
					t_env_list *env);
void			add_cmd_node(t_cmd **cmd_list, t_cmd **current, char **args);
t_parsing_data	*init_parsing_data(void);
char			**process_pipe_or_end(t_parsing_data *p_data, t_token *token);
t_cmd			*create_cmd_node(char **args);
void			free_cmd_list(t_cmd *cmd);
t_cmd			*free_parsing_data(t_parsing_data *p_data);
// tokenization parsing
void			add_token(t_token **tokens, t_token_type type, char *value);
void			free_token_list(t_token **tokens);
bool			handle_signs(char **cmd_list, t_token **current);
void			set_type_to_cmd(t_token **tokens);
void			tokenization(t_token **tokens, char *readline);

//env things
char			*get_env_value(t_env_list *env, char *key);
void			update_env_value(t_env_list *env, char *key, char *value);
char			**env_list_to_tab(t_env_list *env);
t_env_list		*init_env(char **envp);

//execution
int				execute(t_cmd *cmd, t_env_list *env, t_token **tokens);
int				count_cmd(t_cmd *cmd_list);
int				multiple_cmds(t_cmd *cmd_list, t_env_list *env,
					t_token **tokens);
int				wait_for_all_children(pid_t *pids, int cmd_count);
pid_t			*fork_all_cmds(t_cmd *cmd_list, t_env_list *env,
					t_token **tokens);
int				single_cmd(t_cmd *cmd, t_cmd *cmd_list,
					t_env_list *env, t_token **tokens);
void			child_process(t_cmd *cmd, t_cmd *cmd_list,
					t_env_list *env, t_token **tokens);
//built-ins exec
bool			is_child_builtin(char *cmd);
int				handle_child_builtin(char **args, t_env_list *env);
bool			is_parent_builtin(char *cmd);
int				handle_parent_builtin(t_cmd *cmd, t_env_list *env,
					t_token **tokens);
//utils
void			dup2_helper_function(t_cmd *cmd, t_token **tokens,
					t_env_list *env);
void			fd_helper_function(t_cmd *cmd, t_cmd *cmd_list,
					t_token **tokens, t_env_list *env);//new

//Builtins
int				ft_pwd(void);
int				ft_cd(char **args, t_env_list *env);
int				ft_echo(char **args);
int				ft_exit(char **args, t_env_list *env, t_token **tokens,
					t_cmd *cmd);
int				ft_env(t_env_list *env);
int				ft_export(char **args, t_env_list *env);
int				ft_unset(char **args, t_env_list *env);

//Variable expansion utility
char			*expand_variables(char *str, t_env_list *env);

// Fonctions pour les pipes
//pipes utils
void			setup_pipes(t_cmd *cmd, t_token **tokens, t_env_list *env);
void			close_pipes(t_cmd *cmd);
void			close_pipes_except_current(t_cmd *cmd, t_cmd *cmd_list);

//utils misc
void			perror_failure(const char *error, t_token **tokens,
					t_cmd *cmd, t_env_list *env);
void			safe_close(int fd);//replace every close
void			free_tab(char **tab);
void			free_env_list(t_env_list *env);
void			free_all(t_token **tokens, t_cmd *cmd_list, t_env_list *env);
//exit_status
int				set_exit_status(int status);
int				get_exit_status(void);

// Signals
void			setup_signals(void);
void			set_signal_child(void);//add

//startup
void			handle_sigint(int sig);
void			startup_minishell(t_env_list *env);

#endif