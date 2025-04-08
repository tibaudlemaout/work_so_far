##
## EPITECH PROJECT, 2024
## B-CCP-400-NAN-4-1-panoramix-tibaud.le-maout
## File description:
## Makefile
##

SRC =	main.c	\
		druid.c	\
		villager.c

OBJ =	$(SRC:.c=.o)

TEST =	tests/test.c

NAME =	panoramix

CSFML = -lcsfml-graphics -lcsfml-system -lcsfml-audio

CRITERION = --coverage -lcriterion

CC = gcc

all:	$(NAME)

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(CFLAGS)

test_run:
		gcc -o unit_test $(SRC) $(TEST) $(CRITERION) -I ./include/
		./unit_test

clean:
		rm -f $(OBJ)

fclean: clean
		rm -f $(NAME)

re:	fclean all
