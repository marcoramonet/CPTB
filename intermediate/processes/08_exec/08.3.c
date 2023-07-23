#include <stdlib.h>
#include <stdio.h>
#include <errno.h>

/** Includes the exec family of functions.*/
#include <unistd.h>


/**
 * There is some variation of the exec function which changes
 * the parameters of the function.
 * Try the individual differences by calling the particular function.
*/




/**
 * The execlp takes a NULL terminated list of arguments.
 * The p means that the exec function should use the path variable to the executable.
*/
int method_one() 
{
    
    return execlp("ping", "ping", "google.com", "-c", "3", NULL );
}
/**
 * The execvp takes a "vector" (really an array) of arguments terminated by a NULL pointer.
 * 
*/
int method_two() 
{
    char *args[] = {
        "ping",
        "google.com",
        "-c",
        "3",
        NULL
    };
    return execvp(args[0], args);
}

/**
 * Same as execlp but execlpe takes on an environment variables definition.
 * For more on environment look at: https://youtu.be/6W0QT9I9OLE
*/
int method_three() 
{
    char *env[] = {
        "API_KEY=test",
        NULL
    };
    return execle("ping", "ping", "google.com", "-c", "3", NULL, env );
}
/**
 * The execvpe takes a "vector" (really an array) of arguments terminated by a NULL pointer.
 * It also takes an environment.
 * 
*/
int method_four() 
{
    char *args[] = {
        "ping",
        "google.com",
        "-c",
        "3",
        NULL
    };
    char *envp[] = {
        "API_KEY=test",
        NULL
    };
    return execve(args[0], args, envp);
}
/**
 * Esentially an exec function has either v or l.
 * And p and e are optional.
*/
int main(int argc, char *argv[]) 
{
    pid_t pid = fork();

    if (pid == -1) { return 1; }
    if (pid == 0) /* Child process*/ {
        int err = method_two();
        if (err == -1) {
            printf("Error\n");
        }
    } else /* Parent process*/{

        int wstatus;

        wait(&wstatus);

        if (WIFEXITED(wstatus)) {

            int status_code = WEXITSTATUS(wstatus);
            if (status_code == 0) {
                printf("Success!\n");
            } else {
                printf("Failure. Exited with status_code: %d.\n", status_code);
            }
        }
    }
    return 0;
}

/**
 * Bibliography:
 * exec family of functions: https://www.geeksforgeeks.org/exec-family-of-functions-in-c/
 * exec: https://youtu.be/OVFEWSP7n8c
 * man (3) exec in linux terminal.
*/