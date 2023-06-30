/*
** EPITECH PROJECT, 2023
** Semester_2
** File description:
** error_handling
*/
#include "../include/struct.h"
#include "../include/dante.h"

int error_handling_gen(int argc, char **argv)
{
    int index = 0;
    if (argc != 3 && argc != 4)
        return (84);

    while (argv[1][index] != '\0') {
        if (argv[1][index] < '0' || argv[1][index] > '9')
            return (84);
        index ++;
    }
    index = 0;
    while (argv[2][index] != '\0') {
        if (argv[2][index] < '0' || argv[2][index] > '9')
            return (84);
        index ++;
    }
    if (argc == 4) {
        if (strcmp(argv[3], "perfect") != 0)
            return (84);
    }
    return (0);
}
