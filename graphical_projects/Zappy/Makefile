##
## EPITECH PROJECT, 2024
## Appzy
## File description:
## Makefile
##

all: gui ai server

gui:
	cd gui && make
	mv gui/zappy_gui zappy_gui

ai:
	cd ai && make
	mv ai/zappy_ai zappy_ai

server:
	cd server && make
	mv server/zappy_server zappy_server

clean:
	cd gui && make clean
	cd ai && make clean
	cd server && make clean

fclean:
	cd gui && make fclean
	cd ai && make fclean
	cd server && make fclean
	rm -f zapyy_gui
	rm -f zapyy_ai
	rm -f zapyy_server

re: fclean all

doc:
	doxygen Config.doxyfile

TEST_FLAG = -lcriterion

TEST_NAME = unit_tests

TEST_SRC = ./tests/NoTest.cpp

TEST_OBJ = $(TEST_SRC:%.cpp=%.o)

TESTED_SRC =	ai/ParsingArgs.cpp \
				ai/Encryption.cpp

TESTED_OBJ = $(TESTED_SRC:%.cpp=%.o)

$(TEST_NAME): $(TEST_OBJ) $(TESTED_OBJ)
	$(CXX) -o $(TEST_NAME) $(CXXFLAGS) $(TEST_FLAG) $(TEST_OBJ) $(TESTED_OBJ)

tests_run: $(TEST_NAME)
	./$(TEST_NAME)

tests_clean:
	rm -f $(TEST_OBJ)

tests_fclean: tests_clean
	rm -f $(TEST_NAME)
	rm -f ./tests/*.gcda
	rm -f ./tests/*.gcno

tests_re: tests_fclean tests_run

.PHONY: all gui ai server clean fclean re tests_run tests_fclean tests_re
