##
## EPITECH PROJECT, 2024
## Semester_3
## File description:
## Makefile
##

NAME = wolfram

PATHNAME = $(shell stack path --local-install-root)

all :
	stack build
	cp $(PATHNAME)/bin/$(NAME)-exe ./$(NAME)

clean :
	stack clean

fclean : clean
	rm -f $(NAME)

re : fclean all

test_run :
	stack test
