/*
** EPITECH PROJECT, 2024
** Semester_3
** File description:
** myftp
*/

#ifndef MYFTP_H_
    #define MYFTP_H_
#include "struct.h"
#include <stdio.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/select.h>
#include <unistd.h>
#include <string.h>

void handle_client(Server_t *server, Client_t *client);
void handle_client_or_data(Server_t *server, Client_t *clients, int idx);
void process_ftp_command(int clientSocket, const char* command,
    struct sockaddr_in* serverAddress);
void accept_client(Server_t *server, Client_t *clients);

#endif /* !MYFTP_H_ */
