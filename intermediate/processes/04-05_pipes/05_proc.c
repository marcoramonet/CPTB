#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <errno.h>

/**
 * Example of interprocess communication.
 * A program that splits into two processes and calculates the sum of an array in two separate parts.
*/
int main(int argc, char *argv[])
{
	int arr[] = {1, 2, 3, 4, 5, 6};
	/** Here the sizeof(arr) is the number of bytes so by dividing it by the sizeof(int) we obtain the number of elements.*/
	int size_arr = sizeof(arr) / sizeof(int);
	int start_idx, end_idx;

	int fds[2];
	if (pipe(fds) == -1) {
		return 1;
	}


	/**
	 * Depending on which process we are, we set the indices for the calculation to be different.
	*/
	pid_t pid = fork();
	if (pid == -1) {
		return 2;

	} else if (pid == 0) {
		start_idx = 0;
		end_idx = size_arr / 2;

	} else {
		start_idx = size_arr / 2;
		end_idx = size_arr;
	}

	/** Both processes calculate a partial sum, but of different elements because they have different indices.*/
	int sum = 0;
	for (int i = start_idx; i < end_idx; i++) {
		sum += arr[i];
	}
	printf("Partial sum: %d\n", sum);
	if (pid == 0) {
		close(fds[0]);
		if (write(fds[1], &sum,sizeof(sum)) == -1) {
			return 3;
		}
		close(fds[1]);
	} else {
		int partial_sum;
		close(fds[1]);
		wait(NULL);
		if (read(fds[0], &partial_sum,sizeof(partial_sum)) == -1) {
			return 4;
		}
		printf("Result: %d\n", partial_sum + sum);
		close(fds[0]);
	}


}
/** Bibliography:
 * Communicating between processees: https://youtu.be/6u_iPGVkfZ4
*/