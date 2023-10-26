#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

void *hello()
{
    printf("Hello!\n");
    sleep(1);
    return NULL;
}

void *num(void *n)
{
    // We cast the void pointer to an int pointer
    int *num = (int *) n;
    // We use the dereference operator
    printf("Num is: %d\n", *num);
    sleep(1);
    return NULL;
}


int main(int argc, char *argv[]) 
{
    pthread_t t1;
    pthread_create(&t1, NULL, hello, NULL);
    printf("Waiting for hello\n");
    pthread_join(t1, NULL);

    /**
     * Passing an argument to a thread:
    */
    pthread_t t2;
    int x = 1;
    // The args parameter of phtread_create only accepts a void pointer.
    pthread_create(&t2, NULL, num, (void*) &x);
    printf("Waiting for num\n");
    pthread_join(t2, NULL);
    return 0;
}




/**
 * References:
 * Tutorialspoint threads: https://www.tutorialspoint.com/multithreading-in-c
 * manual: https://man7.org/linux/man-pages/man7/pthreads.7.html
 * Introduction To Threads (pthreads) | C Programming Tutorial: https://www.youtube.com/watch?v=ldJ8WGZVXZk
*/