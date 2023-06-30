/*
** EPITECH PROJECT, 2023
** B-MUL-200-NAN-2-1-myrpg-tibaud.le-maout
** File description:
** dungeon1
*/
#include "../../include/my.h"

void dungeon1_display_interaction2(struct_t *data)
{
    sfVector2f pos = sfSprite_getPosition(P.sprite);
    sfVector2f profile_pos = sfSprite_getPosition(P.profile.sprite);
    sfVector2f txt_pos = {pos.x - 190, pos.y + 120};
    int npc = D1.quest[D1.quest_index] - 1;
    int txt_selector = D1.quest_index;

    profile_pos.x += 416;
    sfText_setPosition(D1.texts[txt_selector].txt, txt_pos);
    sfSprite_setPosition(D1.npc[npc].profile.sprite, profile_pos);
    sfRenderWindow_drawSprite(WIN, D1.npc[npc].profile.sprite, NULL);
    sfRenderWindow_drawText(WIN, D1.texts[txt_selector].txt, NULL);
}

void dungeon1_display_interaction(struct_t *data)
{
    sfVector2f pos = sfSprite_getPosition(P.sprite);
    sfVector2f txt_frame_pos = {pos.x - 210, pos.y + 100};
    sfVector2f interact_txt_pos = {pos.x - 50, pos.y + 75};

    if (D1.end == 0) {
        if (data->interact == 1 && data->talk == 0) {
            sfText_setPosition(data->interact_txt.txt, interact_txt_pos);
            sfRenderWindow_drawText(WIN, data->interact_txt.txt, NULL);
        }
        if (data->talk == 1) {
            sfSprite_setPosition(data->txt_frame.sprite, txt_frame_pos);
            sfRenderWindow_drawSprite(WIN, data->txt_frame.sprite, NULL);
            dungeon1_display_interaction2(data);
        }
    }
}

void dungeon1_basics_display(struct_t *data)
{
    sfRenderWindow_clear(WIN, sfBlack);
    sfRenderWindow_setView(WIN, data->view);
    sfRenderWindow_drawSprite(WIN, data->bg.sprite, NULL);
    for (int y = 0; y < 45; y++) {
        for (int x = 0; x < 80; x++)
        sfRenderWindow_drawRectangleShape(WIN, data->wall[y][x], NULL);
    }
    sfRenderWindow_drawSprite(WIN, D1.npc[0].sprite, NULL);
    if (D1.quest_index == 14 && D1.quest_2 == 0)
        sfRenderWindow_drawSprite(WIN, D1.npc[1].sprite, NULL);
    sfRenderWindow_drawSprite(WIN, P.sprite, NULL);
    sfRenderWindow_drawRectangleShape(WIN, P.hitbox, NULL); // player hitbox
    sfRenderWindow_drawSprite(WIN, data->overlay.sprite, NULL);
}

void dungeon1_display(struct_t *data)
{
    dungeon1_basics_display(data);
    if (data->talk == 0) {
        sfRenderWindow_drawSprite(WIN, P.profile.sprite, NULL);
        dungeon1_display_interaction_ballon(data);
    }
    sfRenderWindow_drawSprite(WIN, data->minimap.sprite, NULL);
    sfRenderWindow_drawRectangleShape(WIN, data->minimapOutline, NULL);
    dungeon1_display_interaction(data);
    sfRenderWindow_display(WIN);
}
