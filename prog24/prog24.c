/*
============================================================================
Name : prog24.c
Author : Ketki Kerkar
Description :24.Write a program to create a message queue and print the key and message queue id.
Date: 9th October, 2023.
============================================================================
*/
#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>


int main(void)
{
    int msgid;
    key_t key;
    key = ftok(".", 'a');
    msgid = msgget(key, IPC_CREAT| IPC_EXCL| 0744);
    printf("Key value = %d\n", key);
    printf("Key value in hex = 0x%0x\n", key);
    printf("Message queue id = %d\n", msgid);
}
