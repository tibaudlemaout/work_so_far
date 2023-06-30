##
## EPITECH PROJECT, 2022
## makefile
## File description:
## bsq
##

SRC =	main.c	\
		bsq.c	\
		algorithm.c	\
		disp_algo.c	\
		map_generation.c	\
		generated_algo.c	\
		generated_disp.c	\
		lib/my_printf.c	\
		lib/my_printf_conv.c	\
		lib/resource.c	\
		lib/my_strcpy.c	\
		lib/bsq_strlen.c	\

OBJ = 	$(SRC:.c=.o)

NAME = bsq

all: 	$(NAME)

$(NAME): 	$(OBJ)
		@ar rc lib/libmy.a $(OBJ)
		@gcc -o $(NAME) bsq.c -L./lib/ -lmy
		@rm  -f $(OBJ)

clean:
		rm -f $(OBJ)

fclean: clean
		rm -f $(NAME)
		rm -f lib/libmy.a

re:		fclean all
