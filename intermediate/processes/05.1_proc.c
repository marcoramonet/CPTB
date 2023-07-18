#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <errno.h>

#define NUM_PIPES 2
#define NUM_FDS 2
#define P_RD 0
#define P_WR 1


/**
 * Example of interprocess communication.
 * A program that splits into three processes and calculates the sum of an array in three separate parts.
*/
int main(int argc, char *argv[])
{
	int arr[] = {1, 2, 3, 4, 5, 6};
    int size_arr = sizeof(arr) / sizeof(int);
    int start, end;

    int fds[NUM_PIPES][NUM_FDS];
    if (pipe(fds[0]) == -1 || pipe(fds[1]) == -1) {
        return 1;
    }

    pid_t pid1 = fork();
    pid_t pid2;
    if (pid1 == -1) {
        return 2;

    } else if (pid1 == 0) {
        start = 0;
        end = size_arr / 3;
    } else /* Parent process*/{
        pid2 = fork();
        if (pid2 == -1) {
            return 3;

        } else if (pid2 == 0) {
            start = size_arr / 3;
            end = (size_arr / 3) * 2;
        } else /* Parent process*/{
            start = (size_arr / 3) * 2;
            end = size_arr;
        }
    }

    int partial_sum = 0;
    for (int i = start; i < end; i++) {
        partial_sum += arr[i];
    }
    printf("Partial sum: %d. pid: %d. ppid: %d\n", partial_sum, getpid(), getppid());

    if (pid1 == 0) {
        /** Close unused pipe file descriptors*/
        close(fds[0][P_RD]);
        close(fds[1][P_RD]);
        close(fds[1][P_WR]);

        if (write(fds[0][P_WR], &partial_sum, sizeof(int)) == -1) {
            return 5;
        }

        close(fds[0][P_WR]);

    } else if (pid2 == 0) {
        /** Close unused pipe file descriptors*/
        close(fds[0][P_RD]);
        close(fds[0][P_WR]);
        close(fds[1][P_RD]);

        if (write(fds[1][P_WR], &partial_sum, sizeof(int)) == -1) {
            return 6;
        }

        close(fds[1][P_WR]);
    } else {
        /** Close unused pipe file descriptors*/
        close(fds[0][P_WR]);
        close(fds[1][P_WR]);

        int A, B;
        if (read(fds[0][P_RD], &A, sizeof(int))  == -1 ||
            read(fds[1][P_RD], &B, sizeof(int)) == -1) {
                return 4;
        }

        printf("Total sum is: %d\n", A + B + partial_sum);

        close(fds[0][P_RD]);
        close(fds[1][P_RD]);
    }

}
/** Bibliography:
 * Communicating between processees: https://youtu.be/6u_iPGVkfZ4
*/