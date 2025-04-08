##
## PERSONAL PROJECT, 2024
## Linux_Graphic_Interface
## File description:
## Makefile
##
NAME = weather_app
SFML = -lsfml-graphics -lsfml-system -lsfml-audio -lsfml-window 

SRC =	Main.cpp	\
		ConstDestr.cpp	\
		MeanDevMedian.cpp	\
		Loop.cpp	\
		TempCalc.cpp	\
		WeirdValues.cpp \
		Switch.cpp \
		App.cpp

OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	g++ -o $@ $^ $(SFML) -lm -lX11
	rm -f $(OBJ)
	@printf "[\033[0;31mdeleted\033[0m] % 30s\n" $(OBJ) | tr ' ' '.'
	@printf "[\033[0;36mbuilt\033[0m] % 32s\n" $(NAME) | tr ' ' '.'

clean:
	rm -f $(OBJ)
	@printf "[\033[0;31mdeleted\033[0m] % 30s\n" $(OBJ) | tr ' ' '.'

fclean: clean
	rm -f $(NAME)
	@printf "[\033[0;31mdeleted\033[0m] % 30s\n" $(NAME) | tr ' ' '.'

re: fclean all
