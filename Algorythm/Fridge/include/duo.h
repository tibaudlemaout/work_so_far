/*
** EPITECH PROJECT, 2023
** duo
** File description:
** duo header
*/

#ifndef DUO_H_
    #define DUO_H_

typedef struct fridge_s {
    int tomato;
    int dough;
    int onion;
    int pasta;
    int olive;
    int pepper;
    int ham;
    int cheese;
} fridge_t;

//src

//src/lib
int my_put_nbr(int number);
int my_putchar(char c);
int my_putstr(char const *str);
int my_show_word_array(char * const *tab);
int my_strcmp(char const *s1 , char const *s2);
int my_strlen(char const *str);
int my_tablen(char **tab);
int is_int(char *str);
int char_in_int(char *str);
int is_int_modif(char *str);
int char_in_int_modif(char *str);

#endif /* !DUO_H_ */
