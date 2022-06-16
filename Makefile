# Variables

CC		=	clang
CFLAGS	=	-g #-Wall -Werror -Wextra
NAME	=	cub3d
SRCS	=	src/main.c \
			src/parsing/file.c src/parsing/error.c src/parsing/garbage.c src/parsing/init.c \
			src/game/launch.c src/game/rotate.c src/game/movements.c \
			src/draw/drawWindow.c src/draw/textures.c src/draw/lines.c src/draw/ray.c
# src/parsing/color.c src/parsing/map.c src/parsing/texture.c
# src/parsing/lst/add.c src/parsing/lst/garbage.c
# src/draw/minimap.c
OBJ		=	$(SRCS:.c=.o)

# Rules

all: $(NAME)

$(NAME):	$(OBJ)
	@make -C libft --no-print-directory
	@make -C libmlx --no-print-directory
	@$(CC) $(OBJ) -o $(NAME) -lXext -lX11 -lm libmlx/libmlx_Linux.a libft/libft.a
	@echo "Compiling $(NAME) done"

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $<

clean:
	@rm -rf $(OBJ)
	@make clean -C libft --no-print-directory

fclean: clean
	@rm -rf $(NAME)
	@make clean -C libmlx --no-print-directory
	@make fclean -C libft --no-print-directory
	@echo "! Removed $(NAME)"

test: $(NAME)
	./$(NAME) maps/file.cub

vtest: $(NAME)
	valgrind ./$(NAME) maps/file.cub

re: fclean
	make all

.PHONY: all clean fclean re test vtest
