##
## EPITECH PROJECT, 2024
## B-CNA-410-NAN-4-1-trade-thomas-cluseau
## File description:
## Makefile
##
SRC =   Main.cpp    \
		Bot.cpp

OBJ =	$(SRC:.cpp=.o)

TEST =	tests/test.c

NAME =	trade

CSFML = -lcsfml-graphics -lcsfml-system -lcsfml-audio

CRITERION = --coverage -lcriterion

CC = g++

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
