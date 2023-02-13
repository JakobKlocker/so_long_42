NAME = so_long
SRC = so_long.c map_checks.c map_checks_1.c map_reading.c map_related.c graphic_draw.c graphic_moves.c error_mem.c
OBJ = $(SRC:.c=.o)
CC = cc
FLAG = -Wall -Werror -Wextra
OPTION = -o

all: $(NAME)

$(NAME):
		$(MAKE) all -C ./libft
#		$(MAKE) all -C ./minilibx-linux
		$(CC) $(OPTION) $(NAME) $(FLAG) $(SRC) ./libft/libft.a ./mlx/libmlx_Linux.a -lXext -lX11

clean: 
		$(MAKE) clean -C ./libft
#		$(MAKE) clean -C ./minilibx-linux
		rm -f $(OBJ)

fclean: clean
		$(MAKE) fclean -C ./libft
		rm -f $(NAME)

re:		fclean all

bonus:	all

.PHONY: all bonus clean fclean re