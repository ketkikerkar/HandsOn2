/*
============================================================================
Name : prog22r.c
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
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
int main(){
int fd;
char buff[80];

char arr[200];
fd=open("myfifo",O_RDONLY);
if(fd==-1){
perror("Error");
exit(EXIT_FAILURE);

}
read(fd,buff,sizeof(buff));
printf("The text from fifo is:%s",buff);
return 0;}
