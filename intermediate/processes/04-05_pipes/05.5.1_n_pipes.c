#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>


#define FILDES_PER_PIPE 2
#define P_RD 0
#define P_WR 1

/**
 * This is the same program as 05.5_multiple_pipes.c but generalized.
 * The number of processes is read from the user input.
*/
int main(int argc, char *argv[])
{
    int inc_amt;
    printf("How many times do you want to increment?\n");
    scanf("%d", &inc_amt);
    const int NUM_PROC = inc_amt;
    const int NUM_PIPES = NUM_PROC + 1;
    
    pid_t pids[NUM_PROC];

    int fds[NUM_PIPES][FILDES_PER_PIPE];

    for (int i = 0; i < NUM_PIPES; i++) {
        if (pipe(fds[i]) == -1) { return 1; }
    }

    for (int i = 0; i < NUM_PROC; i++) {
        /**
         * i is the process index
        */
        pids[i] = fork();
        if (pids[i] == -1) { return 2; }
        if (pids[i] == 0) /** Child process */ {

            /* Close unused pipes*/
            for (int j = 0; j < NUM_PIPES; j++) {
                if (j != i) {
                    /** Close all pipes except the pair of the process.*/
                    close(fds[j][P_RD]);
                }
                if (j != i + 1) {
                    /** Close all pipes except the pair of the next process.*/
                    close(fds[j][P_WR]);
                }
            }

            /** Operations*/
            int x = 0;
            if ( read(fds[i][P_RD], &x, sizeof(int)) == -1) { return 3; }
            printf("(%d): Received: %d\n", getpid(), x);
            x++;
            if (write(fds[i + 1][P_WR], &x, sizeof(int)) == -1) { return 4; }
            printf("(%d): Sent: %d\n", getpid(), x);



            /* Close used pipes*/
            close(fds[i][P_RD]);
            close(fds[i + 1][P_WR]);

            return 0;
        }
    }

    /* Parent process*/

    /* Close unused pipes*/
    for (int j = 0; j < NUM_PIPES; j++) {
        if (j != NUM_PIPES - 1) {
            close(fds[j][P_RD]);
        }
        if (j != 0) {
            close(fds[j][P_WR]);
        }
    }

    /** Operations*/

    
    int x = 5, num_proc;
    printf("Input a number:\n");
    scanf("%d", &x);

    printf("(%d) Parent process sent: %d\n", getpid(), x);
    if (write(fds[0][P_WR], &x, sizeof(int)) == -1) { return 5; }
    if ( read(fds[NUM_PROC][P_RD], &x, sizeof(int)) == -1) { return 6; }
    printf("(%d) Parent process read: %d\n", getpid(), x);

    /** Close used pipes*/
    close(fds[0][P_WR]);
    close(fds[NUM_PROC][P_RD]);

    for (int i = 0; i < NUM_PROC; i++) {
        wait(NULL);
    }
    return 0;
}


/**
 * Bibliography:
 * Multiple pipes: https://youtu.be/VzCawLzITh0
 * https://code-vault.net/lesson/v5cml4fg0w:1610639843712
*/