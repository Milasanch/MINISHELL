NAME = minishell

CC = cc

CFLAGS = -Wall -Wextra -Werror

LIBFT = libft/libft.a

SRC = 

OBJ = $(SRC:.c=.o)

all: $(LIBFT) $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(LIBFT)
	@echo "Compilation complete!"
	
$(LIBFT):
	@make -C libft

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@
	
clean:
	@rm -f $(OBJ)
	@make clean -C libft
	@echo "Object files removed!"
	
fclean: clean
	@rm -f $(NAME)
	@make fclean -C libft
	@echo "Executable removed!"

re: fclean all
	@echo "Recompilation complete!"
.PHONY: all clean fclean re