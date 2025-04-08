/*
** EPITECH PROJECT, 2024
** B-NWP-400-NAN-4-1-myteams-thomas.cluseau
** File description:
** create_save
*/
#include "../../include/server.h"
#include "../../include/utils.h"
#include "../../libs/myteams/logging_server.h"
#include <sys/types.h>
#include <sys/stat.h>

static void setup_save_channel_file(void)
{
    FILE *file;
    bool check = false;
    char pass[256];

    file = fopen("./save_file/save_channel.txt", "r");
    if (file != NULL) {
        check = true;
        fscanf(file, "%[^\n]", pass);
        if (strcmp("Here are the channels", pass) != 0)
            check = false;
    }
    if (check == false) {
        file = fopen("./save_file/save_channel.txt", "w+");
        fprintf(file, "Here are the channels\n\n\n");
    }
    fclose(file);
}

static void setup_save_file(void)
{
    FILE *file;
    bool check = false;
    char pass[256];

    file = fopen("./save_file/save_user.txt", "r");
    if (file != NULL) {
        check = true;
        fscanf(file, "%[^\n]", pass);
        if (strcmp("Here are the users", pass) != 0)
            check = false;
    }
    if (check == false) {
        file = fopen("./save_file/save_user.txt", "w+");
        fprintf(file, "Here are the users\n\n\n");
    }
    fclose(file);
    setup_save_channel_file();
}

void is_save_file(void)
{
    FILE *file;
    bool check = false;
    char pass[256];
    struct stat st = {0};

    if (stat("./save_file", &st) == -1)
        mkdir("./save_file", 0777);
    file = fopen("./save_file/save_team.txt", "r");
    if (file != NULL) {
        check = true;
        fscanf(file, "%[^\n]", pass);
        if (strcmp("Here is teams", pass) != 0)
            check = false;
    }
    if (check == false) {
        file = fopen("./save_file/save_team.txt", "w+");
        fprintf(file, "Here is teams\n\n\n");
    }
    fclose(file);
    setup_save_file();
}

void init_client_infile(client_serv_t *client, int id)
{
    FILE *file = fopen(USER_FILE, "a");

    fprintf(file,
    "name;%s\nuuid;%s\nstatus;1\nteam\nmessage\nchannel\n\n",
    client[id].user_name, client[id].uuid);
    fclose(file);
}

static void load_user_infile_cont(int len, char **parse)
{
    for (int j = 0; j < (len - 1); j = j + 2)
        server_event_user_loaded(delete_back(parse[j + 1]), parse[j]);
}

void load_user_infile(void)
{
    FILE *file = fopen(USER_FILE, "r");
    char line[2024];
    char **parse = {NULL};
    int count = -1;
    int len = 0;

    for (int i = 0; fgets(line, sizeof(line), file);) {
        i++;
        parse = split_str_client(line, parse, &len);
        if (i == 2 && len > 1) {
            load_user_infile_cont(len, parse);
            free_array(parse, len);
            fclose(file);
            return;
        }
        free_array(parse, len);
    }
    fclose(file);
}
