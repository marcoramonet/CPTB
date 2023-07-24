#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

#include <signal.h>

void handle_sigtstp(int sig) 
{
    printf("Stop signal received: %d.\n", sig);
    exit(sig);
}

/**
 * To handle a signal we can use either one of the two options:
 * signal() or sigaction().
*/
int main(int argc, char *argv[])
{
    /**
     * For signal we just need to pass the signal we want to handle (SIGTSTP)
     * and a pointer to the handler function. 
    */
//    signal(SIGTSTP, &handle_sigtstp);


   /**
    * For sigaction we need to set up some configurations...
    * The struct sigaction holds the sa_handler which tells sigaction which handler to use.
   */
    struct sigaction sa;
    sa.sa_handler = &handle_sigtstp;
    sigaction(SIGTSTP, &sa, NULL);


    /**
     * Use Ctrl+Z to stop the program
    */
    while(1) {
        printf("Waiting for signal...\n");
    }

    return 0;
}
/**
 * Bibliography:
 * signal handling: https://youtu.be/jF-1eFhyz1U
*/