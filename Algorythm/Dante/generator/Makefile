##
## EPITECH PROJECT, 2023
## Semester_2
## File description:
## Makefile
##

SRC =	main.c			\
		error_handling_gen.c	\
		display_gen_map.c	\

OBJ =	$(SRC:.c=.o)

NAME =	generator

CSFML = -lcsfml-graphics -lcsfml-system -lcsfml-audio

all:	$(NAME)

$(NAME): $(OBJ)
		@ar rc libmy.a $(OBJ)
		@gcc -o $(NAME) main.c -L ./ -lmy -I ./include/
		@rm  -f $(OBJ)

clean:
		@rm -f $(OBJ)

fclean: clean
		@rm -f $(NAME)
		@rm -f libmy.a

re:		fclean all
