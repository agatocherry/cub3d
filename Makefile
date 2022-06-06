# Variables

NAME	=	cub3d
HEADER	=	./include/cub3d.h
LIBFT	=	-L libft -lft
CC		=	gcc
CFLAGS	=	-I include/ 
# don't forget to use these flags : -Wall -Werror -Wextra
SRCS	=	src/main.c \
			src/parsing/lst/add.c src/parsing/lst/garbage.c \
			src/parsing/file.c src/parsing/color.c src/parsing/texture.c src/parsing/map.c src/parsing/error.c src/parsing/garbage.c
OBJ		=	$(SRCS:.c=.o)

# Colors

CYAN	=	'\033[0;36m'
RED		=	'\033[0;31m'
NOCOLOR	=	'\033[0m'

# Rules

all: $(NAME)

$(NAME):	$(OBJ) $(HEADER)
	@make -C libft/ --no-print-directory
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(LIBFT)
	@echo  $(CYAN)"Compiling $(NAME) done"$(NOCOLOR)

%.o: %.c $(HEADER)
	@$(CC) $(CFLAGS) -o $@ -c $<

clean:
	@rm -rf $(OBJ)
	@make clean -C libft/ --no-print-directory
	@echo $(RED)"! Removed $(OBJ)"$(NOCOLOR)

fclean: clean
	@rm -rf $(NAME)
	@make fclean -C libft/ --no-print-directory
	@echo $(RED)"! Removed $(NAME)"$(NOCOLOR)

re: fclean all

.PHONY: all clean fclean re