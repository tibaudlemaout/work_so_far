/*
** EPITECH PROJECT, 2023
** B-MUL-200-NAN-2-1-myrpg-tibaud.le-maout
** File description:
** display
*/
#include "../../include/my.h"

void display_interaction2(struct_t *data)
{
    sfVector2f pos = sfSprite_getPosition(P.sprite);
    sfVector2f profile_pos = sfSprite_getPosition(P.profile.sprite);
    sfVector2f txt_pos = {pos.x - 190, pos.y + 120};
    int npc = TUTO.quest[TUTO.quest_index] - 1;
    int txt_selector = TUTO.quest_index + 1;

    profile_pos.x += 416;
    if (TUTO.quest_1 == 1) {
        sfText_setPosition(TUTO.texts[0].txt, txt_pos);
        sfSprite_setPosition(TUTO.npc[3].profile.sprite, profile_pos);
        sfRenderWindow_drawSprite(WIN, TUTO.npc[3].profile.sprite, NULL);
        sfRenderWindow_drawText(WIN, TUTO.texts[0].txt, NULL);
    } else {
        sfText_setPosition(TUTO.texts[txt_selector].txt, txt_pos);
        sfSprite_setPosition(TUTO.npc[npc].profile.sprite, profile_pos);
        sfRenderWindow_drawSprite(WIN, TUTO.npc[npc].profile.sprite, NULL);
        sfRenderWindow_drawText(WIN, TUTO.texts[txt_selector].txt, NULL);
    }
}

void get_into_fight_with_soldier(struct_t *data)
{
    if (TUTO.quest_index == 12 && data->random_mob_nb != 5) {
        sfSprite_setTexture(P.sprite, P.TextureRight, sfTrue);
        sfSprite_setTextureRect(P.sprite, (sfIntRect) {47, 0, 47, 48});
        data->random_mob_nb = 5;
        data->set = 6;
    }
}

void display_interaction(struct_t *data)
{
    sfVector2f pos = sfSprite_getPosition(P.sprite);
    sfVector2f txt_frame_pos = {pos.x - 210, pos.y + 100};
    sfVector2f interact_txt_pos = {pos.x - 50, pos.y + 75};

    if (TUTO.end == 0) {
        if (data->interact == 1 && data->talk == 0) {
            sfText_setPosition(data->interact_txt.txt, interact_txt_pos);
            sfRenderWindow_drawText(WIN, data->interact_txt.txt, NULL);
        }
        if (data->talk == 1) {
            get_into_fight_with_soldier(data);
            sfSprite_setPosition(data->txt_frame.sprite, txt_frame_pos);
            sfRenderWindow_drawSprite(WIN, data->txt_frame.sprite, NULL);
            display_interaction2(data);
        }
    }
}

void tutorial_basics_display(struct_t *data)
{
    sfRenderWindow_clear(WIN, sfBlack);
    sfRenderWindow_setView(WIN, data->view);
    sfRenderWindow_drawSprite(WIN, data->bg.sprite, NULL);
    for (int i = 0; i < 4; i++)
        sfRenderWindow_drawSprite(WIN, TUTO.npc[i].sprite, NULL);
    sfRenderWindow_drawSprite(WIN, P.sprite, NULL);
    sfRenderWindow_drawRectangleShape(WIN, P.hitbox, NULL); // player hitbox
    sfRenderWindow_drawSprite(WIN, data->overlay.sprite, NULL);
}

void game_display(struct_t *data)
{
    tutorial_basics_display(data);
    if (data->talk == 0) {
        sfRenderWindow_drawSprite(WIN, P.profile.sprite, NULL);
        if (TUTO.quest_index >= 3)
            sfRenderWindow_drawSprite(WIN, data->icon[2], NULL);
        display_interaction_ballon(data);
    }
    sfRenderWindow_drawSprite(WIN, data->minimap.sprite, NULL);
    sfRenderWindow_drawRectangleShape(WIN, data->minimapOutline, NULL);
    display_interaction(data);
    sfRenderWindow_display(WIN);
}
