#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
	/**
	 * NOTE: If we see the return value of fork() it is a pid_t type.
	 * A pid_t is defined by a typedef as __darwin_pid_t, which is defined as __int32_t,
	 * which is defined as int. So by writing pid_t we obtain the same result as writing int.
	*/
	pid_t pid1 = fork();
	if (pid1 != 0) /**Parent process*/ {

		printf("Created child process (0.1: %d) from parent (0)\n", pid1);

		pid_t pid2 = fork();
		if (pid2 != 0) {

			printf("Created child process (0.2: %d) from parent (0)\n", pid2);

		} else {

			printf("\tIn child process (0.2)\n");

			pid_t pid4 = fork();
			if (pid4 != 0) {

				printf("\tCreated child (0.2.1: %d) from parent (0.2)\n", pid4);

			} else {

				printf("\t\tIn child (0.2.1) process\n");
			}
		}
	} else /** Child process*/{

		printf("\tIn child process (0.1)\n");

		pid_t pid3 = fork();
		if (pid3 != 0) {

			printf("\tCreated child (0.1.1: %d) from parent (0.1)\n", pid3);

		} else {

			printf("\t\tIn child (0.1.1)\n");
		}
	}
	return 0;
}
/** Bibliography:
 * Unix processes in C: https://youtube.com/playlist?list=PLfqABt5AS4FkW5mOn2Tn9ZZLLDwA3kZUY
 * See in bash: man fork
*/