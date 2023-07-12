#include <stdlib.h>
#include <stdio.h>
/**
 * A pointer is a memory address.
 * NOTE: We use the type of the variable to declare the type of the pointer holding the address of that variable.
    * For instance, for the address of an int we use int*, for the address of a char we use char*. 
    * In other words the type of the pointer must be compatible with the type of the variable.
 * 
 * */
int main(int argc, char *argv[])
{
    // In an int variable we store the value of an integer
    int num = 57;
    // In the int pointer variable we store the address of an int variable
    int *num_ptr = &num;
    // We can dereference the pointer variable to access the value held at the address stored in the pointer variable.
    int deref_num = *num_ptr;

    printf("num's memory address:%p\tnum_ptr: %p\tnum: %d\t*num_ptr: %d\n", &num, num_ptr, num, *num_ptr);


    return 0;
}