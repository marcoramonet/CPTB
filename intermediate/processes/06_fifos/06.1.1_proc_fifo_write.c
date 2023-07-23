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



/**
 * This is the same program as 06.1_proc_fifo_write but 
 * with an optimization in the write function call.
*/
int main(int argc, char *argv[]) 
{
    /** Sum for testing*/
    int sum = 0;
    int arr[NUM_AMOUNT];
    srand(time(NULL));
    for (int i = 0; i < NUM_AMOUNT; i++){
        arr[i] = rand() % 100;
        sum += arr[i];
        printf("Generated: %d\t Sum: %d\n", arr[i], sum);
    }


    /** Make fifo and do error checking.*/
    if (mkfifo("06.1_fifo", 0777) == -1 && errno != EEXIST) {
        printf("Error creating fifo: %d\n", errno);
        return 1;
    }


    /** Open fifo.*/
    int fd = open("06.1_fifo", O_WRONLY);

    /** Here,  we optimize by writing the whole length
     * of arr in one function call to open, instead of 
     * 5 calls for each number.
     * We can do this because the arr holds the five
     * generated numbers one after the other, and they're 
     * written in the same manner. Also when read.
    */
    if (write(fd, arr, sizeof(int) * NUM_AMOUNT) == -1) {
        printf("Error writing to fifo. errno: %d\n", errno);
        return 2;
    }
    close(fd);


    return 0;
}