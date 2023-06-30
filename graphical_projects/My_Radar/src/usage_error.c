/*
** EPITECH PROJECT, 2023
** EPITECH
** File description:
** usage_error
*/
#include "../include/radar.h"

int help_manual(void)
{
    my_printf("Air traffic simulation panel\n");
    my_putchar('\n');
    my_printf("USAGE\n");
    my_printf(" ./my_radar [OPTION] path_to_script\n");
    my_printf("  path_to_script    The path to the script file\n");
    my_putchar('\n');
    my_printf("OPTIONS\n");
    my_printf("-h            printf the usage and quit\n");
    my_putchar('\n');
    my_printf("USER INTERACTIONS\n");
    my_printf(" 'L' key        enable/disable hitboxes and areas.\n");
    my_printf(" 'S' key        enable/disable sprites.\n");
    return (0);
}
