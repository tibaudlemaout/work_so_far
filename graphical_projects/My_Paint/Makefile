##
## EPITECH PROJECT, 2023
## GGJ
## File description:
## Makefile
##

SRC =	src/main.c							\
		lib.c								\
		src/init/structs.c					\
		src/init/buttons.c					\
		src/init/colors.c					\
		src/init/side_menu.c				\
		src/init/tools_editing.c			\
		src/draw.c							\
		src/events.c						\
		src/side_menu.c

OBJ =	$(SRC:.c=.o)

NAME =	my_paint

CSFML = -lcsfml-graphics -lcsfml-system -lcsfml-audio -lcsfml-window

all:	$(NAME)

$(NAME):
		@gcc -o $(NAME) $(SRC) $(CSFML) -lm
		@rm -f $(OBJ)

clean:
		@rm -f $(OBJ)

fclean: clean
		@rm -f $(NAME)

re:		fclean all
