/*
** EPITECH PROJECT, 2023
** B-MUL-200-NAN-2-1-myrpg-tibaud.le-maout
** File description:
** mobs
*/
#include "../../include/my.h"

void init_mob_stats(mobs_t *mob, char *buffer, int idx)
{
    idx = idx_move(buffer, idx, '\n');
    mob->hp = my_parsing_get_nbr(idx - 1, buffer);
    idx = idx_move(buffer, idx, '\n');
    mob->ads = malloc(sizeof(int) * 3);
    for (int i = 0; i < 3; i++) {
        mob->ads[i] = my_parsing_get_nbr(idx - 1, buffer);
        idx = idx_move(buffer, idx, '\n');
    }
    mob->factor = malloc(sizeof(int) * 3);
    for (int i = 0; i < 3; i++) {
        mob->factor[i] = my_parsing_get_nbr(idx - 1, buffer);
        idx = idx_move(buffer, idx, '\n');
    }
}

mobs_t init_mob(char *buffer, int idx, char *filepath, int move)
{
    mobs_t mob;
    int len = 0;

    for (int i = idx; buffer[i] != '/'; i++)
        len++;
    mob.name = malloc(sizeof(char) * len + 1);
    for (int i = 0; buffer[idx] != '/'; i++) {
        mob.name[i] = buffer[idx];
        idx++;
    }
    mob.name[len] = '\0';
    init_mob_stats(&mob, buffer, idx);
    mob.profile_filepath = malloc(sizeof(char) * (my_strlen(filepath) + 1));
    mob.profile_filepath = filepath;
    mob.profile.sprite = sfSprite_create();
    mob.profile.texture = sfTexture_createFromFile(filepath, NULL);
    sfSprite_setTexture(mob.profile.sprite, mob.profile.texture, sfTrue);
    if (move == 1)
        init_mob_move_sprite(&mob, mob.name);
    return (mob);
}

char *init_each_mob_area_1(struct_t *data, char *buffer)
{
    int idx = 0;

    data->mob = malloc(sizeof(mobs_t) * 7);
    data->mob[0] = init_mob(buffer, idx, "asset/mobs/Cockatrice.png", 0);
    idx = idx_move(buffer, idx, '#');
    data->mob[1] = init_mob(buffer, idx, "asset/mobs/Rat.png", 0);
    idx = idx_move(buffer, idx, '#');
    data->mob[2] = init_mob(buffer, idx, "asset/mobs/Snake.png", 0);
    idx = idx_move(buffer, idx, '#');
    data->mob[3] = init_mob(buffer, idx, "asset/mobs/Slime.png", 1);
    idx = idx_move(buffer, idx, '#');
    data->mob[4] = init_mob(buffer, idx, "asset/mobs/Bat.png", 1);
    idx = idx_move(buffer, idx, '#');
    data->mob[5] = init_mob(buffer, idx, "asset/mobs/Soldier.png", 0);
    idx = idx_move(buffer, idx, '#');
    data->mob[6] = init_mob(buffer, idx, "asset/npc/Blobbob.png", 0);
}

void init_mobs_area_1(struct_t *data)
{
    FILE *fp;
    struct stat sb;
    stat("script/1_mobs.txt", &sb);
    char *buffer = malloc(sizeof(char) * sb.st_size);

    fp = fopen("script/1_mobs.txt", "r");
    fread(buffer, sizeof(char), sb.st_size, fp);
    init_each_mob_area_1(data, buffer);
    free(buffer);
    fclose(fp);
}
