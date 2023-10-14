/*
============================================================================
Name : 34bc.c
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
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <fcntl.h>
#define PORT 8080

int main() {
    int sock = 0;
    struct sockaddr_in server;
    char *hello = "\n Hello from client\n\n";
    char buffer[1024] = {0};

    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("\nSocket creation error\n");
        exit(EXIT_FAILURE);
    }

    server.sin_family = AF_INET;
    server.sin_port = htons(PORT);

    if (inet_pton(AF_INET, "127.0.0.1", &server.sin_addr) <= 0) {
        perror("Invalid address/ Address not supported");
        exit(EXIT_FAILURE);
    }

    if (connect(sock, (struct sockaddr *)&server, sizeof(server)) < 0) {
        perror("Connection Failed");
        exit(EXIT_FAILURE);
    }

    send(sock, hello, strlen(hello), 0);
    printf("\nHello message sent to the client\n");
    read(sock, buffer, 1024);
    printf("Server: %s\n", buffer);
    getchar();
    return 0;
}



