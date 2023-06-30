/*
** EPITECH PROJECT, 2022
** my_strcmp
** File description:
** task06
*/

#include "duo.h"

static int compute_len(char const *s)
{
    int i = 0;

    while (s[i] != '\0') {
        i++;
    }
    return (i);
}

static int my_loop(char const *s1 , char const *s2 , int i)
{
    while (s1[i] != '\0' && s2[i] != '\0') {
        if (s1[i] == s2[i]) {
            i++;
            continue;
        }
        if (s1[i] < s2[i]) {
            return (-1);
        } else {
            return (1);
        }
        i++;
    }
    return (0);
}

int my_strcmp(char const *s1 , char const *s2)
{
    int i = 0;
    int c = 0;
    int len1 = compute_len(s1);
    int len2 = compute_len(s2);

    if (len1 == len2) {
        c = my_loop(s1 , s2 ,i);
        return (c);
    } else if (len1 < len2) {
        return (-1);
    } else {
        return (1);
    }
}
