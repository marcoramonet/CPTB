#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

#include <signal.h>

void handle_sig(int sig) 
{
    printf("HINT: it's somewhere between 10 and 20\n");
}

/**
 * We can communictae between processes by using signals.
 * SIGUSR1 and SIGUSR2 are linux defined signals meant to be used by the user,
 * they are not used anywhere in the linux system.
*/
int main(int argc, char *argv[])
{
    pid_t pid = fork();
    if (pid == -1) { return 1; }
    if (pid == 0) {
        sleep(5);
        /**
         * If the user takes 5 seconds to answer we send a signal to the parent process.
        */
        kill(getppid(), SIGUSR1);

    } else {
        struct sigaction sa;
        sa.sa_handler = &handle_sig;
        /**
         * By setting the sa_flags to SA_RESTART we say that scanf should restart when the process is resumed.
        */
        sa.sa_flags = SA_RESTART;
        sigaction(SIGUSR1, &sa, NULL);

        int x;
        printf("How much is 5 * 3?\n");
        scanf("%d", &x);
        if (x == 15) {
            printf("Correct!\n");
        } else {
            printf("Incorrect!\n");
        }
        /**
         * Once we obtain the answer from the user, we kill the child process.
        */
        kill(pid, SIGKILL);
        wait(NULL);
    }
    return 0;
}
/**
 * Bibliography:
 * Communicating between processes using signals: https://youtu.be/PErrlOx3LYE
 * signal man pages: https://man7.org/linux/man-pages/man7/signal.7.html
*/