# Variables

CC		=	clang
CFLAGS	=	-g 
# -Wall -Werror -Wextra
NAME	=	cub3d
SRCS	=	src/main.c \
			src/parsing/lst/add.c src/parsing/lst/garbage.c \
			src/parsing/file.c src/parsing/color.c src/parsing/texture.c src/parsing/map.c src/parsing/error.c src/parsing/garbage.c \
			src/game/launch.c src/game/keys.c src/draw/drawWindow.c
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

re: fclean all