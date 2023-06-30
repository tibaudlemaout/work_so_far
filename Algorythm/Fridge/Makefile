##
## EPITECH PROJECT, 2022
## minishell1
## File description:
## Makefile
##

SRC	=	src/lib/my_put_nbr.c \
		src/lib/my_putchar.c \
		src/lib/my_putstr.c \
		src/lib/my_show_word_array.c \
		src/lib/my_strcmp.c \
		src/lib/my_strlen.c \
		src/lib/my_tablen.c \
		src/lib/is_int.c \
		src/lib/char_in_int.c \
		\
		src/main.c \
		src/parse_file.c \
		src/init.c \
		src/display_fridge.c \
		src/fridge_loop.c \
		src/make_dish.c	\
		src/make_pasta.c \
		src/add_to_fridge.c \

OBJ	=	$(SRC:.c=.o)

NAME	=	fridge

CFLAGS = -I ./include/

SOURCES = $(shell find $(SRCDIR) -name '*.o')

all:	$(NAME)

$(NAME):	$(OBJ)
	@gcc $(OBJ) -o $(NAME) $(CFLAGS)

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re:	fclean all
