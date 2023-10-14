/*
============================================================================
Name : 27a.c
Author : Ketki Kerkar
Description : Write a program to receive messages from the message queue.
a. with 0 as a flag
Date: 10th , Oct 2023
============================================================================
*/

#include<stdio.h>
#include<sys/msg.h>
#include<sys/ipc.h>
#include<stdlib.h>
struct msg {
	long int m_type;
	char message[80];
} myq;
int main(void){
	key_t key;
	int mqid;
	key = ftok(".", 'a');
        mqid = msgget(key, 0);
        printf("Enter message type: ");
        scanf("%ld", &myq.m_type);
        int rec = msgrcv(mqid, &myq, sizeof(myq.message), myq.m_type,0|MSG_NOERROR);
        if (rec == -1)
   		exit(-1);
	printf("Message: %s\n", myq.message);
}
