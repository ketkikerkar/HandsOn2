/*
============================================================================
Name : 32c.c
Author : Ketki Kerkar
Description : 32. Write a program to implement semaphore to protect any critical section.
c. protect multiple pseudo resources ( may be two) using counting semaphore
Date: 11th , Oct 2023
============================================================================
*/
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <stdio.h>
#include <unistd.h>

struct sembuf p = { 0, -1, SEM_UNDO};//down operation
struct sembuf v = { 0, +1, SEM_UNDO};//up operation

int main()
{
	int semid_cs = semget((key_t)1111,1,IPC_CREAT|0666);//using counting semaphores created in 32_init.c
	if(semid_cs==-1)
	{
		perror("SEMGET ERROR");
		return -1;
	}

	printf("Waiting to get resource...\n");
	semop(semid_cs,&p,1);//down
	printf("***Resource Allocated***\n");
	printf("Press Enter to release the resource:\n");
	getchar();
	semop(semid_cs,&v,1);//up
	printf("***Resource Released***\n");
	return 0;

}
// run ./a.out in 3 differnt terminal to check resources are allocated for 2 and 3rd waits
