/*
** EPITECH PROJECT, 2024
** B-NWP-400-NAN-4-1-myteams-thomas.cluseau
** File description:
** struct
*/

#ifndef STRUCT_H_
    #define STRUCT_H_
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

    typedef struct serv {
        int sockfd;
        fd_set fds;
        int max_sd;
        fd_set readfds;
    } serv_t;

    typedef struct client {
        bool login;
        int sokfd;
        char *uuid;
        char *user_name;
    } client_t;

    typedef struct client_serv {
    int sockfd;
    char **command;
    char *message;
    char *concat;
    char *user_name;
    char *uuid;
    char *uuid_team;
    char *uuid_channel;
    ssize_t ip;
    bool login;
    int use;
    int len_addr;
    struct sockaddr_in address;
    } client_serv_t;

    typedef struct list {
    char *str;
    struct list *next;
    } list_t;

#endif /* !STRUCT_H_ */
