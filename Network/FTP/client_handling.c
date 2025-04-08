/*
** EPITECH PROJECT, 2024
** Network_Programming
** File description:
** client_handling
*/
#include "include/myftp.h"

void handle_client(Server_t *server, Client_t *client)
{
    char buffer[1024];
    ssize_t bytesRead;
    const char* welcomeMessage = "220 Welcome to FTP server\r\n";

    write(client->socket, welcomeMessage, strlen(welcomeMessage));
    while ((bytesRead = read(client->socket, buffer, sizeof(buffer))) > 0) {
        buffer[bytesRead] = '\0';
        process_ftp_command(client->socket, buffer, &server->address);
    }
    close(client->socket);
}

// void accept_client(int serverSocket, fd_set *masterfds, int *maxfd,
//     int *clientSockets)
// {
//     int clientSocket = accept(serverSocket, NULL, NULL);
//     const char *initialResponse = "220 Service ready for new user.\r\n";

//     if (clientSocket == -1) {
//         perror("Accept failed");
//         close(serverSocket);
//         exit(84);
//     }
//     printf("Connection accepted from client %d\n", clientSocket);
//     write(clientSocket, initialResponse, strlen(initialResponse));
//     FD_SET(clientSocket, masterfds);
//     if (clientSocket > *maxfd)
//         *maxfd = clientSocket;
//     for (int i = 0; i < 10; ++i) {
//         if (clientSockets[i] == -1) {
//             clientSockets[i] = clientSocket;
//             break;
//         }
//     }
// }

// void handle_client_or_data(int clientSocket, int dataSocket, fd_set *masterfds,
//     struct sockaddr_in *serverAddress)
// {
//     if (clientSocket != dataSocket) {
//         handle_client(clientSocket, serverAddress);
//     } else {
//         printf("NOT PASV, still need to implement\n");
//     }
//     FD_CLR(clientSocket, masterfds);
//     close(clientSocket);
// }


void accept_client(Server_t *server, Client_t *clients)
{
    int clientSocket = accept(server->socket, NULL, NULL);
    const char *initialResponse = "220 Service ready for new user.\r\n";

    if (clientSocket == -1) {
        perror("Accept failed");
        close(server->socket);
        exit(84);
    }

    printf("Connection accepted from client %d\n", clientSocket);
    write(clientSocket, initialResponse, strlen(initialResponse));

    FD_SET(clientSocket, &server->masterfds);
    if (clientSocket > server->maxfd) {
        server->maxfd = clientSocket;
    }

    for (int i = 0; i < 10; ++i) {
        if (clients[i].socket == -1) {
            clients[i].socket = clientSocket;
            break;
        }
    }
}

void handle_client_or_data(Server_t *server, Client_t *clients, int idx)
{
    if (clients->socket != clients->dataSocket) {
        handle_client(server, &clients[idx]);
    } else {
        printf("NOT PASV, still need to implement\n");
    }

    FD_CLR(clients->socket, &server->masterfds);
    close(clients->socket);
}
