/*
** EPITECH PROJECT, 2024
** B-NWP-400-NAN-4-1-myteams-thomas.cluseau
** File description:
** send_commands
*/
#include "../include/client.h"
#include "../libs/myteams/logging_client.h"
#include "../include/utils.h"

void logout_client(client_t *client, char *message)
{
    if (!strcmp(message, "/logout")) {
        if (client->login != false)
            client_event_logged_out(client->uuid, client->user_name);
        close(client->sokfd);
        free(client);
        exit(0);
    }
}

void send_client(client_t *client, char *message)
{
    int len = 0;
    char **command = split_str_quot(message, command, &len);

    logout_client(client, message);
    if (!strcmp(message, ""))
        return;
    if ((client->login == false && strcmp(message, "/help") != 0) &&
        (client->login == false && strcmp(command[0], "/login") != 0)
        || !strcmp(message, "/login"))
        client_error_unauthorized();
    else if (!strcmp(command[0], "/login") && client->login == true) {
        client_error_already_exist();
        return;
    }
    if (!strcmp(message, "/help") && client->login == false)
        printf("\t/help display help\n\
        /login [username] log with user\n\t/logout disconnect\n");
    else
        dprintf(client->sokfd, "%s\r\n", message);
    free_array(command, len);
}
