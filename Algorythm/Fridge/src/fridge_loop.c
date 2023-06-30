/*
** EPITECH PROJECT, 2023
** epitech
** File description:
** main loop for fridge
*/
#include "duo.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

static char *my_strdup(char *str)
{
    char *dup = malloc(sizeof(char) * (my_strlen(str) + 1));
    int index = 0;

    while (str[index] != '\0') {
        if (str[index] == '\n')
            str[index] = '\0';
        dup[index] = str[index];
        index++;
    }
    dup[index] = '\0';
    return (dup);
}

static char **sort_input(char *buff, fridge_t *fridge)
{
    char **tab = NULL;
    char *token = NULL;

    tab = malloc(sizeof(char *) * 4);
    tab[0] = strtok(my_strdup(buff), " ");
    tab[1] = strtok(NULL, " ");
    tab[2] = strtok(NULL, " ");
    tab[3] = NULL;
    return (tab);
}

int exec_input(char **input, fridge_t *fridge, char *buff)
{
    if (my_strcmp(input[0], "make") == 0) {
        make_meal(input, fridge, buff);
        return (0);
    }
    if (my_strcmp(input[0], "addToFridge") == 0 &&
        input[1] != NULL) {
        add_item(input, fridge);
        return (0);
    }
    if (my_strcmp(input[0], "disp") == 0 &&
        input[1] != NULL) {
        display_fridge(fridge, input);
        return (0);
    }
    if (my_strcmp(input[0], "exit") == 0)
        exit (0);
    printf("'%s': Invalid operation\n", buff);
    return (1);
}

int fridge_loop(fridge_t *fridge)
{
    char **input = NULL;
    char *buff = NULL;
    size_t size = 1;

    while (1) {
        buff = (char *)malloc(size * sizeof(char));
        if (getline(&buff, &size, stdin) < 0)
            break;
        input = sort_input(buff, fridge);
        exec_input(input, fridge, buff);
        free(input);
    }
    free(buff);
    return (0);
}
