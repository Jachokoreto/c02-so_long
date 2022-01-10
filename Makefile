NAME = so_long

CC = gcc
CC_FLAGS = -Wall -Werror -Wextra

SRC = $(shell find ./src)
OBJ = $(SRC:%.c=%.o)

DEPS = $(shell find ./include)


all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

%.o: %.c
	$(CC) $(CC_FLAGS) -Imlx -c $< -o $@

test: $(NAME)
	./so_long



clean: 
	rm -rf *.o

fclean: clean
	rm $(NAME)

re: fclean all
