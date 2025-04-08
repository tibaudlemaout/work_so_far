##
## EPITECH PROJECT, 2024
## Gomoku bootstrap
## File description:
## Makefile
##

# Compiler
CXX = g++

# Criterion library for testing
CRITERION_LIBS = -lcriterion


SRC	= 	src/Main.cpp	\
		src/BoardUtils.cpp	\
		src/CommandProcessor.cpp	\
		src/Evaluation.cpp	\
		src/WinLoseConditions.cpp

TEST_SRCS = 	tests/Main.cpp	\

OBJ	=	$(SRC:.cpp=.o)

# Test object files
TEST_OBJS = $(TEST_SRCS:.cpp=.o)

NAME	=	pbrain-gomoku-ai

TEST_EXEC = pbrain_tests

INCLUDES	= 	-I./
CPP			= 	g++
CPPFLAGS	=	-Wall -Wextra $(INCLUDES) -std=c++20

all: $(NAME)

$(NAME):	$(OBJ)
	@echo -e "\e[1;33m Building $(NAME)...\e[0m"
	$(CPP) -o $(NAME) $(OBJ) $(CPPFLAGS)
	@echo -e "\e[1;32m[SUCCESS] $(NAME) built\e[0m"

# Linking and compiling tests
tests: $(TEST_OBJS) $(OBJS)
	$(CXX) $(TEST_OBJS) $(OBJS) $(CRITERION_LIBS) -o $(TEST_EXEC)

# Run tests
tests_run: tests
	./$(TEST_EXEC)

clean:
	rm -f $(OBJ) $(TEST_OBJS) $(EXEC) $(TEST_EXEC)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY:   all re clean fclean
