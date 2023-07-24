#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

#define P_RD 0
#define P_WR 1
/**
 * We simulate a "|" operator between two programs programatically.
 * We redirect the output of the first program to a pipe.
 * We redirect the input of the second program to the pipe.
*/
int main(int argc, char *argv[])
{

    int fd[2];
    if(pipe(fd) == -1) { return 1;}


    pid_t pid1 = fork();
    if (pid1 == -1) { return 2; }
    if (pid1 == 0) {
        /** We duplicate the pipe write fildes on top of the STDOUT.*/
        dup2(fd[P_WR], STDOUT_FILENO);
        /** We close the reading end of the pipe because we don't use it.*/
        close(fd[P_RD]);
        /** We close the writing end of the pipe because we don't use it*/
        close(fd[P_WR]);

        execlp("ping", "ping", "-c", "3", "google.com", NULL);
    }

    pid_t pid2 = fork();
    if (pid2 == -1) { return 3; }
    if (pid2 == 0) {
        /** 
         * Replace the STDIN_FILENO with fd[P_RD].
         * Or in other words: duplicate fd[P_RD] on top of STDIN_FILENO.
        */
        dup2(fd[P_RD], STDIN_FILENO);
        close(fd[P_RD]);
        close(fd[P_WR]);

        execlp("grep", "grep", "round-trip", NULL);
    }

    close(fd[P_WR]);
    close(fd[P_RD]);

    waitpid(pid1, NULL, 0);
    waitpid(pid2, NULL, 0);

    return 0;
}