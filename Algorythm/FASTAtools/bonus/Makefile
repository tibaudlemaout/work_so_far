##
## EPITECH PROJECT, 2023
## base_layout
## File description:
## Makefile
##

SRC =	src/main.c	\
		src/error_handling.c	\
		src/bubble_sort.c	\
		src/get_input.c	\
		src/option_1.c	\
		src/option_2.c	\
		src/option_3.c	\
		src/option_3_rev.c	\
		src/option_4.c	\
		src/option_4_kmer.c	\
		src/option_5.c	\
		src/option_5_seq.c	\
		src/option_5_rna.c	\
		src/option_5_6_sort_seq.c	\
		src/option_6.c	\
		src/option_6_acid.c	\
		src/option_6_acid_list.c	\
		src/option_7.c	\

OBJ =	$(SRC:.c=.o)

TEST = 	tests/test.c

NAME =	Bonustools

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
		rm -f libmy.a
		rm -f unit_*

re:		fclean all
