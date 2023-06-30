##
## EPITECH PROJECT, 2023
## Synthesis
## File description:
## Makefile
##

SRC =	src/main.c	\
		src/error_handling.c	\
		src/display_h.c	\
		src/is_palindrome.c	\
		src/display_p.c	\
		src/base_calc.c	\
		requirement.c	\

OBJ =	$(SRC:.c=.o)

NAME =	palindrome

CSFML = -lcsfml-graphics -lcsfml-system -lcsfml-audio

all:	$(NAME)

$(NAME): $(OBJ)
		ar rc libmy.a $(OBJ)
		gcc -o $(NAME) src/main.c -L./ -lmy -I ./include/

clean:
		rm -f $(OBJ)

fclean: clean
		rm -f $(NAME)
		rm -f libmy.a

re:		fclean all
