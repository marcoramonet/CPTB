#include <stdlib.h>
#include <stdio.h>
#include <string.h>

double cube(double x) 
{
    return x * x * x;
}
int sum(int a, int b)
{
    return a + b;
}
int one() 
{
    return 1;
}
void print_msg(char name[], int curr_age)
{
    printf("%s will be %d years old one year from now\n", name, sum(one(), curr_age));
}
int main(int argc, char  *argv[]) 
{
    char name[16];
    int age;
    printf("Input name:\n");
    scanf("%s", name);

    printf("Input current age:\n");
    scanf("%d", &age);

    print_msg(name, age);

    printf("%f\n", cube(4.9));

    return 0;
}