/*
** EPITECH PROJECT, 2024
** B-NWP-400-NAN-4-1-myteams-thomas.cluseau
** File description:
** add_to_save
*/
#include "../../include/server.h"
#include "../../include/utils.h"
#include "../../libs/myteams/logging_server.h"

void append_infile(char *path, int nb_line, const char *str)
{
    FILE *file = fopen(path, "r");
    FILE *f_temp = fopen("replace.txt", "w");
    char buffer[5024];
    int count = 0;

    while ((fgets(buffer, 5024, file)) != NULL) {
        count++;
        if (count == nb_line && strcmp(buffer, "\n") != 0) {
            buffer[strlen(buffer)-1] = 0;
            fprintf(f_temp, "%s;%s\n", buffer, str);
        } else if (count == nb_line && !strcmp(buffer, "\n")) {
            buffer[strlen(buffer)-1] = 0;
            fprintf(f_temp, "%s\n", str);
        } else
            fputs(buffer, f_temp);
    }
    fclose(file);
    fclose(f_temp);
    remove(path);
    rename("replace.txt", path);
}

bool check_occurence(char *path, int nb_line, char *occ)
{
    FILE *file = fopen(USER_FILE, "r+");
    char line[2024];
    char **user = NULL;
    int count = 0;
    int len = 0;

    for (int i = 0; fgets(line, sizeof(line), file);) {
        i++;
        if (i == nb_line) {
            user = split_str_client(line, user, &len);
            for (int i = 0; i != len; i++) {
                if (!strcmp(user[i], occ)) {
                    fclose(file);
                    free_array(user, len);
                    return true;
                }
            }
        }
    }
    fclose(file);
    return false;
}
