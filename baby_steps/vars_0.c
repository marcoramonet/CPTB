#include <stdlib.h>
#include <stdio.h>
#include <string.h>
/**
 * A string literal is different than a char array.
*/
int main()
{
    // variables
    int age = 10;
    double pi = 3.1415;
    char grade = 'C';
    char phrase[] = "Hey, this is the C programming language!";
    char first_name[] = "George";
    char last_name[] = "Smith";
    char full_name[32] = "George Smith";

    printf("There once was a boy named %s\n", full_name);
    printf("He was %d years old\n", age);
    printf("He liked the name %s\n", first_name);
    printf("But he did not like being %d.\n", age);
    printf("%s's grade in Mathematics was a %c\n", first_name, grade);
    printf("%s knew the number %lf (pi) by heart\n", first_name, pi);

    // variables can be modified
    age = age + 1;
    printf("After a year %s is %d years old\n", first_name, age);
    
    
    printf("----------------------------------------------------\n");
    /**
     * String literals and numbers are considered constants
    */
    const int MY_NUM = 5;

    //This throws an error:
    // MY_NUM = MY_NUM + 1;

}