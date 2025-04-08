##
## EPITECH PROJECT, 2024
## Appzy
## File description:
## Server Makefile
##

NAME = zappy_server

SRC = main.c \
	args_handling.c \
	ressource_creation.c	\
	main_loop.c	\
	init_server.c	\
	adress_socket_handling.c	\
	error_handling.c	\
	init_teams.c	\
	init_tools.c	\
	free.c	\
	utils.c	\
	player_nb.c	\
	player/create_player.c	\
	player/list_player.c	\
	player/free_player.c	\
	player/verif_team.c	\
	player/eat.c	\
	player/death.c	\
	update_map.c	\
	end_cond.c	\
	client/free_client.c	\
	client/client_connection.c	\
	client/assign_client_player_teams.c	\
	client/assign_gui.c	\
	client/buffer_handling.c	\
	client/list_client.c	\
	command/assign_command.c	\
	command/command_queue.c	\
	command/command_exec.c	\
	command/write_commands.c	\
	command/player/prepare_move.c	\
	command/player/no_preparation.c	\
	command/player/move.c	\
	command/player/drop.c	\
	command/player/inventory.c	\
	command/player/inventory_utils.c	\
	command/player/take.c	\
	command/player/resource.c	\
	command/player/look.c	\
	command/player/look_utils.c	\
	command/player/look_string_tools.c	\
	command/player/connect_nbr.c	\
	command/player/broadcast.c	\
	command/player/incantation.c	\
	command/player/incantation_results.c	\
	command/player/fork.c	\
	command/graphic/map_commands.c	\
	command/graphic/team_commands.c	\
	command/graphic/player_commands.c	\
	command/graphic/freq_commands.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	gcc -o $@ $^
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
