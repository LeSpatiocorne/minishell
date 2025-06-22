MAKEFLAGS += --no-print-directory

NAME = minishell

CC = gcc
FLAGS = -Wextra -Werror -Wall -g

LIBFT = libft/libft.a

OBJDIR := obj

SRCDIR := srcs
INCDIR := includes

SRCS := $(shell find $(SRCDIR) -name "*.c")

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