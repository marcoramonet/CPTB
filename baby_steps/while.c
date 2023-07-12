#include <stdlib.h>
#include <stdio.h>
#include <time.h>



int main(int argc, char *argv[])
{
    int idx = 0;
    while (idx < 5)
    {
        printf("idx: %d\n", idx);
        idx++;
    }


    do 
    {
        printf("idx: %d\n", idx);
        idx++;
    } while (idx < 10);

    return 0;
}