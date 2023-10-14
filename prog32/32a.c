/*
============================================================================
Name : 32a.c
Author : Ketki Kerkar
Description : 32. Write a program to implement semaphore to protect any critical section.
a. rewrite the ticket number creation program using semaphore
Date: 11th , Oct 2023
============================================================================
*/
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

struct sembuf p = { 0, -1, SEM_UNDO};//down operation
struct sembuf v = { 0, +1, SEM_UNDO};//up operation

int main()
{
	struct ticket
	{
		int ticketNumber;
	};
	struct ticket t;
	int fd=open("ticketNumber.txt",O_RDWR);
	if(fd==-1)
	{
		perror("OPEN ERROR");
		close(fd);
		return -1;
	}
	
	
	//Create/Retrieve a semaphore set
	int semid = semget((key_t)8888,1,IPC_CREAT|0666);//1 implies no. of semaphore in a set
	if(semid==-1)
	{
		perror("SEMGET ERROR");
		return -1;
	}
	printf("*****WAITING TO BOOK TICKETS*****\n");
	printf("*****BOOKING IN PROGRESS*****\n");
	semop(semid,&p,1);//acquire lock
	read(fd,&t,sizeof(t));
	
	t.ticketNumber++;//incrementing the current ticket number
	
	lseek(fd,-1*sizeof(t),SEEK_CUR);//updating the file pointer to the start
	write(fd,&t,sizeof(t));//updating file with new ticket number
	printf("Press Enter to book the ticket:\n");

	getchar();
	printf("YOUR TICKET NUMBER = %d\n",t.ticketNumber);
	semop(semid,&v,1);//release lock
	printf("*****TICKET BOOKED*****\n");
	return 0;		

}
