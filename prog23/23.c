#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
#include <sys/resource.h>
#include <fcntl.h>

// Check if the F_GETPIPE_SZ constant is defined
#ifndef F_GETPIPE_SZ
#define F_GETPIPE_SZ 1032  // You can define it with a suitable value if it's not available
#endif

int main() 
{
    // Get the maximum number of files that can be opened by a process
    struct rlimit rlim;
    if(getrlimit(RLIMIT_NOFILE, &rlim) == 0) 
    {
        printf("Maximum number of files that can be opened by a process: %lu\n", rlim.rlim_cur);
    } 
    else 
    {
        perror("getrlimit");
        return 1;
    }

    // Create a pipe and get its buffer size
    int pipe_fd[2];
    if(pipe(pipe_fd) == 0) 
    {
        int pipe_size = fcntl(pipe_fd[0], F_GETPIPE_SZ);
        if(pipe_size != -1) 
	{
            printf("Size of a pipe (circular buffer): %d bytes\n", pipe_size);
        } 
	else 
	{
            perror("fcntl");
            return 1;
        }
    } 
    else 
    {
        perror("pipe");
        return 1;
    }

    return 0;
}
