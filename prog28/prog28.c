/*
============================================================================
Name : prog28.c
Author : Ketki Kerkar
Description :Write a program to change the existing message queue permission. (use msqid_ds structure)
Date: 8th October, 2023.
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
	struct msqid_ds buf;
	int mqid;
	key = ftok("..", 'a');
        mqid = msgget(key,IPC_CREAT|0666);
        msgctl(mqid,IPC_STAT,&buf);
        printf("Access Permission:%o",buf.msg_perm.mode);
        buf.msg_perm.mode=0744;
         
        msgctl(mqid,IPC_SET,&buf);
        msgctl(mqid,IPC_STAT,&buf);
        printf("\n Updated Access Permission:%o",buf.msg_perm.mode);
        
}
