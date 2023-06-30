/*
** EPITECH PROJECT, 2023
** do_arg_t.c
** File description:
** do arg t
*/

#include <string.h>
#include "../include/stumper.h"
#include "../include/struct.h"

static void swap_elem(int *array, int index1, int index2)
{
    int temp = 0;

    temp = array[index1];
    array[index1] = array[index2];
    array[index2] = temp;
}

static void swap_elem_char(char *array, int index1, int index2)
{
    char temp = 'a';

    temp = array[index1];
    array[index1] = array[index2];
    array[index2] = temp;
}

static int check_smaller(int *array, int i, char *letter)
{
    int stop = 0;

    if (array[i] < array[i + 1]) {
        swap_elem(array, i, i + 1);
        swap_elem_char(letter, i, i + 1);
        stop++;
    }
    return (stop);
}

void bubble_sort_array(int *array, int size, char *letter)
{
    int stop = 0;

    while (stop != -1) {
        stop = 0;
        for (int i = 0; i != size - 1; i++) {
            stop = stop + check_smaller(array, i, letter);
        }
        if (stop == 0)
            stop = -1;
    }
}
