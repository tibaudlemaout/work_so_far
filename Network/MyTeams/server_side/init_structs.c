/*
** EPITECH PROJECT, 2024
** B-NWP-400-NAN-4-1-myteams-thomas.cluseau
** File description:
** init_structs
*/
#include "../include/server.h"

void init_struct_client(client_serv_t client[MAX_CLIENT], int id)
{
    client[id].login = false;
    client[id].uuid = NULL;
    client[id].message = NULL;
    client[id].use = 0;
}

serv_t *init_server(int sockfd, int max_sd, fd_set fds, serv_t *serv)
{
    serv = malloc(sizeof(serv_t));
    serv->fds = fds;
    serv->max_sd = max_sd;
    serv->sockfd = sockfd;

    return serv;
}

void close_server(client_serv_t client[MAX_CLIENT], serv_t *serv)
{
    for (int i = 0; i < MAX_CLIENT; i++) {
        if (FD_ISSET(client[i].sockfd, &serv->readfds))
            clean_client(client, i);
    }
    close(serv->sockfd);
    close_status_client();
}
