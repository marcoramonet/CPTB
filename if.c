#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

/**
 * Some conditional operations:
 * ==
 * !=
 * <,>
 * <=, >=
 * &&, ||, !
*/
int better_max(int A, int B, int C)
{
    if (A >= B && A >= C)
    {
        return A;
    }
    else if (B >= A && B >= C)
    {
        return B;
    }
    else 
    {
        return C;
    }
}
int max(int A, int B, int C)
{
    if(A > B)
    {
        if (A > C)
        {
            return A;
        }
        else
        {
            return C;
        }
    }
    else
    {
        if (B > C)
        {
            return B;
        }
        else 
        {
            return C;
        }
    }
}

void test_better_max()
{
    assert(better_max(1,2,3) == 3);
    assert(better_max(7,6,5) == 7);
    assert(better_max(5,5,6) == 6);
    assert(better_max(5,5,4) == 5);
    assert(better_max(5,6,5) == 6);
    assert(better_max(6,5,6) == 6);
    assert(better_max(8,7,7) == 8);
    assert(better_max(9,10,10) == 10);
    assert(better_max(3,3,3) == 3);
}

void test_max()
{
    assert(max(1,2,3) == 3);
    assert(max(7,6,5) == 7);
    assert(max(5,5,6) == 6);
    assert(max(5,5,4) == 5);
    assert(max(5,6,5) == 6);
    assert(max(6,5,6) == 6);
    assert(max(8,7,7) == 8);
    assert(max(9,10,10) == 10);
    assert(max(3,3,3) == 3);
}

int main(int argc, char *argv[]) 
{
    test_better_max();
    test_max();
    int A, B, C, result;
    printf("Input number A:");
    scanf("%d", &A);
    printf("Input number B:");
    scanf("%d", &B);
    printf("Input number C:");
    scanf("%d", &C);
    printf("Result: %d\n", max(A, B, C));
    return 0;
}