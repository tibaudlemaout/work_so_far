##
## EPITECH PROJECT, 2023
## GGJ
## File description:
## Makefile
##

SRC =	src/main.c	\
	src/count_letters.c \
	src/display.c \
	src/check.c	\
	src/remaining_letters.c 	\
	src/do_arg_t.c	\
	src/arrange_display.c	\

OBJ =	$(SRC:.c=.o)

NAME =	text_count

CSFML = -lcsfml-graphics -lcsfml-system -lcsfml-audio

all:	$(NAME)

$(NAME): $(OBJ)
		ar rc lib/libmy.a $(OBJ)
		gcc -o $(NAME) src/main.c -L ./lib/ -lmy -I ./include/

clean:
		rm -f $(OBJ)

fclean: clean
		rm -f $(NAME)
		rm -f lib/libmy.a

re:		fclean all
