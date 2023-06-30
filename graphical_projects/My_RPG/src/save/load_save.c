/*
** EPITECH PROJECT, 2023
** B-MUL-200-NAN-2-1-myrpg-tibaud.le-maout
** File description:
** load_save
*/
#include "../../include/my.h"

save_t load_save(struct_t *data)
{
    FILE *fp;
    struct stat sb;
    stat("src/save/save_file.txt", &sb);
    data->save.buffer = malloc(sizeof(char) * sb.st_size);

    fp = fopen("src/save/save_file.txt", "r");
    fread(data->save.buffer, sizeof(char), sb.st_size, fp);
    fclose(fp);
}
