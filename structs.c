#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/**
 * We cannot asign a string value to an array of characters, we have to use the strcpy() function.
*/
struct Student_t
{

    char name[16];
    int age;
    double gpa;
};


int main(int argc, char *argv[])
{
    struct Student_t S1;
    strcpy(S1.name, "Joseph");
    S1.age = 21;
    S1.gpa = 3.5;

    printf("S1's name: %s", S1.name);
    printf("S1's age: %d", S1.age);
    printf("S1's gpa: %f", S1.gpa);
    return 0;
}