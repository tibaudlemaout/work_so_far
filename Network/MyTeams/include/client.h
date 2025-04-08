/*
** EPITECH PROJECT, 2024
** B-NWP-400-NAN-4-1-myteams-thomas.cluseau
** File description:
** client
*/

#ifndef CLIENT_H_
    #define CLIENT_H_
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
    #include "struct.h"

static volatile sig_atomic_t run = 1;

typedef void (*command)(char *message, char **command, client_t *client,
    int len);

int start_client(char *ip, int port);
client_t *init_client(client_t *client);
void loop_client(int sockfd, client_t *client);
void send_client(client_t *client, char *message);
void logout_client(client_t *client, char *message);

void command_management(char *message, client_t *client);

void is_user(char *message, char **command, client_t *client, int);
void is_users(char *message, char **command, client_t *client, int);
void is_log(char *message, char **command, client_t *client, int);
void is_close(char *message, char **command, client_t *client, int);
void is_error(char *message, char **command, client_t *client, int);
void is_message_private(char *message, char **command, client_t *client,
    int len);
void is_display_message(char *message, char **command, client_t *client,
    int len);
void is_create_team(char *message, char **command, client_t *client,
    int len);
void is_create_channel(char *message, char **command, client_t *client,
    int len);
void is_subscribe(char *message, char **command, client_t *client,
    int len);
void is_unsubscribe(char *message, char **command, client_t *client,
    int len);
void is_subed(char *message, char **command, client_t *client,
    int len);
void is_list(char *message, char **command, client_t *client,
    int len);

#endif /* !CLIENT_H_ */
