#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <assert.h>

void get_pows(int size, double *nums, double base)
{
    for (int i = 0; i < size; i++)
    {
        nums[i] = pow(base, nums[i]);
    }
}
void test_get_pows()
{
    int n = 6;
    double base = 3.0;
    double nums[n];
    for (int i = 0; i < n; i++)
    {
        nums[i] = i;
    }
    get_pows(n, nums, base);
    assert(nums[0] == 1);
    assert(nums[1] == 3.0);
    assert(nums[2] == 9.0);
    assert(nums[3] == 27.0);
    assert(nums[4] == 81);
    assert(nums[5] == 243);
}
void get_double_from_int_arr(int size, int *nums, double * doub_nums)
{
    for (int i = 0; i < size; i++)
    {
        doub_nums[i] = (double) nums[i];
    }
}
void test_get_double_from_int_arr()
{
    int size = 10;
    int nums[size];
    double doub_nums[size];
    for (int i = 0; i < size; i++)
    {
        nums[i] = i;
    }
    get_double_from_int_arr(size, nums, doub_nums);

    assert(doub_nums[0] == 0.0);
    assert(doub_nums[1] == 1.0);
    assert(doub_nums[2] == 2.0);
    assert(doub_nums[3] == 3.0);
    assert(doub_nums[4] == 4.0);
    assert(doub_nums[5] == 5.0);
    assert(doub_nums[6] == 6.0);
    assert(doub_nums[7] == 7.0);
    assert(doub_nums[8] == 8.0);
    assert(doub_nums[9] == 9.0);
}
void increasing(int size, int *my_nums)
{
    for (int i = 0; i < size; i++)
    {
        my_nums[i] = i;
    }
}

void decreasing(int size, int *my_nums)
{
    for (int i = 0; i < size; i++)
    {
        my_nums[i] = size - i - 1;
    }
}
void print_ints(int size, int *nums)
{
    for (int i = 0; i < size; i++)
    {
        printf("my_nums[%d]: %d\n", i, nums[i]);
    }
}
void print_doubs(int size, double *nums)
{
    for (int i = 0; i < size; i++)
    {
        printf("my_nums[%d]: %f\n", i, nums[i]);
    }
}
int main(int argc, char *argv[])
{

    test_get_pows();
    test_get_double_from_int_arr();
    char option[16];
    int size;
    double base;

    printf("increasing or decreasing?\n");
    scanf("%s", option);
    printf("size?\n");
    scanf("%d", &size);
    printf("Base?");
    scanf("%lf", &base);

    int my_nums[size];
    double my_doub_nums[size];

    if (strcmp(option, "increasing") == 0)
    {
        increasing(size, my_nums);
    } else if (strcmp(option, "decreasing") == 0) 
    {
        decreasing(size, my_nums);
    } else 
    {
        printf("Invalid\n");
    }
    get_double_from_int_arr(size, my_nums, my_doub_nums);
    get_pows(size, my_doub_nums, base);
    print_doubs(size, my_doub_nums);
    return 0;
}