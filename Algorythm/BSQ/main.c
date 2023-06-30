/*
** EPITECH PROJECT, 2022
** EPITECH
** File description:
** main
*/
#include "stdlib.h"
#include "struct.h"
#include "bsq.h"
#include "define.h"

int verif_new_map(char *string)
{
    int index = 0;
    int size = my_strlen(string);

    if (size == 0)
        return (84);
    while (index <= size) {
        if (string[index] != '.' && string[index] != 'o' &&
            string[index] != '\0') {
            return (84);
        }
        index ++;
    }
    return (0);
}

void init_data(GLOBAL_T *data)
{
    data->c_tab.y_pos = 1;
    data->c_tab.x_pos = 0;
    data->r_x = 0;
    data->r_y = 0;
    data->check_value = 0;
    data->max_check_value = 0;
    return;
}

int main(int argc, char **argv)
{
    GLOBAL_T data;
    int size = 0;

    init_data(&data);
    if (argc != 2 && argc != 3)
        return (84);
    if (argc == 2)
        op_rd_file(argv[1], &data);
    if (argc == 3) {
        size = my_get_nbr(argv[1]);
        if (verif_new_map(argv[2]) == 84)
            return (84);
        create_template(&data, size, argv[2]);
    }
    free(data.gen_map);
    return (0);
}
