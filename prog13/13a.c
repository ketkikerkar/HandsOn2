/*
============================================================================
Name : 13a.c
Author : Ketki Kerkar
Description : Write two programs: first program is waiting to catch SIGSTOP signal, the second program
will send the signal (using kill system call). Find out whether the first program is able to catch
the signal or not.
Date: 12th , Oct 2023
============================================================================
*/
#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void sigstop_handler(int signum) {
    printf("Caught SIGSTOP\n");
}

int main() {
    signal(SIGSTOP, sigstop_handler);
    
    printf("Process id: %d \n", getpid());
    printf("Waiting for SIGSTOP...\n");
    while (1);

    return 0;
}
