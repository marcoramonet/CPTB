/**
 * typedef is a keyword that we can use in C to give a new name to an existing type, 
 * like an alias or a synonym.
 * 
*/
#include <stdlib.h>
#include <stdio.h>


/**
 * The typedef keyword just creates an alias, meaning the signed_whole_num type
 * is still an int.
*/
typedef int signed_whole_num;
typedef u_int32_t unsigned_whole_num;

int main() 
{

    /** Because we have the typedef above, we can use the tokens signed_whole_num and int interchangeably*/
    signed_whole_num x = -5;
    printf("%d\n", x);
    unsigned_whole_num y = 255;
    printf("%d\n", y);

    return 0;
}

/**
 * typedef Basics | C Programming Tutorial: https://youtu.be/dTFpT-zuG0Q
*/