/*
** EPITECH PROJECT, 2024
** B-NWP-400-NAN-4-1-myteams-thomas.cluseau
** File description:
** client_start
*/
#include "../include/client.h"
#include "../include/utils.h"

int start_client(char *ip, int port)
{
    client_t *client_str = init_client(client_str);
    struct hostent *info;
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in servaddr = {0};

    if ((info = gethostbyname(ip)) == NULL)
        perror_84("invalid ip");
    servaddr.sin_addr.s_addr = inet_addr(ip);
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(port);
    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) != 0)
        perror_84("connect()");
    loop_client(sockfd, client_str);
    free(client_str);
    return (0);
}

static void help(void)
{
    printf("USAGE: ./myteams_cli ip port\n\n  \
    ip   is the server ip address on which the server socket listens.\n  \
    port is the port number on which the server socket listens\n");

    return;
}

int main(int ac, char **av)
{
    if (ac == 3) {
        if (ac == 2 && !strcmp(av[1], "-help")) {
            help();
            return (0);
        }
        if (is_number(av[2]) == true ) {
            return start_client(av[1], atoi(av[2]));
        } else {
            printf("invalid port\n");
            return (84);
        }
    }
    return (84);
}