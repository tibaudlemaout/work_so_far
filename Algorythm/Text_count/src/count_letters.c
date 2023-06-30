/*
** EPITECH PROJECT, 2023
** stumper
** File description:
** counting the numbers
*/
#include "../include/stumper.h"
#include "../include/struct.h"
#include <string.h>

static int check_letter(char *str, char count_str)
{
    int index = 0;

    while (str[index] != '\0') {
        if (str[index] == count_str)
            return (1);
        index++;
    }
    return (0);
}

static char *fill_letters(char *str, char *count_str)
{
    int str_idx = 0;
    int i = 0;

    while (count_str[i] != '\0') {
        if (check_letter(str, count_str[i]) == 0) {
            str[str_idx] = count_str[i];
            str_idx++;
        }
        i++;
    }
    str[str_idx] = '\0';
    return (str);
}

static int count_occurance(char letter, char *str, int *repeats)
{
    int count = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == letter) {
            count++;
        }
    }
    return (count);
}

static int *occurance(char *letters, global_t *global)
{
    int size = strlen(letters);
    int *repeats = NULL;
    int q = 0;
    int i = 0;

    repeats = malloc(sizeof(int) * size);
    while (letters[q] != '\0') {
        repeats[i] = count_occurance(letters[i], global->count_str, repeats);
        i++;
        q++;
    }
    return (repeats);
}

int count_letters(global_t *global)
{
    char *string_letters = NULL;
    int *repeats = NULL;
    int length = strlen(global->count_str);

    string_letters = malloc(sizeof(char) * length);
    string_letters = fill_letters(string_letters, global->count_str);
    repeats = occurance(string_letters, global);
    display(global, string_letters, repeats, length);
    free(repeats);
    free(string_letters);
    return (0);
}
