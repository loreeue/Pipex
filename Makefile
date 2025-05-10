NAME = pipex

SRC = pipex.c execute_commands.c manage_parser.c utils.c exec_child.c find_path.c files.c heredoc.c\
	gnl/get_next_line.c gnl/get_next_line_utils.c frees.c\

OBJ_DIR = obj
OBJ = $(SRC:%.c=$(OBJ_DIR)/%.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror -g -fsanitize=address

$(NAME): $(OBJ)
	@cd libft && $(MAKE) > /dev/null
	@$(CC) $(CFLAGS) $(OBJ) -L ./libft -lft -o $(NAME)

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@cd libft && $(MAKE) clean > /dev/null
	@rm -rf $(OBJ_DIR)
	@echo "Clean complete!"

fclean: clean
	@cd libft && $(MAKE) fclean > /dev/null
	@rm -f $(NAME)
	@echo "Full clean complete!"

all: $(NAME)

re:	fclean all

.PHONY: clean fclean all re
