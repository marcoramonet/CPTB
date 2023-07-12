
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>

void erase_file()
{
    FILE *f = fopen("log.txt", "w");
    
    fprintf(f, "");
    
    fclose(f);
}
/**
 * Static variables are variables whose values persist across function calls.
 * In other words, if we declare a variable with the 'static' keyword, the variable 
 * will retain its value even after the function where it was declared returns.
*/
void increment_and_log(char *message)
{
    FILE *f = fopen("log.txt","a");
    static int x = 0;
    x++;
    fprintf(f, "log %d: %s\n", x, message);
    fclose(f);
}

int main(int argc, char **argv)
{
    erase_file();
    increment_and_log("This is the first message");
    increment_and_log("This is the second message");
    increment_and_log("This is the third message");
    increment_and_log("This is the fourth message");
    increment_and_log("This is the fifth message");

    return 0;
}