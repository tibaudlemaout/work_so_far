/*
** EPITECH PROJECT, 2023
** EPITECH
** File description:
** collision
*/
#include "../include/radar.h"

int invuln_calc(tower_t *tower, plane_t *plane, float impact)
{
    if (impact < tower->rds) {
        plane->invuln = 1;
        return (1);
    } else {
        plane->invuln = 0;
        return (0);
    }
    return (0);
}

void plane_invuln(tower_t *tower, plane_t *plane)
{
    float pos_x = 0;
    float pos_y = 0;
    float impact = 0;

    while (tower != NULL) {
        pos_x = pow((tower->t_pos.x + 50) - plane->a_pos.x , 2);
        pos_y = pow((tower->t_pos.y + 50) - plane->a_pos.y, 2);
        impact = sqrt(pos_x + pos_y);
        if (invuln_calc(tower, plane, impact) == 1) {
            return;
        } else
        tower = tower->T2;
    }
    return;
}

void collision_calc(global_t *data, plane_t *plane,  plane_t *P2, float impact)
{
    if (impact < 20.1 && impact != 0 && plane->invuln == 0 &&
        plane->done == 0 && P2->done == 0) {
        plane->done = 1;
        P2->done = 1;
        data->end_value += 2;
    }
    return;
}

void collision(global_t *data, plane_t *plane, tower_t *tower)
{
    float pos_x;
    float pos_y;
    float impact;

    while (plane != NULL) {
        plane_invuln(tower, plane);
        plane_t *check_p = plane->P2;
        while (check_p != NULL) {
            pos_x = pow(plane->a_pos.x - check_p->a_pos.x, 2);
            pos_y = pow(plane->a_pos.y - check_p->a_pos.y, 2);
            impact = sqrt(pos_x + pos_y);
            collision_calc(data, plane, check_p, impact);
            check_p = check_p->P2;
        }
        plane = plane->P2;
    }
    return;
}
