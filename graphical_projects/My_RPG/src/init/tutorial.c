/*
** EPITECH PROJECT, 2023
** B-MUL-200-NAN-2-1-myrpg-tibaud.le-maout
** File description:
** tutorial
*/
#include "../../include/my.h"

void link_tutorial_str_to_txt(struct_t *data, int i)
{
    TUTO.texts[i].txt = sfText_create();
    TUTO.texts[i].font = sfFont_createFromFile("asset/BreatheFire.otf");
    sfText_setFont(TUTO.texts[i].txt, TUTO.texts[i].font);
    sfText_setFillColor(TUTO.texts[i].txt, sfBlack);
    sfText_setCharacterSize(TUTO.texts[i].txt, 11);
    sfText_setString(TUTO.texts[i].txt, TUTO.texts[i].str);
}

void init_tutorial_txt(struct_t *data, char *buffer)
{
    int idx = 0;

    TUTO.texts = malloc(sizeof(text_t) * 15);
    TUTO.npc = malloc(sizeof(mobs_t) * 4);
    TUTO.npc[0].name = "Chief";
    TUTO.npc[1].name = "Blacksmith";
    TUTO.npc[2].name = "Armorer";
    TUTO.npc[3].name = "Guard";
    for (int a = 0; a < 15; a++) {
        idx = idx_move(buffer, idx, '\n');
        TUTO.texts[a].str = malloc(sizeof(char) * 100);
        idx--;
        for (int i = 0; buffer[idx] != '\n'; idx++) {
            TUTO.texts[a].str[i] = buffer[idx];
            i++;
            TUTO.texts[a].str[i] = '\0';
        }
        link_tutorial_str_to_txt(data, a);
        idx = idx_move(buffer, idx, '\n');
    }
}

void init_tutorial(struct_t *data)
{
    FILE *fp;
    struct stat sb;
    stat("script/tutorial_dialogue.txt", &sb);
    char *buffer = malloc(sizeof(char) * sb.st_size);
    int tab[14] = {1, 1, 2, 2, 3, 1, 1, 4, 4, 4, 4, 4, 4, 4};
    sfVector2f positions[4] = {{792, 312}, {456 ,816}, {528, 816}, {1104, 576}};

    TUTO.quest = malloc(sizeof(int) * 14);
    TUTO.rect_pos = malloc(sizeof(int) * 4);
    for (int i = 0; i < 14; i++)
        TUTO.quest[i] = tab[i];
    for (int i = 0; i < 4; i++)
        TUTO.rect_pos[i] = positions[i];
    fp = fopen("script/tutorial_dialogue.txt", "r");
    fread(buffer, sizeof(char), sb.st_size, fp);
    init_tutorial_txt(data, buffer);
    init_tutorial_sprites(data);
    free(buffer);
    fclose(fp);
}
