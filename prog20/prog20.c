/*
============================================================================
Name : prog20.c
Author : Ketki Kerkar
Description :Write two programs so that both can communicate by FIFO -Use one way communication.
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

fd=open(myfifo,O_WRONLY);
printf("Write the message:");
scanf("%[^\t\n]s",arr);
write(fd,arr,strlen(arr)+1);
close(fd);

return 0;
}
