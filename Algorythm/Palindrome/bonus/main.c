/*
** EPITECH PROJECT, 2023
** B-SYN-200-NAN-2-1-palindrome-tibaud.le-maout
** File description:
** main
*/
#include "include/bonus.h"

static int i_spaces(const char *str, int i)
{
    int move = 0;

    while (str[i] == ' ') {
        i --;
        move ++;
    }
    return (move);
}

static int index_spaces(const char *str, int index)
{
    int move = 0;

    while (str[index] == ' ') {
        index ++;
        move ++;
    }
    return (move);
}

static int handle_spaces(const char *str, int index, int i, int move)
{
    if (str[index] == ' ') {
        move = index_spaces(str, index);
        index = index + move;
        return (index);
    }
    if (str[i] == ' ') {
        move = i_spaces(str, i);
        i = i - move;
        return (i);
    }
    return (0);
}

static int palindrome(const char *str)
{
    int index = 0;
    int i = strlen(str) - 1;
    int halfpoint = (strlen(str) / 2);
    int move = 0;

    while (index <= halfpoint && i >= halfpoint) {
        if (str[index] == ' ')
            index = handle_spaces(str, index, i, move);
        if (str[i] == ' ')
            i = handle_spaces(str, index, i, move);
        if (str[index] != str[i] && str[index] + 32 != str[i] &&
            str[index] - 32 != str[i])
            return (1);
        index ++;
        i --;
    }
    return (0);
}

int main(int argc, char **argv)
{
    if (argc != 2)
        return (84);
    if (palindrome(argv[1]) == 1) {
            printf("the string given is not a palindrome.\n");
            return (0);
    } else {
        printf("the string given is a palindrome.\n");
    }
    return (0);
}
