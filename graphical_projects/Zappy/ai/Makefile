##
## EPITECH PROJECT, 2024
## Appzy
## File description:
## AI Makefile
##

NAME = zappy_ai

SRC = Main.cpp \
	ParsingArgs.cpp \
	Encryption.cpp \
	AiCommand.cpp \
	AiPlayer.cpp \
	AiPriorities.cpp \
	AiLooked.cpp \

OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	g++ -o $@ $^
	rm -f $(OBJ)
	@printf "[\033[0;31mdeleted\033[0m] % 30s\n" $(OBJ) | tr ' ' '.'
	@printf "[\033[0;36mbuilt\033[0m] % 32s\n" $(NAME) | tr ' ' '.'

clean:
	rm -f $(OBJ)
	@printf "[\033[0;31mdeleted\033[0m] % 30s\n" $(OBJ) | tr ' ' '.'

fclean: clean
	rm -f ../$(NAME)
	@printf "[\033[0;31mdeleted\033[0m] % 30s\n" $(NAME) | tr ' ' '.'

re: fclean all

.PHONY: all clean fclean re
