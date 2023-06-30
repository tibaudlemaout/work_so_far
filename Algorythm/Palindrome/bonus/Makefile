##
## EPITECH PROJECT, 2023
## B-SYN-200-NAN-2-1-palindrome-tibaud.le-maout
## File description:
## Makefile
##
SRC =	main.c	\

OBJ =	$(SRC:.c=.o)

NAME =	bonus

CSFML = -lcsfml-graphics -lcsfml-system -lcsfml-audio

all:	$(NAME)

$(NAME): $(OBJ)
		ar rc libmy.a $(OBJ)
		gcc -o $(NAME) main.c -L./ -lmy -I ./include/

clean:
		rm -f $(OBJ)

fclean: clean
		rm -f $(NAME)
		rm -f libmy.a

re:		fclean all
