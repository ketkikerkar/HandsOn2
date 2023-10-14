/*
============================================================================
Name : 32d.c
Author : Ketki Kerkar
Description : 32. Write a program to implement semaphore to protect any critical section.
d. remove the created semaphore
Date: 11th , Oct 2023
============================================================================
*/
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <stdio.h>
#include <unistd.h>

int main()
{	
	int semid;
	printf("Enter the ID of Semaphore you want to remove :\n");
	scanf("%d",&semid);

	int ret = semctl(semid,0,IPC_RMID);
	if(ret==-1)
	{
		perror("SEMCTL ERROR");
		return -1;
	}
	else
		printf("Semaphore with ID %d is removed successfully!!!\n",semid);
	return 0;
}



