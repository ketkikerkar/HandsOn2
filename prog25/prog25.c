/*
============================================================================
Name : prog25.c
Author : Ketki Kerkar
Description :25. Write a program to print a message queue's (use msqid_ds and ipc_perm structures)
a. access permission
b. uid, gid
c. time of last message sent and received
d. time of last change in the message queue
d. size of the queue
f. number of messages in the queue
g. maximum number of bytes allowed
h. pid of the msgsnd and msgrcv
Date: 9th October, 2023.
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <time.h>
#include <unistd.h>

int main() {
    int msqid;
    struct msqid_ds info;
    key_t key;
    key = ftok("/tmp", 'A');
    msqid = msgget(key, IPC_CREAT | 0666);

    if (msqid == -1) {
        perror("msgget");
        exit(1);
    }
    if (msgctl(msqid, IPC_STAT, &info) == -1) {
        perror("msgctl");
        exit(1);
    }
    printf("Access permissions: %o\n", info.msg_perm.mode);
    printf("UID: %d, GID: %d\n", info.msg_perm.uid, info.msg_perm.gid);
    printf("Time of last message sent: %s", ctime(&info.msg_stime));
    printf("Time of last message received: %s", ctime(&info.msg_rtime));
    printf("Time of last change: %s", ctime(&info.msg_ctime));
    printf("Size of the queue: %ld bytes\n", info.msg_cbytes);
    printf("Number of messages in the queue: %lu\n", info.msg_qnum);
    printf("Maximum number of bytes allowed: %lu\n", info.msg_qbytes);
    printf("PID of last msgsnd: %d\n", info.msg_lspid);
    printf("PID of last msgrcv: %d\n", info.msg_lrpid);

    return 0;
}
