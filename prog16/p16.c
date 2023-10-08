/*
============================================================================
Name : prog16.c
Author : Ketki Kerkar
Description :Write a program to send and receive data from parent to child vice versa. Use two way
communication.
Date: 5th October, 2023.
============================================================================
*/
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
        char buff[80];//="Hello this is parent";
        char buff2[80];//ello this is child";
        int fd[2];
        int fd2[2];
        pipe(fd);
        pipe(fd2);
        if(fork())
        {
                close(fd[0]);
                printf("Enter message to the child: ");
                scanf(" %[^\n]",buff);
                write(fd[1],buff,sizeof(buff));
                
                close(fd2[1]);
                
                read(fd2[0],buff2,sizeof(buff2));
                printf("Message from child: %s\n",buff2);
                
        }
        else
        {
                close(fd[1]);
                read(fd[0],buff,sizeof(buff));
                printf("Message from parent: %s\n",buff);
                close(fd2[0]);
                
                printf("Enter message to the parent: ");
                scanf(" %[^\n]",buff2);
                write(fd2[1],buff2,sizeof(buff2));
        }
        wait(0);
}

