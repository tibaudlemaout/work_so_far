/*
** EPITECH PROJECT, 2024
** B-NWP-400-NAN-4-1-myteams-thomas.cluseau
** File description:
** get_info
*/
#include "../../include/server.h"
#include "../../include/utils.h"
#include "../../libs/myteams/logging_server.h"

void is_info(client_serv_t client[MAX_CLIENT], int id,
    int len)
{
    if (len != 1) {
        dprintf(client[id].sockfd, "invalid command");
        return;
    }
    if (client[id].use == 0)
        send_commands_users(client, id);
}
