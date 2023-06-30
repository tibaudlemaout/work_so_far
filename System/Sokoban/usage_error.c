/*
** EPITECH PROJECT, 2022
** usage error management
** File description:
** for sokoban
*/
#include <stdlib.h>
#include <unistd.h>
#include "sokoban.h"

int error(int argc, INIT_S *data)
{
    if (argc != 2){
        my_printf("Missing arguments,\n");
        my_printf("USAGE:\n");
        my_printf("     ./my_sokoban <filepath to map>\n");
        free_all(data);
        exit(84);
    }
    return (0);
}

int help_manual(char **av, INIT_S *data)
{
    if (av[1][0] == '-' && av[1][1] == 'h'){
        my_printf("USAGE\n");
        my_printf("     ./my_sokoban map\n");
        my_printf("DESCRIPTION\n");
        my_printf("     map filled representing the warehouse map, ");
        my_printf("containing '#' for walls,\n");
        my_printf("          'P' for the player, 'X' for boxes and '0' ");
        my_printf("for storage locations.\n");
        my_printf("Use the arrow keys to move around, space to reset the ");
        my_printf("map and backspace to exit the game.\n");
        free_all(data);
        exit(84);
    }
    return (0);
}

int check_map(const char *buff, INIT_S *data)
{
    int i = 0;

    while (buff[i] != '\0'){
        if (buff[i] != '#' && buff[i] != ' ' && buff[i] != 'P' &&
            buff[i] != 'X' && buff[i] != 'O' && buff[i] != '\n' &&
            buff[i] != '\0'){
            free_all(data);
            exit(84);
            }
        i++;
    }
    return (0);
}
