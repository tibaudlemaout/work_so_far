/*
** EPITECH PROJECT, 2023
** EPITECH
** File description:
** struct
*/

#ifndef STRUCT_H_
    #define STRUCT_H_

    typedef struct global{
        char **c_env;
        char **c_path;
        char **tab;
        char *path_buff;
        char *pwd;
        char *oldpwd;
        int past_status;
        int pid;
        int spaces;
        int size;
    } global_t;

    typedef struct builtin{
        char *name;
        char *man;
        int (*f_builtin)(global_t *);
    } builtin_t;

#endif /* !STRUCT_H_ */
