/*
** EPITECH PROJECT, 2023
** EPITECH
** File description:
** main
*/
#include "../include/struct.h"
#include "../include/stumper.h"
#include "../include/lib.h"
#include <string.h>

static void free_everything(global_t *global)
{
    free(global->count_str);
    free(global->searched_char);
    free(global);
}

static void init_struct(global_t *global)
{
    global->arg_t = 0;
    global->arg_r = 0;
    global->count_str = NULL;
    global->searched_char = NULL;
}

static void check_for_arg_t_r(global_t *global, char **argv, int argc, int k)
{
    if (strcmp(argv[k], "-t") == 0)
            global->arg_t = 1;
    if (strcmp(argv[k], "-r") == 0)
            global->arg_r = 1;
}

static void get_args(global_t *global, char **argv, int argc)
{
    for (int k = 1; k != argc; k++) {
        check_for_arg_t_r(global, argv, argc, k);
        if (strcmp(argv[k], "-t") != 0 && strcmp(argv[k], "-r") != 0
            && argv[k + 1] != NULL) {
            global->count_str =
                malloc(sizeof(char) * (strlen(argv[k]) + 1));
            global->count_str = strcpy(global->count_str, argv[k]);
            global->searched_char =
                malloc(sizeof(char) * (strlen(argv[k + 1]) + 1));
            global->searched_char = strcpy(global->searched_char, argv[k + 1]);
            break;
        }
        if (strcmp(argv[k], "-t") != 0 && strcmp(argv[k], "-r") != 0
            && argv[k + 1] == NULL) {
            global->count_str = malloc(sizeof(char) * (strlen(argv[k]) + 1));
            global->count_str = strcpy(global->count_str, argv[k]);
            break;
        }
    }
}

int main(int argc, char **argv)
{
    global_t *global = malloc(sizeof(global_t));

    if (argc < 2 || argc > 5) {
        free (global);
        return (84);
    }
    init_struct(global);
    get_args(global, argv, argc);
    if (global->count_str == NULL || global->count_str[0] == '\0' ||
        (global->searched_char != NULL &&
        check_for_spaces(global->searched_char) == 1)) {
        free_everything(global);
        return (84);
    }
    count_letters(global);
    free_everything(global);
    return (0);
}
