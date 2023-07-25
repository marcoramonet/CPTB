
/**
 * A FIFO is a named pipe. It is a file with the behavior of a pipe.
 * With FIFOs both ends (read an write ) must be opened.
 * From the linux manual: 
    *  "Opening a read or write end of a FIFO blocks until the other end is also opened". 
 * 
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

/** Includes the definition of mkfifo()*/
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/errno.h>
/** Includes the open() function*/
#include <sys/fcntl.h>

int main(int argc, char *argv[]) {
    /** 
     * mkfifo takes the path of the fifo to create. 
     * If the fifo already exists the status variable is set to -1.
     * The parameter mode_t specifies the file's permissions. 
     * mkfifo returns 0 if everything went fine. 
     * And, it returns -1 if there was an error creating the fifo.
     * 
    */
    if (mkfifo("fifo", 0777) == -1) {
        if (errno == EEXIST) /* The file already exists*/ {
            printf("fifo already exists\n");
        } else {
            printf("Error creating fifo. errno: %d", errno);
            return 1;
        }
    }

    /** Besides creating the fifo, we have to open the fifo file to be able to access it.
     * open() takes the path to the file and the open flag, 
     * which describes what's the purpose of opening the file:
        * O_WRONLY: write only.
        * O_RONLY: read only.
        * O_RDWR: read and write.
     * open() returns the file descriptor to the file. 
     * Note that we only get one file desriptor because we open it only to write in it.
     * NOTE: As opposed to the pipe() function, with open() 
     * we only get the file descriptor when we open the fifo, not when we create it.
     * 
     * If we run this program the execution will block on open() 
     * because the fifo needs to be opened on both ends in order to work properly.
     * If we were to open the fifo with the O_RDONLY flag it would also hang.
     * But, if we open the fifo with the O_RDWR flag, 
     * then it won't hang because both ends of the fifo are open.
    */
    printf("Opening...\n");
    int fd = open("fifo", O_WRONLY);
    if (fd == -1) {
        return 2;
    }
    printf("Opened...\n");
    int x = 'H';
    if (write(fd, &x, sizeof(x)) == -1) {
        printf("Error writing to the pipe. errno: %d\n", errno);
        return 3;
    }
    printf("Written...\n");
    close(fd);
    printf("Closed...\n");
    return 0;

}
/**
 * BIBLIOGRAPHY:
 * FIFOs (named pipe): https://youtu.be/2hba3etpoJg
*/