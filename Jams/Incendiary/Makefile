##
## EPITECH PROJECT, 2023
## GGJ
## File description:
## Makefile
##

SRC =	src/main.c					\
		src/main_menu.c				\
		src/keybinds_menu.c			\
		src/music.c					\
		src/play/play.c				\
		src/play/init_game.c		\
		src/play/fire.c				\
		src/play/read_script.c		\
		src/play/get_script.c		\
		src/play/countdown.c		\
		src/play/events.c			\
		src/destroy_all.c			\
		src/end/lose.c				\
		src/end/win.c				\
		src/play_villain.c

OBJ =	$(SRC:.c=.o)

NAME =	incendiary

CSFML = -lcsfml-graphics -lcsfml-system -lcsfml-audio

all:	$(NAME)

$(NAME):
		@gcc -o $(NAME) $(SRC) $(CSFML)
		@rm -f $(OBJ)

clean:
		@rm -f $(OBJ)

fclean: clean
		@rm -f $(NAME)

re:		fclean all
