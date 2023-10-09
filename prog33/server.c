#define SOCKET_NAME "/tmp/resol.sock"
#define BUFFER_SIZE 1024

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <unistd.h>

int
main(int argc, char *argv[])
{
    struct sockaddr_un addr;
    int down_flag = 0;
    int ret;
    int listen_socket;
    int data_socket;
    int result;
    char buffer[BUFFER_SIZE];

    /*
     * In case the program exited inadvertently on the last run,
     * remove the socket.
     */

    unlink(SOCKET_NAME);

    /* Create local socket. */

    listen_socket = socket(AF_UNIX, SOCK_STREAM, 0);
    if (listen_socket == -1) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    /*
     * For portability clear the whole structure, since some
     * implementations have additional (nonstandard) fields in
     * the structure.
     */

    memset(&addr, 0, sizeof(struct sockaddr_un));

    /* Bind socket to socket name. */

    addr.sun_family = AF_UNIX;
    strncpy(addr.sun_path, SOCKET_NAME, sizeof(addr.sun_path) - 1);

    ret = bind(listen_socket, (const struct sockaddr *) &addr,
               sizeof(struct sockaddr_un));
    if (ret == -1) {
        perror("bind");
        exit(EXIT_FAILURE);
    }

    ret = listen(listen_socket, 20);
    if (ret == -1) {
        perror("listen");
        exit(EXIT_FAILURE);
    }

 
  
        data_socket = accept(listen_socket, NULL, NULL);
        if (data_socket == -1) {
            perror("accept");
            exit(EXIT_FAILURE);
        }

        
            ret = read(data_socket, buffer, BUFFER_SIZE);
            if (ret == -1) {
                perror("read");
                exit(EXIT_FAILURE);
            }

        
         printf("%s",buffer);

        /*sprintf(buffer, "%d", result);*/
        char buffer1[]="Hello this is server";
        ret = write(data_socket, buffer1, strlen(buffer1));

        if (ret == -1) {
            perror("write");
            exit(EXIT_FAILURE);
        }

     

        close(data_socket);

   

    close(listen_socket);

  
}

