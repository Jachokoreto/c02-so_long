SRCS = src/*.c
INCLUDE = include
CC = gcc
# CC_FLAGS = -Wall -Werror -Wextra -fsanitize=address
MLX_FLAGS_LINUX = -Lmlx_linux -lmlx_linux -I/usr/include -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz
MLX_FLAGS_MAC = -Lmlx -lmlx -framework OpenGL -framework AppKit
NAME=so_long

all : 
	@echo "make [OS]"

linux :
	cd mlx_linux && ./configure
	$(CC) $(CC_FLAGS) $(SRCS)  $(MLX_FLAGS_LINUX)  -I$(INCLUDE) -o $(NAME)

mac : 
	$(CC) $(CC_FLAGS) $(MLX_FLAGS_MAC) $(SRCS) -I$(INCLUDE) -o $(NAME)

clean :
	rm -rf *.o

fclean : clean
	rm -rf $(NAME)
