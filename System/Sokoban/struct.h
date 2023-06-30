/*
** EPITECH PROJECT, 2022
** struct
** File description:
** cg
*/

#ifndef STRUCT_H
    #define STRUCT_H

    typedef struct MAP{
        char **tab;
        int p_ypos;
        int p_xpos;
    } MAP_S;

    typedef struct INIT{
        MAP_S copy_tab;
        MAP_S empty_tab;
        int file_desc;
        char *filepath;
        int end_value;
        int lose_value;
        int win_value;
        int storage;
        int boxes;
        int buff_layer;
    } INIT_S;

#endif /* !STRUCT_H */
