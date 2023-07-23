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


/** This is the same as 06.1.1_read but we send the result of the sum back to the 
 * writer program
*/
int main(int argc, char *argv[]) {

    int arr[NUM_AMOUNT];

    int fd = open("06.1.2_fifo", O_RDONLY);
    if (fd == -1) {
        printf("Error opening: %d\n", errno);
        return 1;
    }

    if(read(fd, arr, sizeof(int) * NUM_AMOUNT) == -1) {
        printf("Error reading: %d\n", errno);
        return 2;
    }
    int sum = 0;
    for (int i = 0; i < NUM_AMOUNT; i++) {
        sum += arr[i];
    }
    close(fd);

    printf("Sum: %d\n", sum);







    fd = open("06.1.2_fifo", O_WRONLY);

    if (fd == -1) {
        printf("Error opening(1): %d\n", errno);
        return 3;
    }

    if (write(fd, &sum, sizeof(sum)) == -1) {
        printf("Error writing: %d\n", errno);
        return 4;
    }
    close(fd);


    return 0;
}