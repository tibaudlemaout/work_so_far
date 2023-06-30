/*
** EPITECH PROJECT, 2023
** B-MUL-200-NAN-2-1-myrpg-tibaud.le-maout
** File description:
** lib3
*/
#include "../include/my.h"

int my_parsing_strlen(char const *str, int idx)
{
    int cmp = 0;

    for (int i = idx; str[i] != '\n'; i++)
        cmp++;
    return (cmp);
}

int my_parsing_get_nbr(int i, char *str)
{
    long nb = 0;
    int is_neg = 0;

    for (i; str[i] != '/'; i++) {
        if (str[i] == '-')
            is_neg = 1;
        if (str[i] >= '0' && str[i] <= '9') {
            nb *= 10;
            nb += str[i] - 48;
        }
    }
    if (nb < -2147483648 || nb > 2147483647)
        return (0);
    if (is_neg == 1)
        return (-nb);
    return nb;
}

int idx_move(char *buffer, int idx, char stop)
{
    for (idx; buffer[idx] != stop; idx++);
    idx++;
    return (idx + 1);
}

int my_item_get_nbr(int i, char *str)
{
    long nb = 0;
    int is_neg = 0;

    for (i; str[i] != ' '; i++) {
        if (str[i] == '-')
            is_neg = 1;
        if (str[i] >= '0' && str[i] <= '9') {
            nb *= 10;
            nb += str[i] - 48;
        }
    }
    if (nb < -2147483648 || nb > 2147483647)
        return (0);
    if (is_neg == 1)
        return (-nb);
    return nb;
}

void init_one_cell(struct_t *data, int i)
{
    data->inventory.tab[i].taken = 0;
    data->inventory.tab[i].item.hp = 0;
    data->inventory.tab[i].item.att = 0;
    data->inventory.tab[i].item.def = 0;
    data->inventory.tab[i].item.spd = 0;
    data->inventory.tab[i].item.equipement = 0;
    data->inventory.tab[i].item.type = 0;
    return;
}
