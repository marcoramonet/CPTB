#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <errno.h>


int main(int argc, char *argv[])
{
	/**
	 * A pipe is a buffer in memory from which we can write and read data.
	 * A pipe has two file descriptors, a reading end and a writing end.
	 * A file descriptor is a number which tells the operating system a 'location' in memory accessible from a program.
	 */
	int fds[2];
	int pipe_res = pipe(fds);
	/** It's good practice to do error checking*/
	if (pipe_res == -1) {
		fprintf(stderr, "Error opening the pipe: %d\n", errno);
		return 1;
	}

	pid_t pid = fork();
	if (pid == -1) {

		fprintf(stderr, "Error forking: %d\n", errno);
		return 2;

	} else if (pid == 0)/** In child process*/ {

		/** We close the reading end of the pipe*/
		close(fds[0]);
		int num;
		printf("Input a number: \n");
		scanf("%d", &num);
		/** write() allows us to write into any file descriptor (fds[1]) the contents of a buffer (num) */
		if (write(fds[1], &num, sizeof(int)) == -1) {
			printf("Error writing to the pipe\n");
			return 3;
		}
		close(fds[1]);

	} else /** In parent process*/ {

		/** We close the writing end of the pipe*/
		close(fds[1]);
		int num;
		/** We read from a file descriptor (fds[0]) into a buffer (num) a certain number of bytes (sizeof(int))*/
		if (read(fds[0], &num, sizeof(int)) == -1) {
			printf("Error reading from the pipe\n");
			return 4;
		}
		printf("Received: %d\n", num);
		close(fds[0]);
	}

	return 0;
}
/** Bibliography:
 * Communicating between processees: https://youtu.be/Mqb2dVRe0uo
*/