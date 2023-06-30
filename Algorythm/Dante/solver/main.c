/*
** EPITECH PROJECT, 2023
** B-CPE-200-NAN-2-1-dante-tibaud.le-maout
** File description:
** main
*/
#include "include/my.h"

void init_struct(struct_t *data, char *filepath)
{
    FILE *fd = fopen(filepath, "r");
    size_t size = 0;
    char *str;
    int i = 0;

    if (fd == NULL)
        exit(84);
    data->map = malloc(sizeof(char *) * 100);
    for (; getline(&str, &size, fd) != -1; i++)
        data->map[i] = my_strcpy(str);
    data->map[i] = NULL;
    data->lines = get_lines(data->map) - 1;
    data->cols = my_strlen(data->map[0]);
    data->y = data->lines;
    data->x = data->cols - 2;
    if (data->lines >= data->cols)
        data->max = data->lines;
    else
        data->max = data->cols;

}

void display_solution_cont(struct_t *data, int y, int x)
{
    if (data->map[y][x] == '@')
        data->map[y][x] = '*';
    return;
}

void display_solution(struct_t *data)
{
    for (int y = 0; data->map[y]; y++) {
        for (int x = 0; data->map[y][x]; x++) {
            display_solution_cont(data, y, x);
        }
    }
    data->map[data->lines][data->cols - 2] = 'o';
    for (int i = 0; data->map[i] != NULL; i++)
        my_putstr(data->map[i]);
}

int main(int argc, char **argv)
{
    struct_t *data = malloc(sizeof(struct_t));

    if (argc != 2)
        return 84;
    init_struct(data, argv[1]);
    for (int i = 0; i != data->max; i++) {
    for (int y = 0; y < data->lines; y++)
            find_dead_end(data, y);
    }
    best_path(data, data->lines, data->cols - 2);
    if (data->map[0][0] == 'n') {
        my_putstr("no solution found\n");
        return 84;
    }
    display_solution(data);
    free(data);
}
