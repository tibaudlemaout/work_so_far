##
## EPITECH PROJECT, 2022
## my_radar
## File description:
## makefile
##

SRC =	main.c	\
		src/radar.c		\
		src/info.c	\
		src/destroy_sf.c\
		src/script_to_tab.c	\
		src/create_objects.c	\
		src/usage_error.c	\
		src/handle_plane.c	\
		src/collision.c		\
		src/manage_clock.c	\
		lib/my_printf_conv.c	\
		lib/my_printf.c		\
		lib/resource.c		\

OBJ = 	$(SRC:.c=.o)

NAME = my_radar

CSFML = -lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio

all: 	$(NAME)

$(NAME): 	$(OBJ)
		@ar rc lib/libmy.a $(OBJ)
		@gcc -o $(NAME) main.c -L./lib/ -lmy -I ./include/ $(CSFML) -lm
		@rm  -f $(OBJ)

clean:
		rm -f $(OBJ)

fclean: clean
		rm -f $(NAME)
		rm -f lib/libmy.a

re:		fclean all
