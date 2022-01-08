CC = gcc
CC_FLAGS = -Wall -Werror -Wextra

SRC = test.c
OBJ = $(SRC:%.c=%.o)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

%.o: %.c
	$(CC) $(CC_FLAGS) -Imlx -c $< -o $@

