/*
** EPITECH PROJECT, 2023
** Epitech_Jam_1
** File description:
** read_script
*/
#include "../../include/struct.h"
#include "../../include/my.h"
#include "../../include/define.h"

int my_get_nbr(int i, char *str)
{
    long nb = 0;
    int is_neg = 0;

    for (i; str[i] != ' ' && str[i] != '\n' && str[i] != '\0'; i++) {
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

void read_script(struct_t *all, sprite_t **fire, sprite_t **obj)
{
    struct stat sb;
    stat("script1.txt", &sb);
    char buffer[sb.st_size + 1];
    int fd = open("script1.txt", O_RDONLY);

    read(fd, buffer, sb.st_size);
    buffer[sb.st_size] = '\0';
    all->fire_nb = 0;
    for (int i = 0; buffer[i]; i++) {
        if (buffer[i] == 'F') {
            all->fire_nb++;
            get_fire_script(all, buffer, i);
            add_fire(all, fire);
        }
        if (buffer[i] == 'O') {
            get_object_script(all, buffer, i);
            add_object(all, obj);
        }
    }
    close(fd);
}
