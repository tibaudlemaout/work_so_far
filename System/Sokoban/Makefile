##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## for sokoban
##

SRC =	main.c	\
		sokoban.c	\
		lib/my_printf.c	\
		lib/my_printf_conv.c	\
		lib/resource.c	\
		lib/my_strcpy.c	\
		usage_error.c	\
		manage_game.c	\
		move.c	\
		for_end.c	\
		for_win.c	\
		for_lose.c	\

OBJ = 	$(SRC:.c=.o)

NAME = my_sokoban

all: 	$(NAME)

$(NAME): 	$(OBJ)
		ar rc lib/libmy.a $(OBJ)
		gcc -o $(NAME) main.c -L./lib/ -lmy -lncurses
		rm  -f $(OBJ)

clean:
		rm -f $(OBJ)

fclean: clean
		rm -f $(NAME)
		rm -f lib/libmy.a

re:		fclean all
