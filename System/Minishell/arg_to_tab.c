/*
** EPITECH PROJECT, 2023
** EPITECH
** File description:
** Step_3
*/
#include "include/minishell_1.h"
#include "./include/struct.h"

int get_layers(char *arg)
{
    int layers = 1;
    char *token = NULL;

    token = strtok(my_strdup(arg), " \t");
    while (token != NULL) {
        token = strtok(NULL, " \t");
        layers ++;
    }
    return (layers);
}

char *copy_line(char *tab, char *token)
{
    for (int i = 0; token[i] != '\0'; i++) {
        tab[i] = token[i];
        if (token[i] == '\n')
            tab[i] = '\0';
    }
    return (tab);
}

void print_arg(char *arg, global_t *data)
{
    int index = 0;
    char *token = NULL;
    int layers = get_layers(arg);

    data->tab = malloc(sizeof(char *) * (layers));
    token = strtok(arg, " \t");
    while (token != NULL) {
        data->tab[index] = malloc(sizeof(char) * (my_strlen(token) + 1));
        data->tab[index] = copy_line(data->tab[index], token);
        data->tab[index][my_strlen(data->tab[index])] = '\0';
        token = strtok(NULL, " \t");
        index ++;
    }
    data->tab[index + 1] = NULL;
    return;
}
