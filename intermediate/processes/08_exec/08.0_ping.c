#include <stdlib.h>
#include <stdio.h>

/** Includes the exec family of functions.*/
#include <unistd.h>


/**
 * With the exec family of functions we can execute another program from our own program.
 * When we call an exec function the whole process gets replaced by the called program.
 * A successful exec function never returns control because the calling process is overwritten with the new process.
 * The memory is replaced, the execution line too, everything.
 * BUT: We know how to create new processes, so we can use this to our advantage...
*/
int main(int argc, char *argv[]) 
{


    execlp("ping", "ping", "-c", "3", "google.com", NULL);
    /**
     * Note that the printf doesn't get executed because the program gets replaced entirely by the ping program.
    */
   printf("Success!\n");
    return 0;
}