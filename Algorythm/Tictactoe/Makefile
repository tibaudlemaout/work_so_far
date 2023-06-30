##
## EPITECH PROJECT, 2023
## GGJ
## File description:
## Makefile
##

SRC =		main.c	\
		init_structure.c	\
		verif_p_char.c	\
		get_attack.c	\
		create_map.c	\
		set_move_in_map.c \
		detect_win.c	\
		verif_diag_line.c	\
		draw_cond.c \
		free_map.c	\
		lib/resource.c	\

OBJ =	$(SRC:.c=.o)

NAME =	tictactoe

CSFML = -lcsfml-graphics -lcsfml-system -lcsfml-audio

all:	$(NAME)

$(NAME): $(OBJ)
		ar rc lib/libmy.a $(OBJ)
		gcc -o $(NAME) main.c -L ./lib/ -lmy -I ./include/

clean:
		rm -f $(OBJ)

fclean: clean
		rm -f $(NAME)
		rm -f lib/libmy.a

re:		fclean all
