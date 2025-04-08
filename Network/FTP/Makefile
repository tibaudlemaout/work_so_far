##
## EPITECH PROJECT, 2024
## Semester_3
## File description:
## Makefile
##

SRC =	server.c	\
		client_handling.c

OBJ =	$(SRC:.c=.o)

TEST = 	tests/test.c

NAME =	myftp

CSFML = -lcsfml-graphics -lcsfml-system -lcsfml-audio

CRITERION = --coverage -lcriterion

all:	$(NAME)

$(NAME): $(OBJ)
		gcc -o $(NAME) $(SRC) -I ./include/
		rm -f $(OBJ)

test_run:
		gcc -o unit_test $(SRC) $(TEST) $(CRITERION) -I ./include/
		./unit_test

clean:
		rm -f $(OBJ)

fclean: clean
		rm -f $(NAME)

re:		fclean all
