#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

/** Includes the definition of mkfifo()*/
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/errno.h>
/** Includes the open() function*/
#include <sys/fcntl.h>

#include <time.h>

#define NUM_AMOUNT 5


/** This is the exact same as 06.1_proc_fifo_read.c
 * but, with a small optimization in the read() function call.
*/
int main(int argc, char *argv[]) {


    /** Open fifo.*/
    int fd = open("06.1_fifo", O_RDONLY);

    /** Create buffer*/
    int arr[NUM_AMOUNT];

    /** Read the whole length of the array with error checking*/
    if (read(fd, arr, sizeof(int) * NUM_AMOUNT) == -1) {
        printf("Error reading numbers: %d\n", errno);
        return 1;
    }

    /** Calculate sum*/
    int sum = 0;
    for (int i = 0; i < NUM_AMOUNT; i++) {
        sum += arr[i];
        printf("arr[%d]: %d\tsum: %d\n", i, arr[i], sum);
    }

    close(fd);


    return 0;
}