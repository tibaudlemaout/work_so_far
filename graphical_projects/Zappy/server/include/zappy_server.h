/*
** EPITECH PROJECT, 2024
** Appzy
** File description:
** server arguments
*/

/**
 * @file zappy_server.h
 * @brief Header file containing all function prototypes for the server
*/

#ifndef ZAPPY_SERVER_H_
    #define ZAPPY_SERVER_H_
    #include <unistd.h>
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <arpa/inet.h>
    #include <sys/socket.h>
    #include <time.h>
    #include <netinet/in.h>
    #include <sys/select.h>
    #include <signal.h>
    #include <stdbool.h>
    #include <sys/types.h>
    #include <ctype.h>
    #include "struct_server.h"
    #include "player.h"
    #include "commands.h"
    #include "client.h"
    #include "commands.h"
    #define MAX_CLIENTS 100
    #define READY_FIRST_COMMAND -1
    #define ERROR_FIRST_COMMAND -2
    #define GEN_TICK 20
    #define FOOD_TICK 126

//signal handling for closing the porgram, causes error message
void signal_handler(int sig);

//argument handling functions
int get_port(const int argc, const char **argv);
int get_freq(const int argc, const char **argv);
int get_width(const int argc, const char **argv);
int get_height(const int argc, const char **argv);
int get_nb_cli(const int argc, const char **argv);

//server tools
void reset_buffer(char *buffer, int len);
sockaddr_in_t generate_addr(const int port);
void reset_set(fd_set *set, zappy_server_t *server, linked_client_t *head);

//init functions for all aspect of the program
void init_job(const int argc, const char **argv, info_t *info);
void init_server(const int argc, const char **argv, zappy_server_t *server);
void init_client(client_t *client, int clifd, sockaddr_in_t addr_cli);
void init_players(int nb_cli, info_t *info);
void init_map(info_t *data);
void init_inventory(inventory_t *inv);
void init_teams(const int argc, const char **argv, info_t *data);
void init_command(player_t *player, char **args, command_t *command, int i);

//map ressource generation
void gen_res(info_t *info);
void gen_res_tick(info_t *info);
void update_tile_inv(int x, int y, inventory_t inv, info_t *info);

//client connection handling
void manage_client_connect(fd_set *readset, zappy_server_t *net);
void manage_readvalue(char *buffer, client_t *client, info_t *info);
void manage_client_msg(fd_set *readset, zappy_server_t *net, info_t *info);

//linked list handling, for both client and player
void append_client_node(linked_client_t **list, client_t client);
void print_linked(linked_client_t *list);
void skip_client_node_by_fd(linked_client_t **list, int destroy_fd);
void remove_client_node_by_fd(linked_client_t **list, int destroy_fd);
void append_player_node(linked_player_t **list, player_t player);
void remove_player_node_by_id(linked_player_t **list, int destroy_id);
void print_linked_player(linked_player_t *list);

//main loops
void start_server(zappy_server_t *server);
void main_loop(info_t *info, zappy_server_t *server);
bool end_cond(info_t *info);

//assignation of player to their respective teams
void assign_player_by_team(char *team_name, client_t *client,
    info_t *info);
void assign_player(char **args, client_t *client, info_t *info);
void execute_buffer(int readval, char *read_buff, client_t *client,
    info_t *info);

//player handling
void create_player(player_t *player, char *team_name, info_t *info);
void create_egg(player_t *player, char *team_name,
    info_t *info, position_t coord);
void eat(player_t *player, info_t *info);
void player_death(player_t *player, char **args, info_t *info);

// command handling
void use_command(char **args, client_t *client);
void player_command_connection(char **args, client_t *client);
void gui_command_connection(char **args, client_t *client);
void exec_command(info_t *info);

//command steps
int get_ressource(char *arg);
int get_nb_ressource(inventory_t inv, ressource_t ressource);
bool has_x_ressource(inventory_t inv, ressource_t ressource, int x);
void give_nressources(inventory_t *inv, ressource_t ressource, int n);
void take_nressources(inventory_t *inv, ressource_t ressource, int n);
void print_inventory(inventory_t inventory);
void send_new_invs(player_t player, inventory_t inv, info_t *info);
void fix_coord(int *n, int *goal, int lim);
void append_each(player_t *player, info_t *info, int x, int y);
void add_coma_u(player_t *player, look_coords_t coords,
    int i, int n);
void add_coma_d(player_t *player, look_coords_t coords,
    int i, int n);
void add_coma_l(player_t *player, look_coords_t coords,
    int i, int n);
void add_coma_r(player_t *player, look_coords_t coords,
    int i, int n);
bool check_incantation(player_t *player, info_t *info);
void remove_incantation_res(int pl_lvl, inventory_t *inv, info_t *info);

//command queue handling
void dequeue_command(player_t *player);
void enqueue_command(player_t *player, char **args, command_t *command);
void enqueue_command_front(player_t *player, char **args, command_t *command);

//write functions
void write_buffer(zappy_server_t *server, fd_set *writefds);

//free functions
void free_player(player_t *player);
void destroy_players(linked_player_t *list);
void destroy_clients(linked_client_t *list);
void free_client(client_t *client);
void destroy_everything(info_t *info, zappy_server_t *server);
void free_array(char ***largs);

//error display
void handle_errors(const int argc, const char **argv);
void show_error(const char *error);

//utility functions
void append_to_gui(info_t *info, char *str);
int get_nb_unused(linked_player_t *head, char *team_name);
bool is_valid_team(char *name, info_t *info);
void append_to_string(char *dest, char *src);
bool verify_empty(char *cmd);
void create_args_list(char ***args, char *command);
size_t count_args(char **args);
void set_time(player_t *player);
int get_nb_players(info_t *info, position_t coords);

#endif /* !ZAPPY_SERVER_H_ */
