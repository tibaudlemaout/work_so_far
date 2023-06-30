##
## EPITECH PROJECT, 2023
## B-CPE-200-NAN-2-1-dante-tibaud.le-maout
## File description:
## Makefile
##

SRC =	main.c							\
		lib.c							\
		dead_end.c						\
		path.c

OBJ =	$(SRC:.c=.o)

NAME =	solver

all:	$(NAME)

$(NAME):
		@gcc -o $(NAME) $(SRC)
		@rm -f $(OBJ)

clean:
		@rm -f $(OBJ)

fclean: clean
		@rm -f $(NAME)

re:		fclean all
