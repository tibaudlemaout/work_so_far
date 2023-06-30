##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## my ls
##

SRC =	my_ls.c		\
		ls_a.c 	\
		ls_l.c 	\
		ls_r_maj.c 	\
		manage_flag.c	\
		lib/my_printf_conv.c	\
		lib/my_printf.c	\
		lib/resource.c

OBJ = 	$(SRC:.c=.o)

NAME = my_ls

all: 	$(NAME)

$(NAME): 	$(OBJ)
		@ar rc lib/libmy.a $(OBJ)
		@gcc -o $(NAME) my_ls.c -L./lib/ -lmy
		@rm  -f $(OBJ)

clean:
		@rm -f $(OBJ)

fclean: clean
		@rm -f $(NAME)
		@rm -f lib/libmy.a

re:		fclean all
