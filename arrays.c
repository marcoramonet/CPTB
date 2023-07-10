#include <stdlib.h>
#include <stdio.h>
#include <math.h>
/**
 * A variable is a container that is used to store a single value, while an array is a container that is used to store any number of values.
*/

int main()
{
    // We create an array and we initialize it
    int my_init_arr[] = {0,1,2,3,4,5,6,7};

    // This prints a pointer to the array. Note that the format specifier is a 'p' not a 'd'
    printf("%p\n", my_init_arr);


    // This prints the actual value stored in the array at the indexed position
    printf("%d\n", my_init_arr[0]);
    printf("%d\n", my_init_arr[1] + my_init_arr[2]);


    // We describe the size of our array
    const unsigned int SIZE = 8;
    
    // We create an array without initializing it
    int sqr[SIZE];

    // We manipulate the values in the array
    sqr[6] = 36;
    printf("sqr[6]: %d\n", sqr[6]);


    for (unsigned int i = 0; i < SIZE; i++) 
    {
        sqr[i] = pow(my_init_arr[i], 2);
        printf("sqr[%d]: %d\n", i, sqr[i]);
    }

    return 0;
}