/*
** EPITECH PROJECT, 2023
** B-MUL-200-NAN-2-1-myrpg-tibaud.le-maout
** File description:
** area1
*/
#include "../../include/my.h"

void area1_display_interaction2(struct_t *data)
{
    sfVector2f pos = sfSprite_getPosition(P.sprite);
    sfVector2f profile_pos = sfSprite_getPosition(P.profile.sprite);
    sfVector2f txt_pos = {pos.x - 190, pos.y + 120};
    int npc = Z1.quest[Z1.quest_index] - 1;
    int txt_selector = Z1.quest_index;

    profile_pos.x += 416;
    sfText_setPosition(Z1.texts[txt_selector].txt, txt_pos);
    sfSprite_setPosition(Z1.npc[npc].profile.sprite, profile_pos);
    sfRenderWindow_drawSprite(WIN, Z1.npc[npc].profile.sprite, NULL);
    sfRenderWindow_drawText(WIN, Z1.texts[txt_selector].txt, NULL);
}

void area1_display_interaction(struct_t *data)
{
    sfVector2f pos = sfSprite_getPosition(P.sprite);
    sfVector2f txt_frame_pos = {pos.x - 210, pos.y + 100};
    sfVector2f interact_txt_pos = {pos.x - 50, pos.y + 75};

    if (Z1.end == 0) {
        if (data->interact == 1 && data->talk == 0) {
            sfText_setPosition(data->interact_txt.txt, interact_txt_pos);
            sfRenderWindow_drawText(WIN, data->interact_txt.txt, NULL);
        }
        if (data->talk == 1) {
            sfSprite_setPosition(data->txt_frame.sprite, txt_frame_pos);
            sfRenderWindow_drawSprite(WIN, data->txt_frame.sprite, NULL);
            area1_display_interaction2(data);
        }
    }
}

void area1_basics_display(struct_t *data)
{
    sfRenderWindow_clear(WIN, sfBlack);
    sfRenderWindow_setView(WIN, data->view);
    sfRenderWindow_drawSprite(WIN, data->bg.sprite, NULL);
    /* for (int y = 0; y < 45; y++) {
        for (int x = 0; x < 80; x++)
        sfRenderWindow_drawRectangleShape(WIN, data->wall[y][x], NULL);
    } */
    for (int i = 0; i < 2; i++)
        sfRenderWindow_drawSprite(WIN, Z1.npc[i].sprite, NULL);
    sfRenderWindow_drawSprite(WIN, P.sprite, NULL);
    sfRenderWindow_drawRectangleShape(WIN, P.hitbox, NULL); // player hitbox
    sfRenderWindow_drawSprite(WIN, data->overlay.sprite, NULL);
}

void area1_display(struct_t *data)
{
    area1_basics_display(data);
    if (data->talk == 0) {
        sfRenderWindow_drawSprite(WIN, P.profile.sprite, NULL);
        area1_display_interaction_ballon(data);
    }
    sfRenderWindow_drawSprite(WIN, data->minimap.sprite, NULL);
    sfRenderWindow_drawRectangleShape(WIN, data->minimapOutline, NULL);
    area1_display_interaction(data);
    sfRenderWindow_display(WIN);
}
