NAME = libft.a

CC = cc
FLAGS = -Wextra -Werror -Wall -g -fPIE

OBJDIR := obj

SRCS = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c \
	ft_isascii.c ft_isdigit.c ft_isprint.c ft_memchr.c ft_memcmp.c \
	ft_memcpy.c ft_memmove.c ft_memset.c ft_strchr.c ft_strrchr.c \
	ft_strcat.c ft_strcpy.c \
	ft_strdup.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strncmp.c \
	ft_strnstr.c ft_tolower.c ft_toupper.c ft_substr.c ft_strjoin.c \
	ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c \
	ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
	ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c \
	ft_lstlast_bonus.c ft_lstadd_back_bonus.c ft_lstdelone_bonus.c \
	ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c \
	get_next_line.c \
	ft_printf.c print_char.c print_string.c print_num.c print_unsigned.c \
	print_lowhex.c print_uphex.c print_pointer.c \
	ft_utoa.c hexa_convert.c \
	ft_strcmp.c ft_strtok.c ft_strndup.c

OBJS := $(SRCS:%.c=$(OBJDIR)/%.o)

all: $(NAME)

$(NAME): $(OBJS)
	@ar rcs $@ $^
	@echo "🧰 Compiling libft...! 🧰"

$(OBJDIR)/%.o: %.c
	@mkdir -p $(OBJDIR)
	@$(CC) $(FLAGS) -c $< -o $@

clean:
	@rm -rf $(OBJDIR)

fclean: clean
	@rm -f $(NAME)
	@echo "🧰 ...Bye-bye libft... 🧹"

re: fclean all

.PHONY: all clean fclean re bonus libft