/*
============================================================================
Name : 34bs.c
Author : Ketki Kerkar
Description : Write a program to create a concurrent server.
b. use pthread_create
Date: 11th , Oct 2023
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <netinet/in.h>
#include <sys/socket.h>

#define PORT 8080
#define MAX_CLIENTS 5

void *client_handler(void *client_socket_ptr) {
    int client_socket = *(int *)client_socket_ptr;
    char buffer[1024];
    int n;

    while (1) {
        n = read(client_socket, buffer, sizeof(buffer));
        if (n <= 0) {
            close(client_socket);
            pthread_exit(NULL);
        }
        buffer[n] = '\0';
        printf("\n");
        printf("\nReceived from client:%s\n", buffer);
        write(client_socket, "Message received.", 18);
    }
}

int main() {
    int server_socket, client_socket;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_len = sizeof(client_addr);
    pthread_t threads[MAX_CLIENTS];

    // Create a socket
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        perror("\nSocket creation failed\n");
        exit(EXIT_FAILURE);
    }

    // Initialize the server address structure
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    // Bind the socket
    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr) ) < 0) {
        perror("\nBinding failed\n");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(server_socket, 5) < 0) {
        perror("\nListening failed\n");
        exit(EXIT_FAILURE);
    }

    printf("\nServer listening on port %d\n", PORT);

    int i = 0;
    while (1) {
        client_socket = accept(server_socket, (struct sockaddr *)&client_addr, &client_len);

        if (client_socket < 0) {
            perror("\nAcceptance failed\n");
            exit(EXIT_FAILURE);
        }

        if (i < MAX_CLIENTS) {
            pthread_create(&threads[i], NULL, client_handler, &client_socket);
            i++;
        } else {
            printf("\nMaximum number of clients reached. Connection rejected.\n");
            close(client_socket);
        }
    }

    close(server_socket);
    return 0;
}

