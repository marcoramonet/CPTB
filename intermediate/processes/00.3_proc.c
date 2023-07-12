#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

/**
 * What if we want to wait for the child process to finish?
 * As an exercise let's make a program that prints 10 numbers, 
 * from 0 to 10. But the first 5 will be printed by the child process,
 * and the second 5 will be printed by the parent process.
*/

void method_one() 
{
    pid_t pid = fork();
    if (pid != 0) {
        /** Here, we wait for the child process to finish.
         * Comment this line out to see how 
         * the two processes print the numbers simultaneously.
        */
        waitpid(pid, NULL, 0);
        for (int i = 5; i < 10; i++) {
            printf("%d\n", i);

        }
    } else {
        for (int i = 0; i < 5; i++) {
            printf("%d\n", i);
        }
    }
}



void method_two() 
{
    pid_t pid = fork();
    int n;

    if (pid == 0) {
        n = 0;
    } else {
        n = 5;
    }

    if (pid != 0) {
        /** Comment this line if you want to see the numbers out of order*/
        wait(NULL);
    }


    for (int i = n; i < n + 5; i++) {
        printf("%d\n", i);
    }
}


int main(int argc, char *argv[]) 
{
    // method_one();  
    method_two();
    return 0;
}


/** Bibliography:
 * Unix processes in C: https://youtube.com/playlist?list=PLfqABt5AS4FkW5mOn2Tn9ZZLLDwA3kZUY
 * See in bash: man fork
 * * See in bash: man wait
*/