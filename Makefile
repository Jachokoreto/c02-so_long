NAME = so_long

CC = gcc
CC_FLAGS = -Wall -Werror -Wextra -fsanitize=address -g3
MLX_FLAGS = -Lmlx -lmlx -framework OpenGL -framework AppKit

LIBFT = libft/libft.a
SRC_DIR = ./src
OBJ_DIR = ./obj
SRC := $(shell find $(SRC_DIR) -name "*.c" -execdir basename {} \;)
OBJ := $(SRC:%.c=$(OBJ_DIR)/%.o)

INCLUDE = -Iinclude -Imlx -Ilibft

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	@$(CC) $(CC_FLAGS) $(OBJ) $(MLX_FLAGS) -Llibft -lft -o $(NAME)
	@echo "${GREEN}Compile successful!${NC}"
	@echo Run program with ./so_long map/simple.ber

$(LIBFT):
	@make -C libft

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CC_FLAGS) $(INCLUDE) -c $< -o $@

run: clean all
	clear
	./$(NAME) map/simple.ber

test:
	$(CC) test.c $(MLX_FLAGS) $(NAME) 

clean:
	@rm -rf $(OBJ_DIR)]
	@echo "${RED}Removed all object files...${NC}"

fclean: clean
	@rm -rf $(NAME)
	@echo "${RED}Removed $(NAME)...${NC}"

re: fclean all

.PHONY: clean fclean re all

RED = \033[0;31m
GREEN = \033[0;32m
NC = \033[0m # No Color