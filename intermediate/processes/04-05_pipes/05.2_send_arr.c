#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <time.h>

#define P_RD 0
#define P_WR 1

#define NUM_ELEMS 10
/**
 * We create two processes. A child generates a set of random numbers and sends them to the parent.
 * The parent receives them and adds them up.
 * 
 * NOTE: In order to send an array, we must always send first the amount of elements in the array.
 * This is so that the receiving process knows how many elements to read.
*/
int main(int argc, char *argv[]) 
{

    int fd[2];
    if (pipe(fd) == -1) { return 1; }


    pid_t pid = fork();

    if (pid == -1) { return 2; }
    if (pid == 0) {

        int amt;
        printf("How many elements?\n");
        scanf("%d", &amt);

        srand(time(NULL));
        int arr[amt];
        int sum = 0;
        for (int i = 0; i < amt; i++) {
            /** Generate a number from 5 to 20*/
            arr[i] = (rand() % 15) + 5;
            sum += arr[i];
        }

        printf("Child sum: %d\n", sum);

        close(fd[P_RD]);

        if (write(fd[P_WR], &amt, sizeof(int)) == -1) { return 4; }

        if (write(fd[P_WR], arr, sizeof(int) * amt) == -1 ) { return 3; }

        close(fd[P_WR]);

    } else {

        close(fd[P_WR]);

        int amt;
        if ( read(fd[P_RD], &amt, sizeof(int)) == -1) { return 6; }

        int arr[amt];

        if ( read(fd[P_RD], arr, sizeof(int) * amt) == -1) { return 5; }

        close(fd[P_RD]);

        int sum = 0;
        for (int i = 0; i < amt; i++) {
            sum += arr[i];
        }
        printf("Parent sum: %d\n", sum);
        wait(NULL);

    }
    return 0;
}