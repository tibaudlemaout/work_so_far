##
## EPITECH PROJECT, 2023
## B-AIA-200-NAN-2-1-n4s-tibaud.le-maout
## File description:
## Makefile
##

SRC	=	main.c				\
		lib.c				\
		change_direction.c

OBJ =	$(SRC:.c=.o)

NAME =	ai

all:	$(NAME)

$(NAME):
		@gcc -o $(NAME) $(SRC)
		@rm -f $(OBJ)

clean:
		@rm -f $(OBJ)

fclean: clean
		@rm -f $(NAME)

re:		fclean all
