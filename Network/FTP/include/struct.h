/*
** EPITECH PROJECT, 2024
** Semester_3
** File description:
** struct
*/

#ifndef STRUCT_H_
    #define STRUCT_H_
#include <arpa/inet.h>
#include <sys/socket.h>

    typedef struct Client {
        int socket;
        int dataSocket;
    } Client_t;

    typedef struct Server {
        struct sockaddr_in address;
        int socket;
        fd_set masterfds;
        int maxfd;
        char anonymousPath[10];
    } Server_t;

#endif /* !STRUCT_H_ */
