/*
** EPITECH PROJECT, 2024
** B-NWP-400-NAN-4-1-myteams-thomas.cluseau
** File description:
** command_channel
*/
#include "../../include/client.h"
#include "../../include/utils.h"
#include "../../libs/myteams/logging_client.h"

void is_create_channel(char *message, char **command, client_t *client,
int len)
{
    client_event_channel_created(command[1], command[2], command[3]);
}
