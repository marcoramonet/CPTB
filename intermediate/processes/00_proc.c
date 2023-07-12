/**
 * A process is a program in execution. 
 * A process is assigned resources like CPU time and memory by the OS.
*/

#include <stdlib.h>
#include <stdio.h>
/** unistd.h defines fork()*/
#include <unistd.h>

int main(int argc, char *argv[])
{

    /** This prints only once.*/
    printf("Hello world!\n");
    
    /** This will create a new process where the parent process
     * file descriptors will be copied.
     * A file descriptor is [...]
    */
    fork();
    /** This will print twice. Once for each process*/
    printf("This is a process\n");

    printf("\n");

    /**
     * The fork() function returns an int value.
    */
   


    return 0;
}