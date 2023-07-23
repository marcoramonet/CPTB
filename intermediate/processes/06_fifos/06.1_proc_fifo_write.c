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



/**As an exercise we write a program that writes
 *  some numbers to a pipe.
 * And another program that reads those numbers
 *  and prints out their sum.
 * This is the program that writes the numbers.
 * 
 * NOTE: With a fifo we can: not only communicate between processes,
 * but we now can also communicate between processes that are not
 * in the same hierarchy.
*/
int main(int argc, char *argv[]) {

    /** Repace the randomly generated numbers by
     * the following line for testing.
    */
    // int arr[NUM_AMOUNT] = {1,2,3,4,5};




    /**
     * Generate 5 random numbers between 0 and 99 inclusive.
    */
    int arr[NUM_AMOUNT];
    srand(time(NULL));
    for (int i = 0; i < NUM_AMOUNT; i++){
    arr[i] = rand() % 100;
    }


    /** Open fifo and do error checking.*/
    if (mkfifo("06.1_fifo", 0777) == -1 && errno != EEXIST) {
        printf("Error creating fifo: %d\n", errno);
        return 1;
    }


    /** Open fifo.*/
    int fd = open("06.1_fifo", O_WRONLY);

    /** sum for testing*/
    int sum = 0;
    for (int i = 0; i < NUM_AMOUNT; i++) {
        /** Write the numbers one at a time.
         * NOTE: Just like with any file,
         * reading from a fifo leaves the pointer 
         * in the last position. So, the next time
         * that something is read from that file,
         * it's the next byte.
        */
        if (write(fd, &arr[i], sizeof(int)) == -1) {
            printf("Error writing to fifo. errno: %d\n", errno);
            return 2;
        }
        sum += arr[i];
        printf("Wrote: %d.\tSum: %d\n", arr[i], sum);
    }
    close(fd);


    return 0;
}