/*
** EPITECH PROJECT, 2023
** B-MUL-200-NAN-2-1-myrpg-tibaud.le-maout
** File description:
** items
*/
#include "../../include/my.h"

void set_item_texture(struct_t *data, int i, char *name)
{
    char *filepath = "asset/items/";

    filepath = my_strcat(filepath, name);
    filepath = my_strcat(filepath, ".png");
    data->item[i].sprite = sfSprite_create();
    data->item[i].texture = sfTexture_createFromFile(filepath, NULL);
    sfSprite_setTexture(data->item[i].sprite, data->item[i].texture, sfTrue);
    data->item[i].nb = i;
}

int init_items_name_n_sprite(struct_t *data, char *buffer, int idx, int i)
{
    char *name = malloc(sizeof(char) * 25);
    int b = 0;
    int len = my_parsing_strlen(buffer, idx);

    data->item[i].name = malloc(sizeof(char) * (len + 1));
    data->item[i].name[len] = '\0';
    for (int a = 0; buffer[idx] != '\n'; a++) {
        data->item[i].name[a] = buffer[idx];
        if (buffer[idx] != ' ') {
            name[b] = buffer[idx];
            b++;
        }
        idx++;
    }
    name[b] = '\0';
    set_item_texture(data, i, name);
    free(name);
    return idx;
}

void get_items_data(struct_t *data, char *buffer, int idx)
{
    for (int i = 0; buffer[idx]; i++) {
        idx = init_items_name_n_sprite(data, buffer, idx, i);
        data->item[i].hp = my_item_get_nbr(idx, buffer);
        idx = idx_move(buffer, idx, ' ') - 1;
        data->item[i].att = my_item_get_nbr(idx, buffer);
        idx = idx_move(buffer, idx, ' ') - 1;
        data->item[i].def = my_item_get_nbr(idx, buffer);
        idx = idx_move(buffer, idx, ' ') - 1;
        data->item[i].spd = my_item_get_nbr(idx, buffer);
        idx = idx_move(buffer, idx, ' ') - 1;
        data->item[i].equipement = my_item_get_nbr(idx, buffer);
        idx = idx_move(buffer, idx, ' ') - 1;
        data->item[i].type = my_item_get_nbr(idx, buffer);
        idx = idx_move(buffer, idx, '\n') - 1;
    }
}

void init_items_tab(struct_t *data)
{
    FILE *fp;
    struct stat sb;
    stat("script/obj.txt", &sb);
    char *buffer = malloc(sizeof(char) * sb.st_size);
    int idx = 0;

    data->item = malloc(sizeof(items_t) * 54);
    fp = fopen("script/obj.txt", "r");
    fread(buffer, sizeof(char), sb.st_size, fp);
    buffer[sb.st_size] = '\0';
    get_items_data(data, buffer, idx);
    fclose(fp);
}
