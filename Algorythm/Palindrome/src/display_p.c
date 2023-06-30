/*
** EPITECH PROJECT, 2023
** B-SYN-200-NAN-2-1-palindrome-tibaud.le-maout
** File description:
** display_p
*/
#include "../include/palindrome.h"

static int check_pal_based(char *str)
{
    int i = 0;
    int j = strlen(str) - 1;

    while (str[i]) {
        if (str[i] == str[j]) {
            i++;
            j--;
        } else
            return (1);
    }
    return (0);
}

static void display_p(global_t *data, int loops, int iterations, int nb)
{
    if ((nb == data->pal || strcmp(data->n_str, data->rev_based_str) == 0) &&
        iterations >= data->i_min && iterations <= data->i_max ) {
        printf("%i leads to %i in %i ", loops, data->pal, iterations);
        printf("iteration(s) in base %i\n", data->base);
        data->solved = 1;
    }
    return;
}

static void get_n_str(global_t *data)
{
    int i = 0;
    int j = strlen(data->rev_n_str);
    data->n_str = NULL;

    data->n_str = malloc(sizeof(char) * (strlen(data->rev_n_str)));
    while (j != 0) {
        data->n_str[i] = data->rev_n_str[j - 1];
        i++;
        j--;
    }
    data->n_str[i + 1] = '\0';
    return;
}

static void get_rev_pal(global_t *data, int nb)
{
    int leftover = 0;
    data->rev_n = 0;
    int count = 1;
    char *rev_nbr = NULL;

    while (nb != 0) {
        leftover = nb % data->base;
        rev_nbr = realloc(rev_nbr, count);
        rev_nbr[count - 1] = (leftover + 48);
        data->rev_n = (data->rev_n * data->base) + leftover;
        nb /= data->base;
        count++;
    }
    data->rev_n_str = strdup(rev_nbr);
    free(rev_nbr);
    get_n_str(data);
    if (data->base != 10)
        decimal_conv(data);
    return;
}

void search_for_all_palindromes(global_t *data)
{
    int iterations = 0;
    int nb = 0;
    int loops = 1;
    data->solved = 0;

    while (loops <= data->pal) {
        nb = loops;
        while (iterations <= data->i_max && nb <= data->pal) {
            get_rev_pal(data, nb);
            display_p(data, loops, iterations, nb);
            nb += data->rev_n;
            iterations++;
        }
        iterations = 0;
        loops++;
    }
    if (data->solved == 0)
        printf("no solution\n");
    return;
}
