/*
** EPITECH PROJECT, 2024
** Semester_3
** File description:
** client
*/

#include <stdio.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <unistd.h>
#include <string.h>

// int main(int argc, char *argv[])
// {
//     int clientSocket = socket(AF_INET, SOCK_STREAM, 0);
//     struct sockaddr_in serverAddress;
//     char buffer[1024];
//     ssize_t bytesRead = 0;

//     if (clientSocket == -1) {
//         perror("Socket creation failed");
//         exit(84);
//     }
//     serverAddress.sin_family = AF_INET;
//     serverAddress.sin_port = htons(atoi(argv[2]));
//     serverAddress.sin_addr.s_addr = inet_addr(argv[1]);
//     if (connect(clientSocket, (struct sockaddr*)&serverAddress,
//         sizeof(serverAddress)) == -1) {
//         perror("Connection failed");
//         exit(84);
//     }
//     printf("Connected to the server.\n");
//     bytesRead = read(clientSocket, buffer, sizeof(buffer)-1);
//     if (bytesRead == -1) {
//         perror("Read failed");
//     } else {
//         buffer[bytesRead] = '\0';
//         printf("Server said: %s\n", buffer);
//     }
//     return 0;
// }

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 1024

void send_command(int socket, const char* command)
{
    char buffer[BUFFER_SIZE];

    sprintf(buffer, "%s\r\n", command);
    write(socket, buffer, strlen(buffer));
}

void read_response(int socket)
{
    char buffer[BUFFER_SIZE];
    ssize_t bytesRead = read(socket, buffer, sizeof(buffer) - 1);

    if (bytesRead > 0) {
        buffer[bytesRead] = '\0';
        printf("Response from server:%s", buffer);
    } else {
        perror("Error reading from server");
    }
}

int main(int argc, char** argv)
{
    const char* server_ip = argv[1];
    const int server_port = atoi(argv[2]);
    int client_socket = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in server_address;
    char* command = NULL;
    size_t len = 0;
    ssize_t read;

    if (argc != 3) {
        fprintf(stderr, "Usage: %s <server_ip> <server_port>\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    if (client_socket == -1) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = inet_addr(server_ip);
    server_address.sin_port = htons(server_port);
    if (connect(client_socket, (struct sockaddr*)&server_address, sizeof(server_address)) == -1) {
        perror("Connection failed");
        close(client_socket);
        exit(EXIT_FAILURE);
    }
    printf("Connected to FTP server\n");
    while (1) {
        printf("Enter FTP command (or 'QUIT' to exit): ");
        read = getline(&command, &len, stdin);
        if (read == -1) {
            perror("Error reading input");
            break;
        }
        command[strcspn(command, "\n")] = '\0';
        if (strcmp(command, "QUIT") == 0)
            break;
        send_command(client_socket, command);
        read_response(client_socket);
    }
    free(command);
    close(client_socket);
    return 0;
}
