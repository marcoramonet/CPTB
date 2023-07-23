#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    /**
     * The fork() function returns an int value.
     * This number is the process id (pid).
     * Each of the processes resulting from the fork (parent and child),
        * have a different pid value.
     * For the child process the 'pid' value will be 0.
     * For the parent process the 'pid' value will be the pid of the child process.
     * Everything up until the fork() function call is executed only once.
     * While everything after the fork() function call is executed once per process.
    */
   int pid = fork();
   /** Here we will print two different values.
    * The child process will be 0.
    * The parent process will be some other number returned by the fork() function.
   */
   printf("pid:  %d\n", pid);
   
   /**
    * We can use this information to access the execution of each process.
   */
  if (pid == 0) /** In child process*/ {
    printf("In child process\n");

  } else /** In parent process*/ {
    printf("In parent process\n");
  }


    return 0;
}
/** Bibliography:
 * Unix processes in C: https://youtube.com/playlist?list=PLfqABt5AS4FkW5mOn2Tn9ZZLLDwA3kZUY
 * See in bash: man fork
*/