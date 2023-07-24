#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

#define P_RD 0
#define P_WR 1


/**
 * We read a string from the user in the child process and send it to the parent process.
*/
int main(int argc, char *argv[]) 
{
    int fd[2];
    if ( pipe(fd) == -1) { return 2; }
    pid_t pid = fork();

    if (pid == -1) { return 1; }

    if (pid == 0) {
        char msg[128];
        printf("Input:\n");

        /** fgets reads from stdin into msg the length of 128.*/
        fgets(msg, 128, stdin);
        /**fgets leaves the last character of the string as a newline character.
         * So, to avoid this we set the last character to be the null terminator character.*/
        msg[strlen(msg) - 1] = '\0';

        close(fd[P_RD]);

        int len = strlen(msg) + 1;
        /* Just like with the array, we have to send the amount of characters in the string.*/
        if (write(fd[P_WR], &len, sizeof(int)) == -1) { return 3; }


        /* Here we say strlen(msg) + 1 because in the end we have to send the null terminator too.*/
        if (write(fd[P_WR], msg, strlen(msg) + 1) == -1) { return 4;}

        close(fd[P_WR]);

    } else {
        wait(NULL);

        int len;
        char msg[128];
        close(fd[P_WR]);
        if (read(fd[P_RD], &len, sizeof(int)      ) == -1) { return 5; }

        if (read(fd[P_RD], msg, sizeof(char) * len) == -1) { return 6; }
        close(fd[P_RD]);

        printf("Received: %s\n", msg);

    }
    return 0;
}

/**
 * Bibliography: 
 * How to send a string through a pipe: https://youtu.be/ZS3qxIjZ0z0
*/