/*
** EPITECH PROJECT, 2023
** B-MUL-200-NAN-2-1-myrpg-tibaud.le-maout
** File description:
** get_loot
*/
#include "../include/my.h"

int get_universal_loot(struct_t *data, int drop)
{
    if (drop >= 0 && drop <= 5)
        return (0);
    if (drop >= 5 && drop <= 10)
        return (1);
    if (drop >= 11 && drop <= 15)
        return (2);
    if (drop >= 16 && drop <= 20)
        return (3);
    if (drop >= 21 && drop <= 25)
        return (4);
    if (drop >= 26 && drop <= 30)
        return (5);
    if (drop >= 31 && drop <= 35)
        return (6);
    if (drop >= 35 && drop <= 40)
        return (7);
    return (0);
}

int get_area_1_loot(struct_t *data, int drop)
{
    if (drop == 41 && drop == 42)
        return (8);
    if (drop == 43 && drop == 44)
        return (9);
    if (drop == 45 && drop == 46)
        return (10);
    if (drop == 47 && drop == 48)
        return (11);
    return (drop - 37);
}

int get_area_loot(struct_t *data, int index)
{
    int ret = 0;
    int ok = 0;

    if (data->area == 1 && index < 59) {
        ret = get_area_1_loot(data, index);
        ok = 1;
        return (ret);
    }
    if (data->area == 2 && index < 54) {
        ok = 1;
        return (ret - 19);
    }
    if (data->area == 3 && index < 55) {
        ok = 1;
        return (ret - 6);
    }
    if (ok == 0)
        return (-1);
}
