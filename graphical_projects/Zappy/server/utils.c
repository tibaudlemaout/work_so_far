/*
** EPITECH PROJECT, 2024
** Appzy
** File description:
** map creation
*/

/**
 * @file utils.c
 * @brief File containing diverse function for arguments and incoming commands
*/

#include "include/zappy_server.h"

/**
 * @brief Function that applies the content of a command inside an array
 * @param args pointer to an array for storage of every element fo the command
 * @param command the given command
*/
void create_args_list(char ***args, char *command)
{
    char *separator = " ";
    char *token = strtok(command, separator);
    char **command_arr = malloc(sizeof(char *));

    if (command_arr == NULL)
        show_error("args malloc fail\n");
    command_arr[0] = NULL;
    for (int i = 0; token != NULL; i++) {
        command_arr = realloc(command_arr, sizeof(char *) * (i + 2));
        if (command_arr == NULL)
            show_error("args realloc fail\n");
        command_arr[i] = strdup(token);
        command_arr[i + 1] = NULL;
        token = strtok(NULL, separator);
    }
    *args = command_arr;
}

/**
 * @brief Function that counts the number of arguments in a given array
 * @param args an array in which are stored every element of a command
 * @return the number of elements in the array
*/
size_t count_args(char **args)
{
    size_t count = 0;

    if (args == NULL)
        return count;
    for (; args[count]; count++);
    return count;
}

/**
 * @brief Function that checks if a command is empty or not
 * @param cmd the given command to analyze
 * @return if the command is empty or not
*/
bool verify_empty(char *cmd)
{
    bool empty = true;

    for (size_t i = 0; cmd[i]; i++) {
        if (cmd[i] != ' ') {
            empty = false;
            break;
        }
    }
    return empty;
}

/**
 * @brief Function that concatenates a string in another
 * @param dest the destination pointer, on which the string will be written
 * @param src the string to copy on the pointer
*/
void append_to_string(char *dest, char *src)
{
    memmove(dest + strlen(dest), src, strlen(src) + 1);
}

/**
 * @brief Function that empties a buffer (without freeing it) on a
 *  given number of characters
 * @param buffer a pointer on the string to empty
 * @param len the number of character to set to '\0'
*/
void reset_buffer(char *buffer, int len)
{
    for (int i = 0; i < len; i++)
        buffer[i] = '\0';
}
