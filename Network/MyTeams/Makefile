##
## EPITECH PROJECT, 2024
## Semester_3
## File description:
## Makefile
##

SRCSERVER =	server_side/server_start.c	\
			server_side/server_loop.c	\
			server_side/init_structs.c	\
			server_side/client_handling/client.c	\
			server_side/client_handling/stop_client.c	\
			server_side/commands/create_channel.c	\
			server_side/commands/create_client.c	\
			server_side/commands/create_teams.c	\
			server_side/commands/disp_message.c	\
			server_side/commands/get_info.c	\
			server_side/commands/lists.c	\
			server_side/commands/login_management.c	\
			server_side/commands/send_message.c	\
			server_side/commands/subscribe.c	\
			server_side/commands/subscribers.c	\
			server_side/commands/unsubscribe.c	\
			server_side/commands/use.c 	\
			server_side/commands/users.c	\
			server_side/saving_data/add_to_save.c	\
			server_side/saving_data/client_save.c	\
			server_side/saving_data/client_search.c	\
			server_side/saving_data/create_save.c	\
			utils/checker.c	\
			utils/get_next_line.c	\
			utils/my_calloc.c	\
			utils/split_str_client.c	\
			utils/split_str_quot.c

SRCCLIENT = client_side/client_start.c	\
			client_side/client_loop.c	\
			client_side/client_event.c	\
			client_side/send_commands.c	\
			client_side/commands/command_user.c	\
			client_side/commands/command_handling.c	\
			client_side/commands/command_list.c	\
			client_side/commands/command_channel.c	\
			utils/checker.c	\
			utils/get_next_line.c	\
			utils/my_calloc.c	\
			utils/split_str_client.c	\
			utils/split_str_quot.c

OBJ =	$(SRCSERVER:.c=.o)	\
		$(SRCCLIENT:.c=.o)

TEST = 	tests/test.c

NAME =	myteams_server

NAME2 = myteams_cli

CSFML = -lcsfml-graphics -lcsfml-system -lcsfml-audio

CRITERION = --coverage -lcriterion

LDFLAGS	+=	-L ./libs/myteams/ -lmyteams -luuid

INCLUDE = -I ./include/ -I ./libs/myteams/

LIBPATH = $(shell export LD_LIBRARY_PATH=./libs/myteams:$LD_LIBRARY_PATH)

all:	$(NAME)

$(NAME): $(OBJ)
		echo $(LIBPATH)
		gcc -o $(NAME) $(SRCSERVER) $(LDFLAGS) $(INCLUDE)
		gcc -o $(NAME2) $(SRCCLIENT) $(LDFLAGS) $(INCLUDE)

test_run:
		gcc -o unit_test $(SRC) $(TEST) $(CRITERION) -I ./include/
		./unit_test

clean:
		rm -f $(OBJ)

fclean: clean
		rm -f $(NAME)
		rm -f $(NAME2)

re:		fclean all
