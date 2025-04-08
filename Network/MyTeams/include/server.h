/*
** EPITECH PROJECT, 2024
** B-NWP-400-NAN-4-1-myteams-thomas.cluseau
** File description:
** server
*/

#ifndef SERVER_H_
    #define SERVER_H_
    #include <stdio.h>
    #include <sys/types.h>
    #include <sys/socket.h>
    #include <netinet/in.h>
    #include <arpa/inet.h>
    #include <stdlib.h>
    #include <unistd.h>
    #include <netdb.h>
    #include <string.h>
    #include <stdbool.h>
    #include <signal.h>
    #include <errno.h>
    #include <time.h>
    #include "struct.h"
    #define MAX_CLIENT 10
    #define USER_FILE "./save_file/save_user.txt"
    #define TEAM_FILE "./save_file/save_team.txt"
    #define CHANNEL_FILE "./save_file/save_channel.txt"
    #define MAX_NAME_LENGTH 32
    #define MAX_DESCRIPTION_LENGTH 255
    #define MAX_COMMAND_LENGTH 512

static volatile sig_atomic_t run = 1;

typedef void (*command)(client_serv_t client[MAX_CLIENT], int, int);

static const void c_message(int socket, char *str)
{
    dprintf(socket, "%s\r\n", str);
}

serv_t *init_server(int sockfd, int max_sd, fd_set fds, serv_t *serv);
void close_server(client_serv_t client[MAX_CLIENT], serv_t *serv);
int start_server(int);
int loop_server(client_serv_t client_str[MAX_CLIENT], serv_t *serv);
void close_status_client(void);
void share_close_client(client_serv_t client[MAX_CLIENT], int id);

void init_struct_client(client_serv_t client[MAX_CLIENT], int id);
int init_client(client_serv_t s_client[MAX_CLIENT], serv_t *serv);
void fill_client(client_serv_t s_client[MAX_CLIENT], serv_t *serv);
void start_client(client_serv_t client[MAX_CLIENT], int id);
int check_client(client_serv_t client[MAX_CLIENT], int id);
void clean_client(client_serv_t client[MAX_CLIENT], int id);
void login_client(client_serv_t client[MAX_CLIENT], int id, int len);
void status_client(client_serv_t client[MAX_CLIENT], int id, int status);
void send_commands_users(client_serv_t client[MAX_CLIENT], int id);
void load_user_infile(void);
bool check_team_exists(client_serv_t client[MAX_CLIENT], int id);

void help_command(client_serv_t client[MAX_CLIENT], int id);
void handling_command_client(client_serv_t client[MAX_CLIENT], int id,
    int len);

void is_save_file(void);
void init_client_infile(client_serv_t *client, int id);
void append_infile(char *path, int nb_line, const char *str);
bool check_occurence(char *path, int nb_line, char *);

void is_users(client_serv_t client[MAX_CLIENT], int id,
    int len);
void is_user(client_serv_t client[MAX_CLIENT], int id,
    int len);
void is_send(client_serv_t client[MAX_CLIENT], int id,
    int len);
void send_message_user(client_serv_t client[MAX_CLIENT], int id);
void is_messages(client_serv_t client[MAX_CLIENT], int id,
    int len);
void display_message_user(client_serv_t client[MAX_CLIENT], int id);
void add_client_inteam(client_serv_t client[MAX_CLIENT], int id);

char *delete_back(char *uuid);
void search_user(client_serv_t client[MAX_CLIENT], int id);
bool is_user_exist(client_serv_t client[MAX_CLIENT], int id);
void is_create(client_serv_t client[MAX_CLIENT], int id,
    int len);
void is_sub(client_serv_t client[MAX_CLIENT], int id,
    int len);
void is_unsub(client_serv_t client[MAX_CLIENT], int id,
    int len);
void is_subed(client_serv_t client[MAX_CLIENT], int id,
    int len);
void is_use(client_serv_t client[MAX_CLIENT], int id,
    int len);
void is_info(client_serv_t client[MAX_CLIENT], int id,
    int len);
void is_list(client_serv_t client[MAX_CLIENT], int id,
    int len);
void create_channel(client_serv_t client[MAX_CLIENT], int id,
    int len);

#endif /* !SERVER_H_ */
