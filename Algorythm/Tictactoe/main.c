/*
** EPITECH PROJECT, 2023
** EPITECH
** File description:
** main
*/
#include "include/stumper.h"

static void print_map(char **map)
{
    for (int i = 0; map[i] != NULL; i++) {
        printf("%s\n", map[i]);
    }
}

static void change_turn(global_t *global)
{
    if (global->turn == 1) {
        global->turn = 2;
    } else {
        global->turn = 1;
    }
}

int main(int argc, char **argv)
{
    global_t global;
    char **map;
    int *attack;

    init_struct(&global);
    get_argv(argc, argv, &global);
    map = create_map(&global);
    print_map(map);
    while (1) {
        attack = get_attack(&global);
        map = display_move(&global, attack, map);
        print_map(map);
        if (win_cond(&global, map, attack) == 1 ||
            draw_cond(map) == 1)
            break;
        change_turn(&global);
        free(attack);
    }
    free_map(map);
    return (0);
}
