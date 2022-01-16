NAME = so_long

CC = gcc
CC_FLAGS = -Wall -Werror -Wextra -fsanitize=address -g3

SRC_DIR = ./src
OBJ_DIR = ./obj

SRC := $(shell find $(SRC_DIR) -name "*.c" -execdir basename {} \;)
OBJ := $(SRC:%.c=$(OBJ_DIR)/%.o)

MLX_FLAGS = -Lmlx -lmlx -framework OpenGL -framework AppKit

INCLUDE = -Iinclude -Imlx -Ilibft

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CC_FLAGS) $(OBJ) $(MLX_FLAGS) -Llibft -lft -o $(NAME) 

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CC_FLAGS) $(INCLUDE) -c $< -o $@

run: clean all
	clear
	# ./so_long

test:
	$(CC) test.c $(MLX_FLAGS) $(NAME) 
	# ./$(NAME)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm $(NAME)

re: fclean all
