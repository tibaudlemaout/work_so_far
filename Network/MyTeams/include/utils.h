/*
** EPITECH PROJECT, 2024
** Network_Programming
** File description:
** utils
*/

#ifndef UTILS_H_
    #define UTILS_H_
    #include "struct.h"

bool is_number(char *str);
void perror_84(const char *str);
char *get_next_line(const int fd);
char **split_str_quot(const char *str, char **tab, int *);
char **split_str_client(const char *str, char **tab, int *);
void free_array(char **array, int len);
char *my_calloc(int size);
char *itoa(int nb);

#endif /* !UTILS_H_ */
