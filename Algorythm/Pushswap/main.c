/*
** EPITECH PROJECT, 2022
** EPITECH
** File description:
** only for the main function
*/
#include "./struct.h"
#include "./pushswap.h"

void fill_list(int argc, char **argv, global_t *data)
{
    int index = 0;
    int values = 1;

    data->lista = malloc(sizeof(int) * argc - 1);
    data->listb = malloc(sizeof(int) * argc - 1);
    while (values < argc) {
        data->lista[index] = my_get_nbr(argv[values]);
        data->listb[index] = 0;
        values ++;
        index ++;
    }
    return;
}

int main (int argc, char **argv)
{
    global_t data;
    data.size_a = argc - 1;
    data.size_b = 0;
    fill_list(argc, argv, &data);
    bubble_push(&data);
    free(data.lista);
    free(data.listb);
    return (0);
}
