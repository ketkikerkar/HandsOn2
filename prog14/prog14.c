/*
============================================================================
Name : prog14.c
Author : Ketki Kerkar
Description :Write a simple program to create a pipe, write to the pipe, read from pipe and display on
the monitor.
Date: 8th October, 2023.
============================================================================
*/
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>

int main()
{
	int filedes[2];
	char buf[100];
	if(pipe(filedes)==-1)
	{
		exit(EXIT_FAILURE);
	}
	write(filedes[1],"Hello ",6);
	read(filedes[0],buf,6);
	printf("%s",buf);
	return 0;
}
