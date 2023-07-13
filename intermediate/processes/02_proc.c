#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h>
/**wait.h includes getpid() and getppid()*/
#include <unistd.h>

int main(int argc, char *argv[])
{
    pid_t pid = fork();
    /* This prints */
    printf("pid: %d\tparent pid: %d\n",
        getpid(), getppid());

    return 0;
}
/**
 * Bibliography:
 * Process IDs in C : https://youtu.be/PZrQ4eGm-hM
*/