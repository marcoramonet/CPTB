#include <stdlib.h>
#include <stdio.h>


int main() 
{
    // Create variables where we're gonna store the values that the user inputs:
    char name[16];
    int age;

    // Prompt the user:
    printf("Input your name:\n");
    // read value into the corresponding variable: 
    // NOTE: name does not have a '&' because name is a pointer (character array decays to pointer)

    //NOTE: Notice that if we input multiple names into our program, scanf only reads the first name into te variable name, and the program breaks. For a solution see io_1.c
    //scanf("%s", name);
    // Another possible solution is to modify the scanf format string like the following:
    scanf("%s", name);
    printf("Input your age:\n");
    // NOTE: here age has a '&' before it because age is a variable, not a pointer, and the function scanf takes the address of the variable where we want to store the value read
    scanf("%d", &age);
    printf("Your name is %s and your age is %d\n", name, age);

    
}