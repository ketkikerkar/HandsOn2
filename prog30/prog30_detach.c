     /*
============================================================================
Name : 30_detach.c
Author : Ketki Kerkar
Description : Write a program to create a shared memory.
c. detach the shared memory
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
   printf("Shared Memory Detached");
   getchar();
   }
  
    return 0;
    }  
