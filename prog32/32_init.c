/*
============================================================================
Name : 32_init.c
Author : Ketki Kerkar
Description : 32. Write a program to implement semaphore to protect any critical section.
a. rewrite the ticket number creation program using semaphore
b. protect shared memory from concurrent write access
c. protect multiple pseudo resources ( may be two) using counting semaphore
d. remove the created semaphore
Date: 11th , Oct 2023
============================================================================
*/
//This program initialises the required semaphores for a,b,c part of the ques 32. Run it before other program of question 32
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
union semaphore{
    int val;
    struct semid_ds *buf;
    unsigned short  *array;
};


int main()
{	
	//initialise the ticket file
	struct ticket
	{
		int ticket_no;
	}t;
	int fd = open("ticketNumber.txt",O_RDWR|O_CREAT,0666);
	if(fd==-1)
	{
		perror("file couldnt be opened");
		return 1;
	}
	
	t.ticket_no = 0; //initially ticket no =0
	int ret=write(fd,&t,sizeof(t));	
	if(ret==-1)
	{
		perror("Error while writing !!\n");
		
	}
	close(fd);

//create and initialise the semaphore for ques 32a

	int semid = semget((key_t)8888,1,IPC_CREAT|0666);
	if(semid==-1)
	{
		perror("Error while creation of semaphore \n");
		return -1;
	}
	union semaphore u;
  	u.val = 1; //Initialise with 1

   	semctl(semid,0,SETVAL,u);

//create and initialise the semaphore for ques 32b

	int semid_shm = semget((key_t)6789,1,IPC_CREAT|0666);
	if(semid_shm==-1)
	{
		perror("Error while creation of semaphore \n");
		return -1;
	}
	union semaphore u_shm;
  	u_shm.val = 1; //Initialise with 1

  	semctl(semid_shm,0,SETVAL,u_shm);
 
//create and initialise the semaphore for ques 32c

	int semid_cs = semget((key_t)1111,1,IPC_CREAT|0666);
	if(semid_cs==-1)
	{
		perror("SEMGET ERROR");
		return -1;
	}
	union semaphore u_cs;
  	u_cs.val = 2; //Initialise with 2(counting semaphore)

    semctl(semid_cs,0,SETVAL,u_cs);
	return 0;
}
