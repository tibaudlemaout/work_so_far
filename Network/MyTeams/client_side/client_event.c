/*
** EPITECH PROJECT, 2024
** B-NWP-400-NAN-4-1-myteams-thomas.cluseau
** File description:
** client_event
*/

#include "../include/client.h"
#include "../include/utils.h"
#include "../libs/myteams/logging_client.h"


void is_display_message(char *message, char **command, client_t *client,
    int len)
{
    char *ptr;

    client_private_message_print_messages(command[1],
    strtoul(command[3], &ptr, 10), command[2]);
}

void is_create_team(char *message, char **command, client_t *client,
    int len)
{
    client_event_team_created(command[1], command[2], command[3]);
}

void is_subscribe(char *message, char **command, client_t *client,
    int len)
{
    client_print_subscribed(command[1], command[2]);
}
void is_unsubscribe(char *message, char **command, client_t *client,
    int len)
{
    client_print_unsubscribed(command[1], command[2]);
}

void is_subed(char *message, char **command, client_t *client,
    int len)
{
    int status = 0;

    for (int i = 1; i != len;) {
        status = atoi(command[i + 2]);
        if (status > 1)
            status = 1;
        client_print_users(command[i + 1], command[i], status);
        i = i + 3;
    }
}
