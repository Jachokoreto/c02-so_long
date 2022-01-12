NAME = so_long

CC = gcc
CC_FLAGS = -Wall -Werror -Wextra 

SRC_DIR = ./src
OBJ_DIR = ./obj

SRC := $(shell find $(SRC_DIR) -name "*.c" -execdir basename {} \;)
OBJ := $(SRC:%.c=$(OBJ_DIR)/%.o)

INCLUDE = include

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME) -fsanitize=address -g3

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CC_FLAGS) -Imlx -I$(INCLUDE) -c $< -o $@

run: clean all
	clear
	./so_long

test:
	$(CC) test.c -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME) -fsanitize=address -g3
	# ./$(NAME)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm $(NAME)

re: fclean all
