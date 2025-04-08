/*
** EPITECH PROJECT, 2024
** B-NWP-400-NAN-4-1-myteams-thomas.cluseau
** File description:
** stop_client
*/
#include "../../include/server.h"
#include "../../include/utils.h"
#include "../../libs/myteams/logging_server.h"
#include <errno.h>

void clean_client(client_serv_t client[MAX_CLIENT], int id)
{
    client[id].message = NULL;
    dprintf(client[id].sockfd, "end_client");
    close(client[id].sockfd);
    client[id].sockfd = 0;
    memset(&client[id].address, 0, sizeof client[id].address);
    client[id].login = false;
    client[id].uuid = NULL;
    client[id].user_name = NULL;
}

void share_close_client(client_serv_t client[MAX_CLIENT], int id)
{
    for (int i = 0; i != MAX_CLIENT; i++) {
        if (i != id) {
            if (client[i].login == true)
                dprintf(client[i].sockfd, "close;%s;%s", client[id].user_name,
                client[id].uuid);
        }
    }
}
