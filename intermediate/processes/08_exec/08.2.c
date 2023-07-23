#include <stdlib.h>
#include <stdio.h>

/** Includes the exec family of functions.*/
#include <unistd.h>


/**
 * We can access the return value of a program, that is 
 * the value the main function of a program returns.
*/
int main(int argc, char *argv[]) 
{
    pid_t pid = fork();

    if (pid == -1) { return 1; }
    /**
     * It's important that it's the child process which executes the program. 
     * This is because this way the parent process can wait for the child process to finish execution, but
     * not the other way around. If the parent process calls exec and the child process waits for it, then
     * the child process is a zombie process because it cannot wait for its parent process to finish execution.
    */
    if (pid == 0) /* Child process*/ {
        /***
         * exec returns a -1 in case of an error and in case of success it doesn't really return anything,
         * this is because the execution line is replaced by the program.
        */
       int err = execlp("pingg", "ping", "-c", "3", "google.com", NULL);
        if (err == -1) {
            printf("Error in exec\n");
            return 1;
        }
    } else /* Parent process*/{
        /**
         * We can use an int to store the exit information of the process 
         * which finished execution.
        */
        int wstatus;
        /**
         * The parameter of the wait function tells us some infomration about 
         * what happened with the child process that terminated.
        */
        wait(&wstatus);
        /**
         * We can do a couple of checks with the int that we passed to wait().
         * We can use the macro WIFEXITED(x) which returns true if the process
         * referenced by wstatus terminated normally.
        */
        if (WIFEXITED(wstatus)) {
            /**
             * We can also access the exit status code of the process referenced by
             * wstatus (ping in this case). In other words, it's the return value
             * of the main function of the called program, or the value that the 
             * program exited with, for instance by calling exit().
            */
            int status_code = WEXITSTATUS(wstatus);
            if (status_code == 0) {
                printf("Success!\n");
            } else {
                printf("Failure. Exited with status_code: %d.\n", status_code);
            }
        }
    }
    return 0;
}

/**
 * Bibliography:
 * Getting exit status code in C: https://youtu.be/DiNmwwQWl0g
 * See the linux manual for wait: https://man7.org/linux/man-pages/man2/wait.2.html
*/