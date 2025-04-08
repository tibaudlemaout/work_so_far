/*
** EPITECH PROJECT, 2024
** B-NWP-400-NAN-4-1-myteams-thomas.cluseau
** File description:
** command_list
*/

#include "../../include/client.h"
#include "../../include/utils.h"
#include "../../libs/myteams/logging_client.h"

void is_list(char *message, char **command, client_t *client,
int len)
{
    if (!strcmp(command[1], "team")) {
        for (int i = 2; i != len;) {
            client_print_team(command[i + 1], command[i], command[i + 2]);
            i = i + 3;
        }
    }
    return;
}
