NAME = minishell

CC = cc

CFLAGS = -Wall -Wextra -Werror
LDFLAGS = -lreadline

LIBFT = libft/libft.a

SRC = ./src/main.c ./src/signal.c ./src/init_shell.c ./src/parse.c

OBJ = $(SRC:.c=.o)

all: $(LIBFT) $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(LDFLAGS) $(LIBFT)
	@echo "Compilation complete!"
	
$(LIBFT):
	@make -C libft -s

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@
	
clean:
	@rm -f $(OBJ)
	@make clean -C libft -s
	@echo "Object files removed!"
	
fclean: clean
	@rm -f $(NAME)
	@make fclean -C libft -s
	@echo "Executable removed!"

re: fclean all
	@echo "Recompilation complete!"
.PHONY: all clean fclean re