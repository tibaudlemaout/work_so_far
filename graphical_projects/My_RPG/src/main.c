/*
** EPITECH PROJECT, 2023
** B-MUL-200-NAN-2-1-myrpg-tibaud.le-maout
** File description:
** main
*/
#include "../include/my.h"

void start(void)
{
    menu_t *menu = init_menu();
    struct_t *data = init_struct();
    save_t save = load_save(data);
    fight_t *fight;

    sfRenderWindow_isOpen(WIN);
    main_loop(data, menu, fight);
    sfRenderWindow_close(WIN);
    free(data);
}

int main(int ac, char **av)
{
    if (ac == 2 && my_strcmp(av[1], "-h") == 0) {
        my_putstr("DESCRIPTION\n");
        my_putstr("\t- simple raster graphics editor\n");
        my_putstr("\t- opens, modifies and saves image files");
        my_putstr("\t- SPACE key opens tolls menu\n");
        my_putstr("\nno arguments needed\n");
        return 0;
    } else if (ac != 1) {
        my_putstr("bad arguments, try with -h");
        return 84;
    }
    start();
    return 0;
}
