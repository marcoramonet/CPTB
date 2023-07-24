#include <stdlib.h>
#include <stdio.h>

/** Includes the exec family of functions.*/
#include <unistd.h>


/**
 * By forking before we call the exec function we still have control over the execution line
 * of the parent process.
*/
int main(int argc, char *argv[]) 
{
    pid_t pid = fork();

    if (pid == -1) { return 1; }
    /**
     * It's important that it's the child process which executes the program. 
     * This is because this way the parent process can wait for the child process to finish execution, but
     * not the other way around. If the parent process calls exec and the child process waits for it, then
     * the child process is a zombie process because it cannot wait for its parent process to finish execution.
    */
    if (pid == 0) {
        execlp("ping", "ping", "-c", "3", "google.com", NULL);
    } else {
        wait(NULL);
        /**
        * Note that the printf gets executed because only the child process gets replaced by the ping program,
        * not the parent process.
        */
        printf("Success!\n");
    }
    return 0;
}