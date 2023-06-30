##
## EPITECH PROJECT, 2022
## makefile
## File description:
## bsq
##

SRC =	main.c	\
		bubble_sort.c	\
		swap.c	\
		rotate_left.c	\
		rotate_right.c	\
		push.c	\
		lib/my_printf.c	\
		lib/my_printf_conv.c	\
		lib/resource.c	\
		lib/my_get_nbr.c	\

OBJ = 	$(SRC:.c=.o)

NAME = pushswap

all: 	$(NAME)

$(NAME): 	$(OBJ)
		ar rc lib/libmy.a $(OBJ)
		gcc -o $(NAME) main.c -L./lib/ -lmy
		rm  -f $(OBJ)

clean:
		rm -f $(OBJ)

fclean: clean
		rm -f $(NAME)
		rm -f lib/libmy.a

re:		fclean all
