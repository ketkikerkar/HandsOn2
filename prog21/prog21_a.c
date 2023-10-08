/*
============================================================================
Name : prog21_a.c
Author : Ketki Kerkar
Description :Write two programs so that both can communicate by FIFO -Use two way communications.
Date: 8th October, 2023.
============================================================================
*/
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/wait.h>

int main()
{
	int fd,fd2;
	char buff[80], buff2[80];
	fd2=open("fifo1",O_RDONLY);
	read(fd2, &buff2, sizeof(buff2));
	printf("The text from program2: %s\n", buff2);
	fd=open("fifo2", O_WRONLY);
	printf("Enter message from program1:");
	scanf(" %[^\n]", buff);
	write(fd, &buff, sizeof(buff));
	
}
