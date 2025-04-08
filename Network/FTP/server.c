/*
** EPITECH PROJECT, 2024
** Semester_3
** File description:
** server
*/
#include "include/myftp.h"

int dataSocket;
struct sockaddr_in dataAddress;

void handle_pasv(int clientSocket, struct sockaddr_in* serverAddress)
{
    char response[256];
    dataSocket = socket(AF_INET, SOCK_STREAM, 0);
    socklen_t dataAddressLen = sizeof(dataAddress);
    int dataPort = ntohs(dataAddress.sin_port);

    memset(&dataAddress, 0, sizeof(dataAddress));
    dataAddress.sin_family = AF_INET;
    dataAddress.sin_addr.s_addr = INADDR_ANY;
    bind(dataSocket, (struct sockaddr*)&dataAddress, sizeof(dataAddress));
    getsockname(dataSocket, (struct sockaddr*)&dataAddress, &dataAddressLen);
    listen(dataSocket, 1);
    snprintf(response, sizeof(response), "227 Entering Passive Mode (%s,%d,%d).\r\n",
             inet_ntoa(serverAddress->sin_addr),
             (dataPort >> 8) & 0xFF, dataPort & 0xFF);
    write(clientSocket, response, strlen(response));
}

void process_ftp_command(int clientSocket, const char* command,
    struct sockaddr_in* serverAddress)
{
    if (strncmp(command, "USER", 4) == 0) {
        printf("Received USER command.\n");
        const char* response = "331 User name okay, need password.\r\n";
        write(clientSocket, response, strlen(response));
    } else if (strncmp(command, "PASS", 4) == 0) {
        printf("Received PASS command.\n");
        const char* response = "230 User logged in, proceed.\r\n";
        write(clientSocket, response, strlen(response));
    } else if (strncmp(command, "CWD", 3) == 0) {
        const char* response = "250 Directory changed.\r\n";
        write(clientSocket, response, strlen(response));
    } else if (strncmp(command, "PASV", 4) == 0) {
        handle_pasv(clientSocket, serverAddress);
    } else {
        const char* response = "500 Syntax error, command unrecognized.\r\n";
        write(clientSocket, response, strlen(response));
    }
}

// void setup_server(struct sockaddr_in *serverAddress, int serverSocket,
//     char **argv, char *anonymousPath)
// {
//     serverAddress->sin_family = AF_INET;
//     serverAddress->sin_addr.s_addr = INADDR_ANY;
//     serverAddress->sin_port = htons(atoi(argv[1]));

//     if (bind(serverSocket, (struct sockaddr *)serverAddress, sizeof(*serverAddress)) == -1) {
//         perror("Bind failed");
//         close(serverSocket);
//         exit(84);
//     }
//     if (listen(serverSocket, 10) == -1) {
//         perror("Listen failed");
//         close(serverSocket);
//         exit(84);
//     }
//     chdir(anonymousPath);
//     printf("Server listening on IP address: %s\n", inet_ntoa(serverAddress->sin_addr));
//     printf("Server listening on port %d...\n", ntohs(serverAddress->sin_port));
// }

// void run_server(int serverSocket, fd_set *masterfds, int *maxfd,
//     int *clientSockets, struct sockaddr_in *serverAddress)
// {
//     fd_set readfds;

//     while (1) {
//         readfds = *masterfds;
//         if (select(*maxfd + 1, &readfds, NULL, NULL, NULL) == -1) {
//             perror("Select failed");
//             exit(84);
//         }
//         if (FD_ISSET(serverSocket, &readfds)) {
//             accept_client(serverSocket, masterfds, maxfd, clientSockets);
//         }
//         for (int i = 0; i < 10; ++i) {
//             if (clientSockets[i] != -1 && FD_ISSET(clientSockets[i],
//                 &readfds)) {
//                 handle_client_or_data(clientSockets[i], dataSocket, masterfds,
//                     serverAddress);
//             }
//         }
//     }
// }

// int main(int argc, char **argv)
// {
//     struct sockaddr_in serverAddress;
//     int serverSocket = socket(AF_INET, SOCK_STREAM, 0);
//     socklen_t serverAddrLen = sizeof(serverAddress);
//     int clientSockets[10];
//     fd_set readfds;
//     fd_set masterfds;
//     int maxfd;

//     if (serverSocket == -1) {
//         perror("Socket creation failed");
//         exit(84);
//     }
//     setup_server(&serverAddress, serverSocket, argv, argv[3]);
//     FD_ZERO(&masterfds);
//     FD_SET(serverSocket, &masterfds);
//     maxfd = serverSocket;
//     for (int i = 0; i < 10; ++i)
//         clientSockets[i] = -1;
//     run_server(serverSocket, &masterfds, &maxfd, clientSockets,
//         &serverAddress);
//     close(serverSocket);
//     return (0);
// }

void setup_server(Server_t *server, char **argv)
{
    server->address.sin_family = AF_INET;
    server->address.sin_addr.s_addr = INADDR_ANY;
    server->address.sin_port = htons(atoi(argv[1]));

    if (bind(server->socket, (struct sockaddr *)&server->address,
        sizeof(server->address)) == -1) {
        perror("Bind failed");
        close(server->socket);
        exit(84);
    }
    if (listen(server->socket, 10) == -1) {
        perror("Listen failed");
        close(server->socket);
        exit(84);
    }
    chdir(argv[3]);
    strcpy(server->anonymousPath, argv[3]);
    printf("Server listening on IP address: %s\n",
        inet_ntoa(server->address.sin_addr));
    printf("Server listening on port %d...\n",
        ntohs(server->address.sin_port));
    FD_ZERO(&server->masterfds);
    FD_SET(server->socket, &server->masterfds);
    server->maxfd = server->socket;
}

void run_server(Server_t *server, Client_t *clients) {
    fd_set readfds;

    while (1) {
        readfds = server->masterfds;
        if (select(server->maxfd + 1, &readfds, NULL, NULL, NULL) == -1) {
            perror("Select failed");
            exit(84);
        }
        if (FD_ISSET(server->socket, &readfds))
            accept_client(server, clients);
        for (int i = 0; i < 10; ++i) {
            if (clients[i].socket != -1 && FD_ISSET(clients[i].socket, &readfds))
                handle_client_or_data(server, &clients[i], i);
        }
    }
}

int main(int argc, char **argv)
{
    Server_t server;
    Client_t clients[10];
    server.socket = socket(AF_INET, SOCK_STREAM, 0);

    if (server.socket == -1) {
        perror("Socket creation failed");
        exit(84);
    }
    setup_server(&server, argv);
    run_server(&server, clients);
    close(server.socket);
    return 0;
}
