/*
** EPITECH PROJECT, 2023
** Semester_2
** File description:
** exit
*/
#include "../include/struct.h"
#include "../include/minishell_1.h"

int new_exit(global_t *data)
{
    my_printf("exit\n");
    exit(data->past_status);
}
