/*
** EPITECH PROJECT, 2024
** Network_Programming
** File description:
** server_start
*/
#include "../include/server.h"
#include "../include/utils.h"

static int run_server(int sockfd, struct sockaddr_in *s_addr, int port)
{
    client_serv_t client_str[MAX_CLIENT];
    fd_set fds;
    int max_sd = sockfd;
    serv_t *serv;

    for (int i = 0; i < MAX_CLIENT; i++) {
        client_str[i].sockfd = 0;
    }
    if ((listen(sockfd, MAX_CLIENT)) != 0) {
        perror_84("listen()");
    }
    serv = init_server(sockfd, max_sd, fds, serv);
    signal(SIGPIPE, SIG_IGN);
    loop_server(client_str, serv);
    return (0);
}

int start_server(int port)
{
    struct sockaddr_in s_addr = {0};
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd == -1)
        perror_84("socket(): ");
    s_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    s_addr.sin_family = AF_INET;
    s_addr.sin_port = htons(port);
    if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR,
    &s_addr, sizeof(int)) == -1) {
        perror_84("setsockopt()");
    }
    if (bind(sockfd, (struct sockaddr *) &s_addr, sizeof(s_addr)) == -1) {
        perror_84("bind()");
    }
    run_server(sockfd, &s_addr, port);
    return (0);
}

static void display_help(void)
{
    printf("USAGE: ./myteams_server port\n\n  \
    port is the port number on which the server socket listens.\n");
    return;
}

int main(int argc, char **argv)
{
    int port = 0;

    if (argc == 2) {
        if (argv[1] == "-h")
            display_help();
        port = atoi(argv[1]);
        start_server(port);
        return (0);
    } else {
        return (84);
    }
}
