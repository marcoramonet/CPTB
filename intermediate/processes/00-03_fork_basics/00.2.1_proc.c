#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
	int n;
	/** NOTE: If we wanted to have a variable accessible through all the processes,
	 * we might expect that a static variable may work. But the fact is it doesn't.
	 * See: https://stackoverflow.com/questions/29319718/can-a-child-process-change-a-static-variable-shared-by-his-parent
	 * For such behaviour, look into threads.
	*/
	// static int count = 0;



	printf("How many forks?\n");
	scanf("%d", &n);


	if (n >= 0 && n <= 8) {
		int pids[n];
		for (int i = 0; i < n; i++) {
			pids[i] = fork();
		}

	} else {
		printf("Invalid, the computer will crash");
	}

	/**
	* NOTE: that the amount of "hello" that we get is 2^n because that's the amount of processes.
	*/
	printf("Hello\n");

	/**
	 * How can I check for a more controlled branching of the execution line?
	 * See 00.2.2_proc.c
	*/
	return 0;
}


/** Bibliography:
 * Unix processes in C: https://youtube.com/playlist?list=PLfqABt5AS4FkW5mOn2Tn9ZZLLDwA3kZUY
 * See in bash: man fork
*/