##
## EPITECH PROJECT, 2023
## B-SYN-200-NAN-2-1-calendar-tibaud.le-maout
## File description:
## Makefile
##

SRC =	src/main.c	\
		src/error_handling.c	\
		src/get_layers.c	\
		src/loop.c	\
		src/employee.c	\
		src/meeting.c	\
		src/info_employee.c	\
		src/employee_cmp.c	\
		src/sort_employee_forename.c	\
		src/sort_employee_name.c	\
		src/sort_employee_job.c	\
		src/sort_employee_zip.c	\
		src/sort_employee_id.c	\
		src/info_meeting.c	\
		src/get_emp_meeting.c	\
		src/meeting_cmp.c	\
		src/sort_meeting_id.c	\
		src/sort_meeting_date.c	\
		src/sort_meeting_zip.c	\
		src/invite.c	\
		src/exclude.c	\
		src/cancel.c	\
		src/fire.c	\
		requirement.c

OBJ =	$(SRC:.c=.o)

TEST = 	tests/test.c

NAME =	calendar

CSFML = -lcsfml-graphics -lcsfml-system -lcsfml-audio

CRITERION = --coverage -lcriterion

all:	$(NAME)

$(NAME): $(OBJ)
		gcc -o $(NAME) $(SRC) -I ./include/
		rm -f $(OBJ)

test_run:
		gcc -o unit_test $(SRC) $(TEST) $(CRITERION) -I ./include/
		./unit_test

clean:
		rm -f $(OBJ)

fclean: clean
		rm -f $(NAME)
		rm -f libmy.a
		rm -f unit_*

re:		fclean all
