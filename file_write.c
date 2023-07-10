#include <stdlib.h>
#include <stdio.h>
/**
 * NOTE: input command: <man fopen> for more information. Other file I/O functions: fclose()
 * When we open a file we have a pointer to a memory address where the file is located in memory
 * 
 * When we use the 'w' mode on fopen() whatever text we write on the file will et overwritten.
*/

int main(int argc, char *argv[])
{

    //Writing to a file
    FILE *f_write = fopen("files.txt", "w");
    int length;
    printf("What's the length of your message?\n");
    scanf("%d", &length);
    char msg[length];
    printf("What's your message?\n");
    scanf("%s", msg);
    // NOTE: We still need to find out how to read a line of text containing spaces
    // fgets(msg,length, stdin);
    fprintf(f_write, "Hello World!\n");
    fprintf(f_write, "%s\n", msg);

    fclose(f_write);
    return 0;
}