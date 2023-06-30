/*
** EPITECH PROJECT, 2023
** B-SYN-200-NAN-2-1-palindrome-tibaud.le-maout
** File description:
** error_handling
*/
#include "../include/palindrome.h"

static int verif_values(char *val_arg)
{
    int i = 0;

    while (val_arg[i]) {
        if (val_arg[i] >= '0' && val_arg[i] <= '9')
            i++;
        else {
            fprintf(stderr, "invalid argument\n");
            exit(84);
        }
    }
    return (0);
}

static int verif_arg_cont(char *arg, char *val_arg, global_t *data)
{
    if (strcmp(arg, "-b") == 0 && val_arg) {
        if (verif_values(val_arg) == 0 && atoi(val_arg) >= 2 &&
            atoi(val_arg) <= 10) {
            data->base = atoi(val_arg);
            return (1);
        }
    }
    if (strcmp(arg, "-imin") == 0 && val_arg) {
        if (verif_values(val_arg) == 0 && atoi(val_arg) >= 0) {
            data->i_min = atoi(val_arg);
            return (1);
        }
    }
    if (strcmp(arg, "-imax") == 0 && val_arg) {
        if (verif_values(val_arg) == 0 && atoi(val_arg) >= 0) {
            data->i_max = atoi(val_arg);
            return (1);
        }
    }
    return (0);
}

static void verif_arg(char *arg, char *val_arg, global_t *data)
{
    if (strcmp(arg, "-n") == 0 && val_arg) {
        if (verif_values(val_arg) == 0 && atoi(val_arg) >= 0) {
            data->n = atoi(val_arg);
            data->n_str = strdup(val_arg);
            return;
        }
    }
    if (strcmp(arg, "-p") == 0 && val_arg) {
        if (verif_values(val_arg) == 0 && atoi(val_arg) >= 0) {
            data->pal = atoi(val_arg);
            data->pal_str = strdup(val_arg);
            return;
        }
    }
    if (verif_arg_cont(arg, val_arg, data) == 0) {
        fprintf(stderr, "invalid argument\n");
        exit(84);
    }
    return;
}

static void proper_argument(char *arg, char *val_arg, global_t *data)
{
    if (arg[0] == '-') {
        verif_arg(arg, val_arg, data);
        return;
    }
    if ((arg[0] >= '0' && arg[0] <= '9')) {
        verif_values(arg);
        return;
    }
    fprintf(stderr, "invalid argument\n");
    exit(84);
}

int error_handling(int argc, char **argv, global_t *data)
{
    if (argc == 1 || argc > 9) {
        fprintf(stderr, "invalid argument\n");
        exit(84);
    }
    if (strcmp(argv[1], "-h") == 0)
        display_h();
    for (int i = 1; i < argc; i++) {
        proper_argument(argv[i], argv[i + 1], data);
    }
    if ((data->n_str != NULL && data->pal_str != NULL) ||
        (data->n == 0 && data->pal == 0) || (data->i_min > data->i_max)) {
        fprintf(stderr, "invalid argument\n");
        exit(84);
    }
    return (0);
}
