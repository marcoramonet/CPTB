#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h>
/**unistd.h includes getpid() and getppid()*/
#include <unistd.h>

int main(int argc, char *argv[])
{
    pid_t pid = fork();
    if (pid == 0) {
        sleep(1);
    }
    /**
     * Notice that pid is 0 but the process id is different.
    */
    printf("pid: %d, getpid(): %d, getppid(): %d\n", pid, getpid(), getppid());
    wait(NULL);
    return 0;
}
/**
 * Bibliography:
 * What does fork() actually return?: https://youtu.be/sGpv7qEBrJs
*/