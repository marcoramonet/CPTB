#include <stdlib.h>
#include <stdio.h>
/**
 * When we do an operation with an integer and a floating point number the type gets casted to floating point.\
 * c math functions: ceil(), pow(), floor()
*/



int main()
{
    int amount;
    printf("How many numbers do you want to average?\n");
    scanf("%d", &amount);

    double nums[amount];
    double added = 0;

    for (int i = 0; i < amount; i++)
    {
        printf("Input the %dth number:\n", i);
        scanf("%lf", &nums[i]);
        added += nums[i];
    }
    double average = added / amount;
    printf("Result: %f", average);

    return 0;
}