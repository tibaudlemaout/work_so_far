/*
** EPITECH PROJECT, 2024
** B-NWP-400-NAN-4-1-myteams-thomas.cluseau
** File description:
** client_loop
*/
#include "../include/client.h"
#include "../include/utils.h"
#include "../libs/myteams/logging_client.h"
#include <signal.h>
#include <errno.h>

static void handle_signal_action(int sig_number)
{
    run = 0;
}

client_t *init_client(client_t *client)
{
    client = malloc(sizeof(client_t));
    client->login = false;
    client->user_name = NULL;
    client->uuid = NULL;
    return client;
}

static void read_client(int sockfd, client_t *client)
{
    int len = 0;
    char buffer[1024];

    if ((len = recv(sockfd, buffer, 1024 - 1, 0)) < 0)
        perror_84("recv()");
    buffer[len] = 0;
    if (!len) {
        close(sockfd);
        exit(0);
    }
    if (!strcmp(buffer, "end_client")) {
        if (client->login != false)
            client_event_logged_out(client->uuid, client->user_name);
        close(client->sokfd);
        free(client);
        exit(0);
    }
    command_management(buffer, client);
}

void loop_client(int sockfd, client_t *client)
{
    fd_set fds;
    client->sokfd = sockfd;

    signal(SIGINT, handle_signal_action);
    for (;run != 0;) {
        FD_ZERO(&fds);
        FD_SET(STDIN_FILENO, &fds);
        FD_SET(sockfd, &fds);
        if (select(sockfd + 1, &fds, NULL, NULL, NULL) == -1)
            if (errno == EINTR)
                continue;
            else
                perror_84("select()");
        if (FD_ISSET(STDIN_FILENO, &fds))
            send_client(client, get_next_line(0));
        else if (FD_ISSET(sockfd, &fds))
            read_client(sockfd, client);
    }
    printf("\n");
    logout_client(client, "/logout");
}
