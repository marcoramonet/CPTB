#include <stdlib.h>
#include <stdio.h>

int main(int argc, char **argv)
{
    int a, b;
    double c;
    a = 5;
    b = 2;
    /**
     * We type cast the number 5 to double. Then a division of double by an int
     * results in a double. We can say that the int gets 'promoted' to a double.
     * Type conversion has higher presedence than division. 
    */
    c = (double) 5 / 2;
    printf("c: %f\n", c);


    int x = 2;
    int z;
    double y = 5;
    /** Here the result from the division is 'demoted' to an int.*/
    z = y / x;
    printf("z: %d\n", z);

    printf("");

    return 0;
}

/**
 * Bibliography:
    * Type Casting | C Programming Tutorial: https://youtu.be/xKOPZ4mEH3I
*/