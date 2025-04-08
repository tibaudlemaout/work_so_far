/*
** EPITECH PROJECT, 2024
** Semester_3
** File description:
** commands
*/
#include "../include/client.h"
#include "../include/server.h"

void help(void)
{
    printf("Available commands:\n");
    printf("/help : Show help\n");
    printf("/login [\"user_name\"] : Set the user_name used by client\n");
    printf("/logout : Disconnect the client from the server\n");
    return;
}

void login(int server_socket, char *username)
{
    char login_command[MAX_COMMAND_LENGTH];
    sprintf(login_command, "/login \"%s\"", username);
    send_command(server_socket, login_command);
    receive_response(server_socket);
}

void logout(int server_socket)
{
    send_command(server_socket, "/logout");
    receive_response(server_socket);
    close(server_socket);
    exit(0);
}
