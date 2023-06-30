/*
** EPITECH PROJECT, 2023
** B-SYN-200-NAN-2-1-palindrome-tibaud.le-maout
** File description:
** is_palindrome
*/
#include "../include/palindrome.h"

static void get_rev(global_t *data)
{
    int leftover = 0;
    int nb = data->n;
    data->rev_n = 0;

    while (nb != 0) {
        leftover = nb % data->base;
        data->rev_n = (data->rev_n * data->base) + leftover;
        nb /= data->base;
    }
    return;
}

static void search_for_palindrome(global_t *data)
{
    int iterations = 0;

    while (iterations <= data->i_max) {
        get_rev(data);
        if (data->n == data->rev_n && iterations >= data->i_min) {
            printf("%s leads to %i in %i ", data->n_str, data->n, iterations);
            printf("iteration(s) in base %i\n", data->base);
            return;
        }
        data->n += data->rev_n;
        iterations++;
    }
    printf("no solution\n");
    return;
}

static void check_pal_str(char *str)
{
    int i = 0;
    int j = strlen(str) - 1;

    while (str[i]) {
        if (str[i] == str[j]) {
            i++;
            j--;
        } else {
            fprintf(stderr, "invalid argument\n");
            exit(84);
        }
    }
    return;
}

static void get_based_pal(global_t *data)
{
    int nb = data->pal;
    int leftover = 0;
    int count = 1;
    data->rev_based_str = NULL;

    while (nb != 0) {
        leftover = nb % data->base;
        data->rev_based_str = realloc(data->rev_based_str, count);
        data->rev_based_str[count - 1] = (leftover + 48);
        data->rev_n = (data->rev_n * data->base) + leftover;
        nb /= data->base;
        count++;
    }
    check_pal_str(data->rev_based_str);
    return;
}

int is_palindrome(global_t *data)
{
    if (data->n_str)
        search_for_palindrome(data);
    if (data->pal_str) {
        get_based_pal(data);
        search_for_all_palindromes(data);
    }
    return (0);
}
