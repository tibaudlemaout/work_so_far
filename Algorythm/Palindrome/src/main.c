/*
** EPITECH PROJECT, 2023
** B-SYN-200-NAN-2-1-palindrome-tibaud.le-maout
** File description:
** main
*/
#include "../include/palindrome.h"

static void init_data(global_t *data)
{
    data->n_str = NULL;
    data->pal_str = NULL;
    data->rev_based_str = NULL;
    data->rev_n_str = NULL;
    data->n = 0;
    data->pal = 0;
    data->base = 10;
    data->i_min = 0;
    data->i_max = 100;
    return;
}

static void free_data(global_t *data)
{
    if (data->n_str)
        free(data->n_str);
    if (data->pal_str)
        free(data->pal_str);
    if (data->rev_based_str)
        free(data->rev_based_str);
    if (data->rev_n_str)
        free(data->rev_n_str);
    return;
}

int main(int argc, char **argv)
{
    global_t data;

    init_data(&data);
    error_handling(argc, argv, &data);
    is_palindrome(&data);
    free_data(&data);
    return (0);
}
