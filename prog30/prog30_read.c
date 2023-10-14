         /*
============================================================================
Name : prog30_read.c
Author : Ketki Kerkar
Description : Write a program to create a shared memory.
b. attach with O_RDONLY and check whether you are able to overwrite
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
    shmid=shmget((key_t)2345, 1024, 0666);  
    printf("Key of shared memory is %d\n",shmid);  
    shared_memory=shmat(shmid,NULL,0); //process attached to shared memory segment  
    printf("Process attached at %p\n",shared_memory);  
    printf("Data read from shared memory is : %s\n",(char *)shared_memory);  
    }  
