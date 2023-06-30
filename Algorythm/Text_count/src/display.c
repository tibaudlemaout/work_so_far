/*
** EPITECH PROJECT, 2023
** stumper
** File description:
** display
*/
#include <string.h>
#include "../include/stumper.h"
#include "../include/struct.h"

static int basic_display(global_t *global, char *letter, int *repeat,
    int length)
{
    for (int i = 0; letter[i] != '\0'; i++) {
        if (repeat[i] == 0 || letter[i] <= 32) {
            i++;
        } else {
            printf("%c:%i\n", letter[i], repeat[i]);
        }
    }
    return (0);
}

static int verif_letter(global_t *global, char letter, int *repeat)
{
    int i = 0;

    while (global->searched_char[i] != '\0') {
        if (letter == global->searched_char[i])
            return (1);
        else
            i++;
    }
    return (0);
}

static int precise_display(global_t *global, char *letter, int *repeat,
    int length)
{
    int i = 0;
    int nb = 0;

    while (letter[i] != '\0') {
        if (repeat[i] == 0 ||
            verif_letter(global, letter[i], repeat) == 0) {
            i++;
        } else {
            printf("%c:%i\n", letter[i], repeat[i]);
            i++;
        }
    }
    display_remaining_char(global, letter);
    return (0);
}

static int display_next(global_t *global, char *letter, int *repeat,
    int length)
{
    if (global->arg_t == 1 && global->arg_r == 0
        && global->searched_char == NULL) {
        bubble_sort_array(repeat, strlen(letter), letter);
        basic_display(global, letter, repeat, length - 1);
    }
    if (global->arg_t == 0 && global->arg_r == 1
        && global->searched_char == NULL) {
        display_r(global, letter, repeat);
        return (0);
    }
    if (global->arg_t == 1 && global->arg_r == 1
        && global->searched_char == NULL) {
        bubble_sort_array(repeat, strlen(letter), letter);
        display_r(global, letter, repeat);
        return (0);
    }
    return (0);
}

int display(global_t *global, char *letter, int *repeat, int length)
{
    if (global->arg_t == 0 && global->arg_r == 0
        && global->searched_char == NULL) {
        basic_display(global, letter, repeat, length);
        return (0);
    }
    if (global->arg_t == 0 && global->arg_r == 0
        && global->searched_char != NULL) {
        precise_display(global, letter, repeat, length);
        return (0);
    }
    if (global->arg_t == 1 && global->arg_r == 0
        && global->searched_char != NULL) {
        bubble_sort_array(repeat, strlen(letter), letter);
        precise_display(global, letter, repeat, length);
    }
    display_next(global, letter, repeat, length);
    return (0);
}
