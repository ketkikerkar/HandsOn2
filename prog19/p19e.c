/*
=======================================================================================================
Name : 19e.c
Author : Ketki Kerkar. 
Description : Create a FIFO file by
	      e. mkfifo library function
Date: 10 Oct 2023
======================================================================================================
*/
#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/stat.h>
int main(void){
	int f = mkfifo("myfifo", 0666);
	if(f<0){
		perror("Failed:");
	}
	else
		printf("File Created.\n");
	close(f);
}
