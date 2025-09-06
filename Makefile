NAME = minishell

CC = cc

CFLAGS = -Wall -Wextra -Werror -g3
LDFLAGS = -lreadline

LIBFT = libft/libft.a

SRC = ./src/main.c ./src/signal.c ./src/init_shell.c ./src/parse.c

OBJ = $(SRC:.c=.o)

all: $(LIBFT) $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(LDFLAGS) $(LIBFT)
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(LDFLAGS) $(LIBFT)
	@echo "Compilation complete!"
	
$(LIBFT):
	@make -C libft -s
	@make -C libft -s

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@
	
clean:
	@rm -f $(OBJ)
	@make clean -C libft -s
	@make clean -C libft -s
	@echo "Object files removed!"
	
fclean: clean
	@rm -f $(NAME)
	@make fclean -C libft -s
	@make fclean -C libft -s
	@echo "Executable removed!"

re: fclean all
	@echo "Recompilation complete!"

valgrind: re
	valgrind -s \
		--tool=memcheck \
		--leak-check=full \
		--show-leak-kinds=all \
		--show-reachable=yes \
		--track-origins=yes \
		--trace-children=yes \
		--track-fds=yes \
		--suppressions=valgrind/valgrind.sup \
		--log-file=valgrind/informe.txt \
		./$(NAME)
.PHONY: all clean fclean re valgrind