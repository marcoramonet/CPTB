/**
 * We cannot have a pipe that both sends and receives data in the same process. 
 * We must have a pipe for reading and a pipe for writing.
 * 
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

#include <time.h>

#define P_RD 0
#define P_WR 1

/**
 * We want to create a program that generates a number from 0-9, 
 * sends it to another process which multiplies it by 4,
 * and sends it back to the parent process.
*/
int main(int argc, char *argv[])
{
    /** 
     * Parent to child.
     * Parent only writes to this pipe.
     * Child only reads from this pipe.
     * */
    int p1[2];
    /**
     * Child to parent.
     * Parent only reads from this pipe.
     * Child only writes to this pipe.
    */
    int p2[2]; 
    if (pipe(p1) == -1) { return 1; }
    if (pipe(p2) == -1) { return 2; }

    pid_t pid = fork();
    if (pid == -1) { return 3; }
    if (pid == 0) {

        int y;

        close(p1[P_WR]);
        close(p2[P_RD]);

        if (read(p1[P_RD], &y, sizeof(int)) == -1) { return 5; }
        printf("y: %d\n", y);
        y *= 4;
        printf("y * 4: %d\n", y);
        if (write(p2[P_WR], &y, sizeof(int)) == -1) { return 6; }

        close(p1[P_RD]);
        close(p2[P_WR]);

    } else {
        srand(time(NULL));
        int x = rand() % 10;
        printf("x: %d\n", x);

        close(p1[P_RD]);
        close(p2[P_WR]);

        if(write(p1[P_WR], &x, sizeof(int)) == -1) { return 4; }

        if (read(p2[P_RD], &x, sizeof(int)) == -1) { return 7; }

        close(p1[P_WR]);
        close(p2[P_RD]);
        printf("x * 4: %d\n", x);
    }
    return 0;
}