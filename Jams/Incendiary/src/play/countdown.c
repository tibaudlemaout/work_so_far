/*
** EPITECH PROJECT, 2023
** Epitech_Jam_1
** File description:
** countdown
*/
#include "../../include/struct.h"
#include "../../include/my.h"
#include "../../include/define.h"

void display_countdown_text(struct_t *all)
{
    char str[3] = "00";
    int div = 1;

    str[3] = '\0';
    if (all->hourglass.life < 10)
        str[1] = all->hourglass.life + 48;
    if (all->hourglass.life > 9) {
        str[0] = all->hourglass.life / 10 + 48;
        str[1] = all->hourglass.life % 10 + 48;
    }
    sfText_setString(all->countdown.text, str);
    sfRenderWindow_drawText(WIN, all->countdown.text, NULL);
}

void set_countdown(struct_t *all)
{
    all->delay.time = sfClock_getElapsedTime(all->delay.clock);
    all->seconds.time = sfClock_getElapsedTime(all->seconds.clock);
    all->seconds.seconds = all->seconds.time.microseconds / 1000000.0;
    all->delay.seconds = all->delay.time.microseconds / 1000000.0;
}

void countdown(struct_t *all, sprite_t *fire)
{
    set_countdown(all);
    if (all->seconds.seconds > 1) {
        all->hourglass.life--;
        sfClock_restart(all->seconds.clock);
    }
    if (all->delay.seconds > 20 && all->delay.seconds < 40) {
        all->hourglass.rect.left = 23;
        sfSprite_setTextureRect(all->hourglass.sprite, all->hourglass.rect);
        sfSprite_setTexture(all->smoke.sprite, all->smoke.TextureLeft, sfFalse);
    }
    if (all->delay.seconds > 40 && all->delay.seconds < 60) {
        all->hourglass.rect.left = 46;
        sfSprite_setTextureRect(all->hourglass.sprite, all->hourglass.rect);
        sfSprite_setTexture(all->smoke.sprite, all->smoke.TextureRight, sfFalse);
    }
    if (all->delay.seconds > 60) {
        all->hourglass.rect.left = 69;
        sfSprite_setTextureRect(all->hourglass.sprite, all->hourglass.rect);
        sfSprite_setTexture(all->smoke.sprite, all->smoke.TextureUp, sfFalse);
    }
    if (all->delay.seconds > 80)
        all->set = 0;
    display_countdown_text(all);
    while (fire != NULL) {
        if (all->delay.seconds >= fire->delay)
            fire->display = 1;
        fire = fire->next;
    }
}