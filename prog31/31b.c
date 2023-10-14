/*
============================================================================
Name : 31b.c
Author : Ketki Kerkar
Description : Write a program to create a semaphore and initialize value to the semaphore.
b. create a counting semaphore
Date: 11th , Oct 2023
============================================================================
*/

#include <unistd.h>
#include <string.h>
#include <sys/sem.h>
#include <stdio.h>

union semaphore{
int val;
struct semid_Ds *buf;
unsigned short int *array;
};


int main(int argc, char **argv)
{
if(argc<2){
printf("Enter a token for key as command line argument\n ");
}
else{
    char arg_val=argv[1][0];
    union semaphore arg;
    int key,semid;
    key=ftok(".",arg_val);
    semid=semget(key ,1 ,IPC_CREAT|0744);
if(semid!=-1){
    //1 for binary , >1 for counting semaphore
    arg.val=5;
    semctl(semid,0,SETVAL,arg); //check ipcs -s whether created or not
    printf("Counting semaphore created successfully\n");
}
else{
    printf("Error creating Counting semaphore \n");
    }
}
    return 0;
}
