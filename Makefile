CC = gcc
CC_FLAGS = -Wall -Werror -Wextra

SRC = test.c
OBJ = $(SRC:%.c=%.o)

NAME = so_long

$(NAME): $(OBJ)
	$(CC) $(OBJ) -Lmlx -lmlx -framework OpenGL -framework AppKit -v -o $(NAME)

%.o: %.c
	$(CC) $(CC_FLAGS) -Imlx -c $< -o $@

test: $(NAME)
	fclean && $(NAME) ||  ./$<

clean: 
	rm -rf *.o

fclean: clean
	rm $(NAME)
