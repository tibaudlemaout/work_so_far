/*
** EPITECH PROJECT, 2024
** B-NWP-400-NAN-4-1-myteams-thomas.cluseau
** File description:
** users
*/
#include "../../include/server.h"
#include "../../include/utils.h"
#include "../../libs/myteams/logging_server.h"

void is_users(client_serv_t client[MAX_CLIENT], int id,
int len)
{
    if (len != 1)
        dprintf(client[id].sockfd, "enter a valid command");
    else
        send_commands_users(client, id);
}

void is_user(client_serv_t client[MAX_CLIENT], int id,
int len)
{
    if (len != 2)
        dprintf(client[id].sockfd, "enter a valid command");
    else
        search_user(client, id);
}

void is_send(client_serv_t client[MAX_CLIENT], int id,
int len)
{
    if (len != 3)
        dprintf(client[id].sockfd, "enter a valid command");
    else
        send_message_user(client, id);
}

void is_messages(client_serv_t client[MAX_CLIENT], int id,
int len)
{
    if (len != 2)
        dprintf(client[id].sockfd, "enter a valid command");
    else
        display_message_user(client, id);
}
