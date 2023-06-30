/*
** EPITECH PROJECT, 2023
** Epitech_Jam_1
** File description:
** fire
*/
#include "../../include/struct.h"
#include "../../include/my.h"
#include "../../include/define.h"

void fire_detection(struct_t *all, sprite_t *fire)
{
    while (fire != NULL) {
        switch (P.direction) {
            case 1:
                if (P.pos.x == fire->pos.x && fire->pos.y >= P.pos.y - (80 * 2) && fire->pos.y < P.pos.y
                    && fire->life > 0 && fire->display == 1) {
                    fire->life--;
                }
                break;
            case 2:
                if (P.pos.y == fire->pos.y && fire->pos.x <= P.pos.x + (80 * 2) && fire->pos.x > P.pos.x
                    && fire->life > 0 && fire->display == 1) {
                    fire->life--;
                }
                break;
            case 3:
                if (P.pos.x == fire->pos.x && fire->pos.y <= P.pos.y + (80 * 2) && fire->pos.y > P.pos.y
                    && fire->life > 0 && fire->display == 1) {
                    fire->life--;
                }
                break;
            case 4:
                if (P.pos.y == fire->pos.y && fire->pos.x >= P.pos.x - (80 * 2) && fire->pos.x < P.pos.x
                    && fire->life > 0 && fire->display == 1) {
                    fire->life--;
                }
                break;
        }
        fire = fire->next;
    }
}