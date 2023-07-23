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

/** As an exercise we write a program that writes some numbers to a pipe.
 * And another program that reads those numbers and prints out their sum.
 * This is the program that reads the numbers
*/
int main(int argc, char *argv[]) {

    /** We don't have to create the fifo because
     * the writing program does that. We only have to open
     * the fifo, with some error checking.
    */
    int fd = open("06.1_fifo", O_RDONLY);
    if (fd == -1) {
        printf("Error opening fifo: %d.\n", errno);
        return 1;
    }

    /**
     * We create the buffer to read into.
    */
    int arr[NUM_AMOUNT];
    for (int i = 0; i < NUM_AMOUNT; i++) {
        /** We read one int at a time, while doing some error checking.*/
        if (read(fd, &arr[i], sizeof(int)) == -1) {
            printf("Error reading fifo: %d.\n", errno);
            return 2;
        } /* If we read correctly, we print what we read */
        printf("Read: %d.\n", arr[i]);

    }

    /** We calculate the sum.*/
    int sum = 0;
    for (int i = 0; i < NUM_AMOUNT; i++) {
        sum += arr[i];
    }
    printf("The result is: %d\n", sum);

    return 0;
}