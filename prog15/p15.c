/*
============================================================================
Name : prog15.c
Author : Ketki Kerkar
Description :Write a simple program to send some data from parent to the child process.
Date: 5th October, 2023.
============================================================================
*/
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
        char buff[80];
        int fd[2];
        pipe(fd);
        if(fork())
        {
                close(fd[0]);
                printf("Enter message to the child: ");
                scanf(" %[^\n]",buff);
                write(fd[1],buff,sizeof(buff));
        }
        else
        {
                close(fd[1]);
                read(fd[0],buff,sizeof(buff));
                printf("Message from parent: %s\n",buff);
        }
        wait(0);
}
