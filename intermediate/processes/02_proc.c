#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h>
/**unistd.h includes getpid() and getppid()*/
#include <unistd.h>

int main(int argc, char *argv[])
{
    pid_t pid = fork();
    /**
     * getpid() returns the process id of the calling process.
     * getppid() returns the process id of the parent process of the calling process.
    */
    printf("pid: %d\tparent pid: %d\n",
        getpid(), getppid());

    return 0;
}
/**
 * Bibliography:
 * Process IDs in C : https://youtu.be/PZrQ4eGm-hM
*/