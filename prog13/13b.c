/*
============================================================================
Name : 13b.c
Author : Ketki Kerkar
Description : Write two programs: first program is waiting to catch SIGSTOP signal, the second program
will send the signal (using kill system call). Find out whether the first program is able to catch
the signal or not.
Date: 12th , Oct 2023
============================================================================
*/
#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <PID of the first program>\n", argv[0]);
        return 1;
    }

    pid_t target_pid = atoi(argv[1]);

    if (kill(target_pid, SIGSTOP) == -1) {
        perror("kill");
        return 1;
    }

    printf("Sent SIGSTOP to process with PID %d\n", target_pid);

    return 0;
}
