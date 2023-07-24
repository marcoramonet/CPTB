#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

#include <signal.h>


int main(int argc, char *argv[])
{
    pid_t pid = fork();

    if (pid == -1) { return 1; }
    if (pid == 0) {
        while(1) {
            usleep(500000);
            printf("Sleeping...\n");
        }
    } else {
        /**
         * kill() doesn't necessarily kill the process to which its sending the signal.
         * Depending on the signal that kill is sending is the effect on the process.
         * SIGSTOP only stops the execution of the process, it doesn't kill it.
         * 
         * Whenever we hit Ctrl+Z in the terminal while a process is running,
         * the terminal sends the SIGTSTP signal to the process which stops it
         * and sends it to the background. Then if we run the command fg
         * we tell the terminal to bring to the foreground any process that is in the
         * background.
        */
        kill(pid, SIGSTOP);
        int t;

        do{
            printf("How many seconds should we sleep?\n");
            scanf("%d", &t);

            if (t > 0) {
                /**
                 * SIGCONT tells the process to continue execution if it was stopped.
                */
                kill(pid, SIGCONT);
                sleep(t);
                kill(pid, SIGSTOP);
            }

        } while (t > 0);


        kill(pid, SIGKILL);
        wait(NULL);
    }


    return 0;
}
/**
 * Bibliography:
 * SIGSTOP and SIGCONT:  https://youtu.be/3MZjaZxZYrE
*/