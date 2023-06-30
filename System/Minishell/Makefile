##
## EPITECH PROJECT, 2023
## GGJ
## File description:
## Makefile
##

SRC =	main.c						\
		manage_child.c				\
		arg_to_tab.c				\
		find_path.c					\
		copy_path.c					\
		create_path.c				\
		free_all.c					\
		new_functions/cd.c			\
		new_functions/cd_options.c	\
		new_functions/env.c			\
		new_functions/exit.c		\
		new_functions/add_rmv_env_line.c	\
		new_functions/setenv.c		\
		new_functions/unsetenv.c	\
		lib/resource.c				\
		lib/resource_2.c			\
		lib/my_strcpy.c				\
		lib/my_printf.c				\
		lib/my_printf_conv.c		\

OBJ =	$(SRC:.c=.o)

NAME =	mysh

CSFML = -lcsfml-graphics -lcsfml-system -lcsfml-audio

CFLAGS = -g

all:	$(NAME)

$(NAME): $(OBJ)
		@ar rc lib/libmy.a $(OBJ)
		@gcc -o $(NAME) main.c -L./lib/ -lmy -I ./include/
		@rm  -f $(OBJ)

clean:
		@rm -f $(OBJ)

fclean: clean
		@rm -f $(NAME)
		@rm -f lib/libmy.a

re:		fclean all
