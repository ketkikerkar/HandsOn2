/*
============================================================================
Name : 32b.c
Author : Ketki Kerkar
Description : 32. Write a program to implement semaphore to protect any critical section.
b. protect shared memory from concurrent write access
Date: 11th , Oct 2023
============================================================================
*/
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/shm.h>
#include <string.h>

struct sembuf p = { 0, -1, SEM_UNDO};//down operation
struct sembuf v = { 0, +1, SEM_UNDO};//up operation

int main()
{
	int shmid = shmget((key_t)3333,1024,IPC_CREAT|0666); //create/retrieve a shared memory segment of 1024 bytes
	if(shmid==-1)
	{
		perror("SHMGET ERROR");
		return -1;
	}
	char *ptr = (char *)shmat(shmid,NULL,0); //NULL allows the system to choose address on its own
	if(ptr==(char *)-1)
	{
		perror("SHMAT ERROR");
		return -1;
	}
	else
		printf("Shared Memory attached at address %p\n",ptr);
	
	int semid_shm = semget((key_t)6789,1,IPC_CREAT|0666);
	if(semid_shm==-1)
	{
		perror("SEMGET ERROR");
		return -1;
	}
	

	printf("Waiting to write data to shared memory....\n");
	semop(semid_shm,&p,1); //lock shared memory
	printf("DATA IN SHARED MEMORY : %s\n",ptr);//read data from shm
	printf("Enter the data you want to write on Shared Memory:\n");
	scanf("%s",ptr);
	printf("Data written on Shared Memory: %s\n",ptr);
	semop(semid_shm,&v,1); //release shared memory
	printf("Detaching the Shared Memory..\n");
	shmdt(ptr);
	return 0;

}
