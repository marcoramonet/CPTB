#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

#include <signal.h>


int main(int argc, char *argv[])
{
    pid_t pid = fork();

    if (pid == -1) { return 1; }
    if (pid == 0) {
        while(1) {
            usleep(500000);
            printf("Sleeping...\n");
        }
    } else {
        sleep(2);
        /**
         * In order to kill the child process we can press ctrl+C to send a kill signal.
         * But we can also do this programatically by using kill().
         * kill() sends the process specified by the pid, the signal specified in the 
         * second parameter.
         * 
         * NOTE: In the child process, even though it is in an infinite while loop,
         * the signal gets handled properly and the process gets killed.
        */
        kill(pid, SIGKILL);
    }


    return 0;
}