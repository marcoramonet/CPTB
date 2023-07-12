#include <stdlib.h>
#include <stdio.h>

int main()
{
    /**
     * NOTE: scanf stops reading characters when it reaches a space character. 
     * For example if we input "John Smith" for a name in our program, scanf is only gonna read "John", not "Smith"
     * So, instead of scanf we can use fgets: fgets reads a full line of text
    */

    char full_name[32];
    printf("Enter your full name:\n");
    fgets(full_name, 32, stdin);
    printf("Your full name is: %s\n", full_name);
    /**
     * One downside of fgets is that the newline character that the user inputs when they input their name gets stored in the variable, 
     * so when we print the variable, the newline character is printed alongside the string.
    */
    return 0;
}