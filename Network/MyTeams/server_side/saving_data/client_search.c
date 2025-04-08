/*
** EPITECH PROJECT, 2024
** B-NWP-400-NAN-4-1-myteams-thomas.cluseau
** File description:
** client_search
*/
#include "../../include/server.h"
#include "../../include/utils.h"
#include "../../libs/myteams/logging_server.h"

static void setup_search_user_cont(client_serv_t client[MAX_CLIENT],
    char **parse, bool check, int id)
{
    if (!strcmp(parse[0], "uuid")) {
        parse[1][strlen(parse[1]) - 1] = '\0';
        !strcmp(parse[1], client[id].command[1]) ? check = true : 0;
    }
}

static void setup_search_user(client_serv_t client[MAX_CLIENT], int id,
    char *name)
{
    FILE *file = fopen(USER_FILE, "r+");
    char line[2024];
    char **parse = {NULL};
    bool check = false;

    for (int len = 0; fgets(line, sizeof(line), file);) {
        parse = split_str_client(line, parse, &len);
        if (check == true) {
            parse[1][strlen(parse[1]) - 1] = '\0';
            dprintf(client[id].sockfd, "user;%s;%s;%s",
            client[id].command[1], name, parse[1]);
            free_array(parse, len);
            fclose(file);
            return;
        }
        for (int j = 0; j != len; j++) {
            setup_search_user_cont(client, parse, check, id);
        }
    }
}

void search_user(client_serv_t client[MAX_CLIENT], int id)
{
    FILE *file = fopen(USER_FILE, "r+");
    char line[5024];
    char **parse = {NULL};
    char *name = NULL;
    int len = 0;
    for (int count = 0; fgets(line, sizeof(line), file);) {
        count++;
        if (count == 2) {
            parse = split_str_client(line, parse, &len);
            for (int j = 0; j != len; j++) {
                if (!strcmp(delete_back(parse[j]), client[id].command[1])
                && strlen(client[id].command[1]) == 36) {
                    name = strdup(parse[j-1]);
                    free_array(parse, len);
                }
            }
        }
    }
    fclose(file);
    name != NULL ? setup_search_user(client, id, name) :
    dprintf(client[id].sockfd, "error;user;%s", client[id].command[1]);
}
