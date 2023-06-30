/*
** EPITECH PROJECT, 2022
** my_ls
** File description:
** managing flags
*/
#include "ls.h"

int manage_flags(int argc, char **argv)
{
    int index = 1;
    char *filepath;
    if (argc == 1) {
        my_ls("./");
        return (0);
    }
    while (index < argc) {
        if (argv[index][0] == '.' && argv[index][0] != '-') {
            my_ls(argv[1]);
        }
        if (argv[index][0] == '-') {
            switch (argv[1][1]) {
            case 'l' : ls_l("./"); break;
            case 'a' : ls_a("./"); break;
            case 'R' : ls_r_maj("./"); break;
            }
        }
        index ++;
    }
    return 0;
}
