##
## EPITECH PROJECT, 2024
## Appzy
## File description:
## Makefile
##

NAME = zappy_gui

SFML = -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

SRC = Main.cpp \
	Commands.cpp \
	Client.cpp \
	EventHandler.cpp \
	Player.cpp \
	Resource.cpp \
	Tile.cpp \
	Scene.cpp \
	Client.cpp

OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	g++ -o $@ $^ $(SFML)
	rm -f $(OBJ)
	@printf "[\033[0;31mdeleted\033[0m] % 30s\n" $(OBJ) | tr ' ' '.'
	@printf "[\033[0;36mbuilt\033[0m] % 32s\n" $(NAME) | tr ' ' '.'

%.o: %.cpp
	g++ -c $< -o $@ $(INCLUDES)

clean:
	rm -f $(OBJ)
	@printf "[\033[0;31mdeleted\033[0m] % 30s\n" $(OBJ) | tr ' ' '.'

fclean: clean
	rm -f ../$(NAME)
	@printf "[\033[0;31mdeleted\033[0m] % 30s\n" $(NAME) | tr ' ' '.'

re: fclean all

.PHONY: all clean fclean re
