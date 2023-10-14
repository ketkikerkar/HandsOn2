
         /*
============================================================================
Name : prog30_read.c
Author : Ketki Kerkar
Description : Write a program to create a shared memory.
d. remove the shared memory
Date: 11th , Oct 2023
============================================================================
*/
#include<stdio.h>  
    #include<stdlib.h>  
    #include<unistd.h>  
    #include<sys/shm.h>  
    #include<string.h>  
    int main()  
    {  
    int i;  
    void *shared_memory;  
    char buff[100];  
    int shmid;  
    shmid=shmget((key_t)2345, 1024, 0666|IPC_CREAT);   
    //creates shared memory segment with key 2345, having size 1024 bytes. IPC_CREAT is used to create the shared segment if it does not exist. 0666 are the permissions on the shared segment  
    printf("Key of shared memory is %d\n",shmid);  
    shared_memory=shmat(shmid,NULL,0);   
    //process attached to shared memory segment  
    printf("Process attached at %p\n",shared_memory);   
   
    if (shmdt(shared_memory) == -1) {
    //detach
      perror("shmdt");
      return 1;
   }
   else{
   printf("Detached");
   getchar();
   }
   if (shmctl(shmid, IPC_RMID, 0) == -1) {//remove shared memory
      perror("shmctl");
      return 1;
   }
   else{
   printf("Removed shared memory");}
   
    return 0;
    }  
