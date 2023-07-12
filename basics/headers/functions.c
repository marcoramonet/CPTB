#include "functions.h"
#include <stdlib.h>
#include <stdio.h>
int main(int argc, char *argv[])
{
    test_power();
    if (argc == 2) {
        int num = atoi(argv[1]);
        printf("%d\n", square(num));
    } else if (argc == 3) {
        int base = atoi(argv[1]);
        int exp = atoi(argv[2]);
        printf("%d\n", power(base, exp));
    }
    return 0;
}