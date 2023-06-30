/*
** EPITECH PROJECT, 2023
** stumper
** File description:
** init the structure
*/
#include "include/stumper.h"
#include <string.h>

static int set_p1_char(global_t *global, char *new_char)
{
    int size = strlen(new_char);
    if (size > 1)
        exit (84);
    global->p1 = new_char[0];
    return (0);
}

static int set_p2_char(global_t *global, char *new_char)
{
    int size = strlen(new_char);
    if (size > 1)
        exit (84);
    global->p2 = new_char[0];
    return (0);
}

static int set_size(global_t *global, char *new_size)
{
    int i = 0;

    while (new_size[i] != '\0') {
        if (new_size[i] >= '0' && new_size[i] <= '9')
            i ++;
        else
            exit (84);
    }
    global->size = my_get_nbr(new_size);
    if (global->size < 3)
        exit(84);
    return (0);
}

int get_argv(int argc, char **argv, global_t *global)
{
    if (argc > 7)
        exit (84);
    if (argc == 1)
        return (0);
    for (int i = 1; argv[i + 1] != NULL; i ++) {
        if (strcmp(argv[i], "-p1") == 0)
            set_p1_char(global, argv[i + 1]);
        if (strcmp(argv[i], "-p2") == 0)
            set_p2_char(global, argv[i + 1]);
        if (strcmp(argv[i], "-s") == 0)
            set_size(global, argv[i + 1]);
    }
    diff_p_char(global);
    return (0);
}

void init_struct(global_t *global)
{
    global->p1 = 'X';
    global->p2 = 'O';
    global->size = 3;
    global->turn = 1;
    return;
}
