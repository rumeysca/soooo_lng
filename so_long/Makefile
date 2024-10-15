NAME = so_long
CC = gcc
FLAGS = -Wall -Wextra -Werror
FRAMES = -framework OpenGL -framework AppKit
SOURCES = 	so_long.c \
			map_init.c \
			map_read.c \
			map_reach.c \
			map_char.c \
			map_wall.c 
OBJS = $(SOURCES:.c=.o)

MLX = ./mlx/libmlx.a
LIBFT = ./libft/libft.a
PRINTF = ./ft_printf/libftprintf.a
GNL = ./get_next_line/gnl.a

all: $(NAME)

$(NAME): $(OBJS) $(MLX) $(LIBFT) $(GNL) $(PRINTF) 
	$(CC) $(FLAGS) -o $(NAME) $(OBJS) $(MLX) $(LIBFT) $(GNL) $(PRINTF) $(FRAMES)

$(OBJS): $(SOURCES)
	$(CC) $(FLAGS) -c ${SOURCES}

$(MLX):
	@${MAKE} -C ./mlx

$(LIBFT):
	@${MAKE} -C ./libft

$(PRINTF):
	@${MAKE} -C ./ft_printf

$(GNL):
	@${MAKE} -C ./get_next_line

clean:
	rm -f ${OBJS}
	@${MAKE} clean -C ./ft_printf
	@${MAKE} clean -C ./mlx
	@${MAKE} clean -C ./libft
	@${MAKE} clean -C ./get_next_line

fclean: clean
	rm -f so_long
	@${MAKE} fclean -C ./ft_printf
	@${MAKE} fclean -C ./libft
	@${MAKE} fclean -C ./get_next_line

re:fclean all
