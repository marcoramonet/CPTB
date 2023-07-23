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
 * This is the same as 06.1.1_write but we receive the sum from the reader.
*/
int main(int argc, char *argv[]) 
{
    int arr[NUM_AMOUNT];
    int sum_gen = 0;
    srand(time(NULL));
    for (int i = 0; i < NUM_AMOUNT; i++) {
        arr[i] = rand() % 100;
        sum_gen += arr[i];
        printf("Generated: %d\n", arr[i]);
    }
    printf("Sum: %d\n", sum_gen);

    if (mkfifo("06.1.2_fifo", 0777) == -1 && errno != EEXIST) {
        printf("Error creating: %d\n", errno);
        return 1;
    }

    int fd = open("06.1.2_fifo", O_WRONLY);

    if (fd == -1) {
        printf("Error opening: %d\n", errno);
        return 2;
    }

    if (write(fd, arr, sizeof(arr) * NUM_AMOUNT) == -1) {
        printf("Error writing: %d\n", errno);
        return 3;
    }

    close(fd);

    fd = open("06.1.2_fifo", O_RDONLY);
    if (fd == -1) {
        printf("Error opening(1): %d\n", errno);
        return 4;
    }

    int sum_rec;
    if (read(fd, &sum_rec, sizeof(sum_rec)) == -1) {
        printf("Error reading: %d\n", errno);
        return 5;
    }
    close(fd);
    if (sum_gen != sum_rec) {
        printf("Received sum is incorrect: %d\n", sum_rec);
        return 6;
    }

    return 0;
}