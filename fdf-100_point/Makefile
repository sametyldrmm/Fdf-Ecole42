NAME= fdf
CFLAGS= -Wall -Wextra -I $(MLX)
CC= gcc
SRC= fdf.c draw.c get_next_line.c get_next_line_utils.c libft.c main.c 
OBJ= $(SRC:.c=.o)

ifeq ($(shell uname -s), Linux)
	MLX = minilibx_linux
	MLX_FLAGS = $(MLX)/libmlx_Linux.a -lXext -lX11 -lm -lz
else
	MLX = minilibx_macos
	MLX_FLAGS = -framework OpenGL -framework AppKit $(MLX)/libmlx.a
endif

all: $(NAME)

$(NAME): $(OBJ)
	make -C $(MLX)
	gcc -o $(NAME) $(OBJ) -I $(MLX) -I libft $(CFLAGS) $(MLX_FLAGS) -o fdf -g

%.o : %.c FdF.h
	$(CC) -c -o $@ $< $(CFLAGS) -Wall -Wextra -Werror

clean:
	make clean -C $(MLX)
	rm -rf $(OBJ)

fclean:
	make clean -C $(MLX)
	rm -rf $(OBJ) $(NAME) texture

re: clean $(NAME)

.PHONY: all clean fclean re