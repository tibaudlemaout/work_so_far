/*
** EPITECH PROJECT, 2023
** B-MUL-200-NAN-2-1-myrpg-tibaud.le-maout
** File description:
** dungeon1_npc
*/
#include "../../include/my.h"

void init_dungeon1_npc_images(struct_t *data, int i)
{
    sfIntRect rect = {47, 0, 47, 48};
    char *str = my_strcat("asset/npc/", D1.npc[i].name);
    char *Profile = my_strcat(str, "PP.png");
    char *Down = my_strcat(str, "Down.png");
    sfVector2f pos[2] = {{600, 852}, {1704, 185}};
    sfTexture *profile_texture = sfTexture_createFromFile(Profile, NULL);

    D1.npc[i].sprite = sfSprite_create();
    D1.npc[i].profile.sprite = sfSprite_create();
    D1.npc[i].profile.texture = sfTexture_createFromFile(Profile, NULL);
    D1.npc[i].TextureDown = sfTexture_createFromFile(Down, NULL);
    sfSprite_setTexture(D1.npc[i].sprite, D1.npc[i].TextureDown, sfTrue);
    sfSprite_setTexture(D1.npc[i].profile.sprite, profile_texture, sfTrue);
    sfSprite_setPosition(D1.npc[i].sprite, pos[i]);
    sfSprite_setScale(D1.npc[i].sprite, (sfVector2f) {0.5, 0.5});
    sfSprite_setScale(D1.npc[i].profile.sprite, (sfVector2f) {0.45, 0.45});
    sfSprite_setTextureRect(D1.npc[i].sprite, rect);
    return;
}

void init_dungeon_1_npc_sprites(struct_t *data)
{
    int tab[16] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    sfVector2f positions[2] = {{600, 864}, {1704, 192}};

    D1.quest = malloc(sizeof(int) * 16);
    D1.rect_pos = malloc(sizeof(int) * 2);
    D1.npc = malloc(sizeof(mobs_t) * 2);
    for (int i = 0; i < 16; i++)
        D1.quest[i] = tab[i];
    for (int i = 0; i < 2; i++)
        D1.rect_pos[i] = positions[i];
    D1.npc[0].name = "Guard";
    D1.npc[1].name = "Blobbob";
    for (int i = 0; i < 2; i++)
        init_dungeon1_npc_images(data, i);
}

void link_dungeon1_str_to_txt(struct_t *data, int i)
{
    D1.texts[i].txt = sfText_create();
    D1.texts[i].font = sfFont_createFromFile("asset/BreatheFire.otf");
    sfText_setFont(D1.texts[i].txt, D1.texts[i].font);
    sfText_setFillColor(D1.texts[i].txt, sfBlack);
    sfText_setCharacterSize(D1.texts[i].txt, 11);
    sfText_setString(D1.texts[i].txt, D1.texts[i].str);
}

void init_dungeon1_npc_txt(struct_t *data, char *buffer)
{
    char *str;
    int idx = 0;

    D1.texts = malloc(sizeof(text_t) * 16);
    for (int a = 0; a < 16; a++) {
        idx = idx_move(buffer, idx, '\n');
        D1.texts[a].str = malloc(sizeof(char) * 100);
        idx--;
        for (int i = 0; buffer[idx] != '\n'; idx++) {
            D1.texts[a].str[i] = buffer[idx];
            i++;
            D1.texts[a].str[i] = '\0';
        }
        link_dungeon1_str_to_txt(data, a);
        idx = idx_move(buffer, idx, '\n');
    }
}

void init_dungeon_1_npc(struct_t *data)
{
    FILE *fp;
    struct stat sb;
    stat("script/1_dungeon_dialogue.txt", &sb);
    char *buffer = malloc(sizeof(char) * sb.st_size);

    fp = fopen("script/1_dungeon_dialogue.txt", "r");
    fread(buffer, sizeof(char), sb.st_size, fp);
    init_dungeon_1_npc_sprites(data);
    init_dungeon1_npc_txt(data, buffer);
    free(buffer);
    fclose(fp);
}
