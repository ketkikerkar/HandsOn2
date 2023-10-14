/*
============================================================================
Name : prog22.c
Author : Ketki Kerkar
Description :Write a program to wait for data to be written into FIFO within 10 seconds, use select
system call with FIFO.
Date: 6th October, 2023.
============================================================================
*/
#include<stdio.h>
#include<fcntl.h>
#include<string.h>
#include<sys/stat.h>
#include<unistd.h>
#include<sys/types.h>

int main()
{
int fd;
char * myfifo="myfifo";
mkfifo(myfifo,0666);
char arr[200];
fd_set rfds;
	struct timeval tv;
	int retval;
	FD_ZERO(&rfds);
	FD_SET(0,&rfds);
	tv.tv_sec=10;
	tv.tv_usec=0;
	retval=select(1,&rfds,NULL,NULL,&tv);
	
	if(retval==-1) perror("ERROR Occurred");
	else if(retval) {
	//printf("Data is available for reading within 10 seconds\n");
	


while(1){
fd=open(myfifo,O_WRONLY);
printf("Write the message:");
scanf("%[^\t\n]s",arr);
write(fd,arr,strlen(arr)+1);
close(fd);
}}
else printf("Data is not available for reading within 10 seconds\n");
return 0;
}
