#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

#define FILDES_PER_PIPE 2
#define NUM_PIPES 3
#define P_RD 0
#define P_WR 1

/**
 * We create two child processes. Each child process adds 5 to a number.
 * We create an int variable, we pass it through each child process (2),
 * each of which adds 5 to it and passes it on to the next process.
 * In the end the parent process receives the variable with two additions,
 * one for each child.
*/
int main(int argc, char *argv[])
{
    int fds[NUM_PIPES][FILDES_PER_PIPE];

    for (int i = 0; i < NUM_PIPES; i++) {
        if (pipe(fds[i]) == -1) { return 1; }
    }

    pid_t pid1 = fork();
    if(pid1 == -1) { return 2; }
    if (pid1 == 0) {

        /** Close unused fildes*/
        close(fds[2][P_WR]);
        close(fds[2][P_RD]);
        close(fds[0][P_WR]);
        close(fds[1][P_RD]);

        /** Operations*/
        int y;
        if (read(fds[0][P_RD], &y, sizeof(int)) == -1) { return 3; }
        y += 5;

        if (write(fds[1][P_WR], &y, sizeof(int)) == -1) { return 4; }

        /** Close used fildes*/
        close(fds[0][P_RD]);
        close(fds[1][P_WR]);

        return 0;
    }


    pid_t pid2 = fork();
    if (pid2 == -1) { return 5; }
    if (pid2 == 0) {

        /** Close unused fildes*/
        close(fds[0][P_WR]);
        close(fds[0][P_RD]);
        close(fds[1][P_WR]);
        close(fds[2][P_RD]);

        /** Operations*/
        int z;
        if (read(fds[1][P_RD], &z, sizeof(int)) == -1) { return 6; }

        z += 5;

        if (write(fds[2][P_WR], &z, sizeof(int)) == -1) { return 7; }

        /** Close used fildes*/
        close(fds[1][P_RD]);
        close(fds[2][P_WR]);
        return 0;
    }

    /**
     * Parent process
    */

    /** Close unused fildes*/
    close(fds[1][P_RD]);
    close(fds[1][P_WR]);
    close(fds[0][P_RD]);
    close(fds[2][P_WR]);

    /** Operations*/
    int x, r;
    printf("Input a number: \n");
    scanf("%d", &x);

    if (write(fds[0][P_WR], &x, sizeof(int)) == -1) { return 8; }
    if (read(fds[2][P_RD], &r, sizeof(int)) == -1) { return 9; } 

    printf("Result: %d\n", r);

    /** Close used fildes*/
    close(fds[0][P_WR]);
    close(fds[2][P_RD]);

    waitpid(pid1, NULL, 0);
    waitpid(pid2, NULL, 0);

    return 0;
}


/**
 * Bibliography:
 * Working with multiple pipes: https://youtu.be/NkfIUo_Qq4c
*/