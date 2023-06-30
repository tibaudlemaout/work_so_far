/*
** EPITECH PROJECT, 2023
** B-MUL-200-NAN-2-1-myrpg-tibaud.le-maout
** File description:
** loop_selector
*/
#include "../include/my.h"

void main_loop4(struct_t *data, menu_t *menu, fight_t *fight)
{
    switch (data->set) {
        case 0:
            return;
        case 16:
            dungeon1_loop(data);
            break;
    }
}

void main_loop3(struct_t *data, menu_t *menu, fight_t *fight)
{
    switch (data->set) {
        case 0:
            return;
        case 11:
            tutorial_animation(data);
            break;
        case 12:
            tutorial_animation2(data);
            break;
        case 13:
            tutorial_animation3(data);
            break;
        case 14:
            area1_loop(data);
            break;
        case 15:
            in_game_menu_loop(data);
            break;
    }
    main_loop4(data, menu, fight);
}

void main_loop2(struct_t *data, menu_t *menu, fight_t *fight)
{
    switch (data->set) {
        case 0:
            return;
        case 6:
            starting_fight_animation(data, 0, 7);
            break;
        case 7:
            fight = fight_loop(data);
            break;
        case 8:
            finishing_fight_animation(data, fight);
            break;
        case 9:
            inventory_loop(data);
            break;
        case 10:
            map_loop(data);
            break;
    }
    main_loop3(data, menu, fight);
}

void main_loop(struct_t *data, menu_t *menu, fight_t *fight)
{
    while (data->set != 0) {
        switch (data->set) {
        case 1:
            menu_loop(data, menu);
            break;
        case 3:
            selection_loop(data, menu);
            break;
        case 4:
            name_loop(data, menu);
            break;
        case 5:
            game_loop(data);
            break;
        }
        main_loop2(data, menu, fight);
    }
}

