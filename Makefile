MAKEFLAGS += --no-print-directory

NAME = minishell

CC = gcc
FLAGS = -Wextra -Werror -Wall -g

LIBFT = libft/libft.a

OBJDIR := obj

SRCDIR := srcs
INCDIR := includes

#SRCS := $(shell find $(SRCDIR) -name "*.c")

SRCS := srcs/builtins/ft_cd.c srcs/builtins/ft_echo.c srcs/builtins/ft_env.c \
		srcs/builtins/ft_exit.c srcs/builtins/ft_export.c srcs/builtins/ft_pwd.c \
		srcs/builtins/ft_unset.c srcs/env/env_list_to_tab.c srcs/env/init_env.c \
		srcs/execution/exec_utils.c srcs/execution/execute_multiple.c \
		srcs/execution/execute.c srcs/execution/handle_builtins.c srcs/execution/pipes_utils.c \
		srcs/parser/cmd_parsing.c srcs/parser/heredoc_utils.c srcs/parser/heredoc.c \
		srcs/parser/path_parsing.c srcs/parser/redirections.c \
		srcs/parser/token_bool.c srcs/parser/token_orga.c srcs/parser/token_utils.c \
		srcs/parser/token.c \
		srcs/utils/cleanup.c srcs/utils/cmd_parsing_util.c srcs/utils/env_utils.c \
		srcs/utils/exit_status.c srcs/utils/ft_signals.c srcs/utils/variable_expansion.c \
		srcs/utils/welcome_n_shlvl.c srcs/main.c
	
OBJS := $(SRCS:%.c=$(OBJDIR)/%.o)

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	@$(CC) $(FLAGS) $(OBJS) $(LIBFT) -lreadline -o $@
	@echo "🧰 minishell is minishelling... 🧰"

$(LIBFT):
	@make -C libft

$(OBJDIR)/%.o: %.c
	@mkdir -p $(dir $@)
	@$(CC) $(FLAGS) -I$(INCDIR) -c $< -o $@

clean:
	@rm -rf $(OBJDIR)
	@make clean -C ./libft

fclean: clean
	@rm -f $(NAME)
	@make fclean -C ./libft
	@echo "🧹 Adios, minishell 🧹"

re: fclean all

.PHONY: all clean fclean re bonus