NAME= fdf
CFLAGS= -Wall -Wextra -I $(MLX) 
CC= gcc

SRC= get_next_line.c get_next_line_utils.c yeni_fdf.c draw.c veri_al.c utils_and_key.c utils_and_key2.c start_and_free.c draw_pach.c utils.c utils1.c
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
	gcc -o $(NAME) $(OBJ) -I $(MLX) -I libft $(CFLAGS) $(MLX_FLAGS) -o fdf

%.o : %.c FdF.h
	$(CC) -c -o $@ $< $(CFLAGS)

clean:
	make clean -C $(MLX)
	rm -rf $(OBJ)

fclean:
	make clean -C $(MLX)
	rm -rf $(OBJ) $(NAME) texture

re: clean $(NAME)

.PHONY: all clean fclean re