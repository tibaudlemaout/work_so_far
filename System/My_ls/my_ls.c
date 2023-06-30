/*
** EPITECH PROJECT, 2022
** my_ls
** File description:
** main file
*/
#include <dirent.h>
#include <sys/types.h>
#include <stdio.h>
#include "ls.h"

int my_ls(const char *pathname)
{
    struct dirent *dir;
    DIR *d = opendir(pathname);

    d = opendir(pathname);
    if (d == NULL){
        my_printf("could not open directory %s\n", pathname);
    }
    dir = readdir(d);
    while (dir != NULL){
        if (dir->d_name[0] != '.')
            my_printf ("%s  ", dir->d_name);
        dir = readdir(d);
    }
    my_printf("\n");
    closedir(d);
    return (0);
}

int main (int argc, char *argv[])
{
    manage_flags(argc, argv);
    return (0);
}
