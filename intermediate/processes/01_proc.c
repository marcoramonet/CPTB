/**
 * A process is a program in execution. 
 * A process is assigned resources like CPU time and memory by the OS.
*/

#include <stdlib.h>
#include <stdio.h>
/** unistd.h defines fork()*/
#include <unistd.h>


/**
     * The fork function splits the execution line creating a new process.
     * When we run into a fork() function call, a new process is created and executed.
     * The newly created process is an exact copy of the parent process. 
     * It contains the same variables and file descriptors.
     * The fork() function returns an int. 
     * This number equals 0 in the child process and the process id of the new child (pid) in the parent process.
*/
void fork_not_wait(char *child_message)
{
    int pid = fork();
    if (pid == 0)  /*In child process*/ {
        sleep(1);
        printf("%s\n", child_message);
        return;
    } else /* In parent process*/{
        printf("I don't wait for my children\n");
    }
}

void fork_n_wait(char *child_message)
{
    int pid = fork();
    if (pid == 0)  /*In child process*/ {
        sleep(1);
        printf("%s\n", child_message);
        return;
    } else /*In parent process*/{
        printf("I wait for my children\n");
        /* waitpid waits for the child process described by 'pid' to finish*/
        waitpid(pid, NULL, 0);
    }
}

int main(int argc, char *argv[])
{
    /**
     * Notice that when we don't wait for the child to finish,
     * the parent process returns, therefore the terminal resets.
     * Then the child process prints the message to the terminal.
    */
//    fork_not_wait("Mommy please dont leave me");

/**
 * But, when we wait for the child process, 
 * the terminal does not reset. 
 * IOW: the program waits for the child process to finish.
*/
    fork_n_wait("My mommy loves me");


    
    return 0;
}