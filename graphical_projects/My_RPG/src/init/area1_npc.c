/*
** EPITECH PROJECT, 2023
** B-MUL-200-NAN-2-1-myrpg-tibaud.le-maout
** File description:
** area1_npc
*/
#include "../../include/my.h"

void init_area1_npc_images(struct_t *data, int i)
{
    sfIntRect rect = {47, 0, 47, 48};
    char *str = my_strcat("asset/npc/", Z1.npc[i].name);
    char *Profile = my_strcat(str, "PP.png");
    char *Left = my_strcat(str, "Left.png");
    sfVector2f pos[2] = {{312, 468}, {1656, 444}};
    sfTexture *profile_texture = sfTexture_createFromFile(Profile, NULL);

    Z1.npc[i].sprite = sfSprite_create();
    Z1.npc[i].profile.sprite = sfSprite_create();
    Z1.npc[i].profile.texture = sfTexture_createFromFile(Profile, NULL);
    Z1.npc[i].TextureLeft = sfTexture_createFromFile(Left, NULL);
    sfSprite_setTexture(Z1.npc[i].sprite, Z1.npc[i].TextureLeft, sfTrue);
    sfSprite_setTexture(Z1.npc[i].profile.sprite, profile_texture, sfTrue);
    sfSprite_setPosition(Z1.npc[i].sprite, pos[i]);
    sfSprite_setScale(Z1.npc[i].sprite, (sfVector2f) {0.5, 0.5});
    sfSprite_setScale(Z1.npc[i].profile.sprite, (sfVector2f) {0.45, 0.45});
    sfSprite_setTextureRect(Z1.npc[i].sprite, rect);
    return;
}

void init_area_1_npc_sprites(struct_t *data)
{
    int tab[11] = {1, 1, 1, 1, 2, 2, 2, 2, 2, 2, 2};
    sfVector2f positions[2] = {{312, 480}, {1656, 456}};

    Z1.quest = malloc(sizeof(int) * 11);
    Z1.rect_pos = malloc(sizeof(int) * 2);
    Z1.npc = malloc(sizeof(mobs_t) * 2);
    for (int i = 0; i < 11; i++)
        Z1.quest[i] = tab[i];
    for (int i = 0; i < 2; i++)
        Z1.rect_pos[i] = positions[i];
    Z1.npc[0].name = "Traveler";
    Z1.npc[1].name = "Guard";
    for (int i = 0; i < 2; i++)
        init_area1_npc_images(data, i);
}

void link_area1_str_to_txt(struct_t *data, int i)
{
    Z1.texts[i].txt = sfText_create();
    Z1.texts[i].font = sfFont_createFromFile("asset/BreatheFire.otf");
    sfText_setFont(Z1.texts[i].txt, Z1.texts[i].font);
    sfText_setFillColor(Z1.texts[i].txt, sfBlack);
    sfText_setCharacterSize(Z1.texts[i].txt, 11);
    sfText_setString(Z1.texts[i].txt, Z1.texts[i].str);
}

void init_area1_npc_txt(struct_t *data, char *buffer)
{
    char *str;
    int idx = 0;

    Z1.texts = malloc(sizeof(text_t) * 11);
    for (int a = 0; a < 11; a++) {
        idx = idx_move(buffer, idx, '\n');
        Z1.texts[a].str = malloc(sizeof(char) * 100);
        idx--;
        for (int i = 0; buffer[idx] != '\n'; idx++) {
            Z1.texts[a].str[i] = buffer[idx];
            i++;
            Z1.texts[a].str[i] = '\0';
        }
        link_area1_str_to_txt(data, a);
        idx = idx_move(buffer, idx, '\n');
    }
}

void init_area_1_npc(struct_t *data)
{
    FILE *fp;
    struct stat sb;
    stat("script/1_zone_dialogue.txt", &sb);
    char *buffer = malloc(sizeof(char) * sb.st_size);

    fp = fopen("script/1_zone_dialogue.txt", "r");
    fread(buffer, sizeof(char), sb.st_size, fp);
    init_area_1_npc_sprites(data);
    init_area1_npc_txt(data, buffer);
    free(buffer);
    fclose(fp);
}
