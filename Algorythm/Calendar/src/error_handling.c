/*
** EPITECH PROJECT, 2023
** B-SYN-200-NAN-2-1-calendar-tibaud.le-maout
** File description:
** error_handling
*/
#include "../include/calendar.h"

static void display_h(void)
{
    printf("USAGE\n");
    printf("      write instructions to the standard output until the END");
    printf(" instruction\n");
    exit(0);
}

int error_handling(int argc, char **argv)
{
    if (argc > 2)
        exit(84);
    if (argc == 2 && strcmp(argv[1], "-h") == 0)
        display_h();
    return (0);
}
