/*
============================================================================
Name : prog26.c
Author : Ketki Kerkar
Description :Write a program to send messages to the message queue. Check $ipcs -q
Date: 9th October, 2023.
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <mqueue.h>

#define QUEUE_NAME "/my_message_queue"
#define MAX_MSG_SIZE 1024

int main() {
    mqd_t mq;
    struct mq_attr attr;
    char buffer[MAX_MSG_SIZE];

    // Set up the message queue attributes
    attr.mq_flags = 0;
    attr.mq_maxmsg = 10;  // Maximum number of messages in the queue
    attr.mq_msgsize = MAX_MSG_SIZE;
    attr.mq_curmsgs = 0;

    // Open or create the message queue
    mq = mq_open(QUEUE_NAME, O_WRONLY | O_CREAT, 0666, &attr);
    if (mq == (mqd_t)-1) {
        perror("mq_open");
        exit(1);
    }

    printf("Enter a message to send (Ctrl-D to exit):\n");

    while (fgets(buffer, MAX_MSG_SIZE, stdin) != NULL) {
        // Send the message to the message queue
        if (mq_send(mq, buffer, strlen(buffer), 0) == -1) {
            perror("mq_send");
            exit(1);
        }

        printf("Message sent: %s\n", buffer);

        printf("Enter a message to send (Ctrl-D to exit):\n");
    }

    // Close the message queue
    if (mq_close(mq) == -1) {
        perror("mq_close");
        exit(1);
    }

    return 0;
}
