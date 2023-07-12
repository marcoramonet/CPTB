#include <stdlib.h>
#include <stdio.h>

int main()
{
    double numA, numB;
    printf("Input first number:\n");
    scanf("%lf", &numA);
    printf("Input second number:\n");
    scanf("%lf", &numB);
    printf("The sum of your two numbers is: %f\n", numA + numB);

    return 0;
}