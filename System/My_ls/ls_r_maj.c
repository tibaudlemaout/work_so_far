/*
** EPITECH PROJECT, 2022
** my_ls
** File description:
** flag R
*/
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include "ls.h"

int ls_r_maj(const char *pathname)
{
    struct dirent *dir;
    DIR *d = opendir(pathname);

    d = opendir(pathname);
    if (d == NULL)
        my_printf("could not open directory %s\n", pathname);
    dir = readdir(d);
    while (dir != NULL){
        if (dir->d_name[0] == '.')
            dir ++;
        if (dir->d_type == DT_DIR){
            my_printf ("./%s  ", dir->d_name);
            d = opendir(dir->d_name);
        }
        my_printf ("%s  ", dir->d_name);
        dir = readdir(d);
    }
    my_printf("\n");
    closedir(d);
    return (0);
}
