/*
** EPITECH PROJECT, 2023
** EPITECH
** File description:
** minishell_1
*/
#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <sys/wait.h>
#include "./struct.h"

#ifndef MINISHELL_1_H_
    #define MINISHELL_1_H_

int cond_printf(const char *format, int i, va_list list);
int my_printf(const char *format, ...);
void my_putchar(char c);
int my_strlen(char const *str);
int bsq_strlen(char const *str);
int my_put_nbr(int nb);
int my_putstr(char const *str);
int my_get_nbr(char *str);
int my_strcmp(char *str1, char *str2);
char *my_strcpy(char *dest, char const *src);
char *my_strdup(char *str);
void print_arg(char *arg, global_t *data);
void copy_env(global_t *data, char **env);
void free_ongoing(global_t *data, char *buff);
void free_c_env(global_t *data);
int is_builtin(global_t *data);
int new_exit(global_t *data);
int new_cd(global_t *data);
int new_env(global_t *data);
int new_setenv(global_t *data);
int new_unsetenv(global_t *data);
void get_path(global_t *data, char **env);
int search_in_path(global_t *data);
int path_or_absolute(global_t *data);
int search_in_path(global_t *data);
void handle_child(global_t *data, char *exec);
char *save_pwd(char *c_env, char *pwd);
char *save_pre_dir(char *pwd);
void change_env_cd(global_t *data, char *pwd);
int create_new_env(global_t *data, char *env_name, int argc);
int set_path_buff(char *path, char *exec, global_t *data);
int create_own_path(global_t *data, int index, int found);
char *retrieve_home(global_t *data, char *pwd);
char *retrieve_tab_1(global_t *data, char *pwd);
char *pre_dir(global_t *data, char *pwd);

#endif /* !MINISHELL_1_H_ */
