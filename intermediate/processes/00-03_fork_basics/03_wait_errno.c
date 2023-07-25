#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
/** wait.h include the wait() function*/
#include <sys/wait.h>
/** errno.h includes the errno environment variable and the ECHILD flag*/
#include <errno.h>


int main(int argc, char *argv[])
{
    /**
     * How do we know in which process we are when we fork multiple times?
    */
   pid_t pid1 = fork(); /* Gives parent and x processes*/
   pid_t pid2 = fork();


   if (pid1 == 0) {
		if (pid2 == 0) {
			printf("We are in process y: %d. My parent process is: %d\n", getpid(), getppid());
		} else {
			printf("We are in process x: %d. My parent process is: %d\n", getpid(), getppid());
		}
   } else {
		if (pid2 == 0) {
			printf("We are in process z: %d. My parent process is: %d\n", getpid(), getppid());
		} else {
			printf("We are in the parent process: %d. My parent process is: %d\n", getpid(), getppid());
		}
   }



	if (argc > 1 && strcmp(argv[1], "A") == 0) {
		/**
		* The function wait() waits for any child process to finish execution.
		* BUT: Because we are calling wait() from every process, the parent process finishes execution when any process finishes,
			in this case z most likely.
		* But, we may still have process x running, therefore if we call the getppid() function from x it will return 1, because its 
		* parent process (the parent process) will have finished executing.
		*/
		wait(NULL);
	} else if (argc > 1 && strcmp(argv[1], "B") == 0) {
		/**
		 * The wait function returns to the calling process the process id of the process which stopped execution.
		 * When there is an error, it returns the value of -1, and the variable errno is set to indicate the error.
		 * An example of an error in wait() is that the calling process does not have anything to wait for, 
		 * it doesn't have any child processes.
		 * Because the wait() function can have many different errors, the variable errno can be used to
		 * know which error it had. The error of the process not having any children is ECHILD.
		 * So, here we are checking that the wait() function did not return an error and that in case it did
		 * the error is that the calling process doesn't have any child processes.
		 * IOW: We are checking that a process only stops waiting when a child process returns because
		 * a child of its own stopped executing, not only because it doesn't have any children.
		*/
		while(wait(NULL) != -1 && errno != ECHILD) {
			/** We should get this printed 3 times because there are 3 parents*/
			printf("A child process finished\n");
		}
	}
	return 0;
}
/** Bibliography:
 * Calling fork multiple times: https://youtu.be/94URLRsjqMQ
 * See in the terminal: man 2 wait
*/