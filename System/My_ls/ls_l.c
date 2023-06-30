/*
** EPITECH PROJECT, 2022
** my_ls
** File description:
** flag l
*/
#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include "ls.h"

int perm_access(struct stat info)
{
    my_printf(S_ISDIR(info.st_mode) ? "d" : "-");
    my_printf((info.st_mode & S_IRUSR) ? "r" : "-");
    my_printf((info.st_mode & S_IWUSR) ? "w" : "-");
    my_printf((info.st_mode & S_IXUSR) ? "e" : "-");
    my_printf((info.st_mode & S_IRGRP) ? "r" : "-");
    my_printf((info.st_mode & S_IWGRP) ? "w" : "-");
    my_printf((info.st_mode & S_IXGRP) ? "e" : "-");
    my_printf((info.st_mode & S_IROTH) ? "r" : "-");
    my_printf((info.st_mode & S_IWOTH) ? "w" : "-");
    my_printf((info.st_mode & S_IXOTH) ? "e" : "-");
    my_printf(" ");
}

int month_tab(int month)
{
    switch (month) {
        case 0 :my_printf("Jan "); break;
        case 1 :my_printf("Feb "); break;
        case 2 :my_printf("Mar "); break;
        case 3 :my_printf("Apr "); break;
        case 4 :my_printf("May "); break;
        case 5 :my_printf("Jun "); break;
        case 6 :my_printf("Jul "); break;
        case 7 :my_printf("Aug "); break;
        case 8 :my_printf("Sep "); break;
        case 9 :my_printf("Oct "); break;
        case 10 :my_printf("Nov "); break;
        case 11 :my_printf("Dec "); break;
        default: ; break;
    }
}

int time_disp(struct stat info)
{
    time_t date;
    int index = 0;
    char *disp_time;
    disp_time = malloc(sizeof(char) * 24);
    time(&date);
    disp_time = ctime(&info.st_mtime);
    while (index <= 24) {
        while ((index >= 4 && index <= 15)) {
        my_printf("%c", disp_time[index]);
        index ++;
        }
        index ++;
    }
    my_putchar (' ');
    return (0);
}

int l_display(struct dirent *dir, struct stat info)
{
    struct passwd *id;
    struct group *gid;
    if (stat(dir->d_name, &info) != -1){
        perm_access(info);
        my_printf("%d ", info.st_nlink);
        id = getpwuid(info.st_uid);
        my_printf("%s ", id->pw_name);
        gid = getgrgid(info.st_gid);
        my_printf("%s ", gid->gr_name);
        my_printf("%d ", info.st_size);
        time_disp(info);
        my_printf ("%s\n", dir->d_name);
    }
}

int ls_l(const char *filepath)
{
    struct dirent *dir;
    struct stat info;
    DIR *d = opendir(filepath);

    d = opendir(filepath);
    if (d == NULL){
        my_printf("could not open directory %s\n", filepath);
    }
    dir = readdir(d);
    stat(d, &info);
    my_printf("total:%d\n", info.st_blocks);
    while (dir != NULL){
        if (dir->d_name[0] != '.'){
            l_display(dir, info);
        }
        dir = readdir(d);
    }
    closedir(d);
    return (0);
}
