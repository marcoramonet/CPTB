#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>


/**
 * Say we wanted to wait for two processes which take different amounts of time.
 * 
*/
int main() 
{
    int pid1 = fork();
    if (pid1 == -1) { return 1; }
    if (pid1 == 0) {
        sleep(4);
        printf("Finished execution. pid: %d\n", getpid());
        return 0;
    }

    int pid2 = fork();
    if (pid2 == -1) { return 2; }
    if (pid2 == 0) {
        sleep(2);
        printf("Finished execution. pid: %d\n", getpid());
        return 0;
    }

    /**
     * We can wait for both proccesses to finish by calling wait(NULL) twice.
     * But, what if we want to specify which process we wait for first?
    */
    // int pid1_res = wait(NULL);
    // printf("Waited for %d\n", pid1_res);
    // int pid2_res = wait(NULL);
    // printf("Waited for %d\n", pid2_res);

    /**
     * To wait for a particular process we can use waitpid().
     * Notice that now we wait for both processes in order to continue execution.
     * And also the order of the wait is respected.
     *
     * 
     * The third parameter specifies the options passed into waitpid.
     * The equivalent of wait(NULL) is waitpid(pid, NULL, 0).
     * But, if we pass the option WNOHANG for instance, instead of stopping execution and
     * waiting for the process to finish its execution it's
     * only gonna evaluate if the pid process is finished at the particular time when the
     * waitpid function is called, and it's gonna save the result of the evaluation in the
     * second parameter, an int pointer similar to the parameter of wait().
    */
    int pid1_res = waitpid(pid1, NULL, WNOHANG);
    printf("Waited for %d\n", pid1_res);
    int pid2_res = waitpid(pid2, NULL, WNOHANG);
    printf("Waited for %d\n", pid2_res);
    return 0;
}
/**
 * Bibliography: 
 * What is waitpid?: https://linux.die.net/man/2/waitpid
 * Linux man page waitpid: https://linux.die.net/man/2/waitpid
*/