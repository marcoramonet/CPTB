#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <fcntl.h>

/** Includes the exec family of functions.*/
#include <unistd.h>


/**
 * What if I don't want the output of the ping program that I'm calling through the exec function?
 * We can redirect the standard output through the dup function.
 * A file descriptor represents a key to an input or output resource, it could be 
 * a pipe, stdout or stdin, a file, a fifo, etc. 
 * Whenever a process is created certain file descriptors are created by default by the OS:
    *  0: STDIN
    *  1: STDOUT
    *  2: STDERR
*/
int main(int argc, char *argv[]) 
{
    pid_t pid = fork();

    if (pid == -1) { return 1; }
    if (pid == 0) /* Child process*/ {

        /**
         * Here we create a file, or open it if it already exists.
            * "pingout.txt" : The path to the file we want to access.
            * O_WRONLY | O_CREAT : The flags we pass to open. In this case we are 
                * writing to the file (O_WRONLY : 0001), and we create the file in case it doesn't exist (O_CREAT : 00000200).
                * We bitwise OR them so the resulting flag is: 00000201.
            * 0777 : We pass the specified permissions in octal. In this case 0777 means that anyone can access the file.
        *   
        * When we call open, a new file descriptor is added to the process table, 
        * and the table results in:
            *  0 : STDIN
            *  1 : STDOUT
            *  2 : STDERR
            *  3 : pingout.txt
        */
        int file = open("pingout.txt", O_WRONLY | O_CREAT, 0777);

        /**
         * The dup() function duplicates the file descriptor passed as a parameter and 
         * sets it in the lowest available file descriptor. 
         * That is, it adds another file descriptor that gives access to the same 
         * file described by the file descriptor given as a parameter. After calling dup,
         * the file descriptor table would look something like:
            *  0 : STDIN
            *  1 : STDOUT
            *  2 : STDERR
            *  3 : pingout.txt
            *  4 : pingout.txt
         * 
        */
        int file2 = dup(file);


        /**
         * dup2(A, B) takes two parameters: 
            *  A: This is the file descriptor that we want to duplicate. 
            *  B: The value that we want the new file descriptor to actually have.
        * When dup2 is called, it closes the B file descriptor and copies the A
        * descriptor to the position where B was.
        * So, by running dup2(file, STDOUT_FILENO) we're replacing the descriptor of STDOUT
        * with the 'file' file descriptor, leaving us with the following file descriptor table:
            *  0 : STDIN
            *  1 : pingout.txt
            *  2 : STDERR
            *  3 : pingout.txt
            *  4 : pingout.txt
        * Now whenever a printf() is called, instead of writing to the STDOUT, it will
        * write to pingout.txt
        */
       int file3 = dup2(file, STDOUT_FILENO);

       /**
        * NOTE: When we call exec, it doesn't replace the file descriptor table,
        * so it will still write to pingout.txt.
       */
        if (execlp("ping", "ping", "google.com", "-c", "3", NULL) == -1) {
            printf("Error\n");
        }
    } else /* Parent process*/{

    }
    return 0;
}

/**
 * Bibliography:
 * Redirecting standard output in C: https://youtu.be/5fnVr-zH-SE
*/