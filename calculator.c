#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
/**
 * In a switch statement each of the cases are constant values
*/
double calculate_case(double A, double B, char op) 
{
    double result;

    switch (op)
    {
    case '+':
        result =  A + B;
        break;
    case '-':
        result =  A - B;
        break;    
    case '*':
        result =  A * B;
        break;
    case '/':
        result =  A / B;
        break;
    default:
        // printf("Invalid operator\n");
        result = -1;
        break;
    }
    return result;
}


double calculate(double A, double B, char op)
{
    if (op == '+')
    {
        return A + B;
    } else if (op == '-')
    {
        return A - B;
    } else if (op == '*')
    {
        return A * B;
    } else if (op == '/') 
    {
        return A / B;
    } else
    {
        // printf("Invalid operator\n");
        return -1;
    }
}

void test_calculate()
{
    assert(calculate(9, 1,'+') == 10);
    assert(calculate(7, 3,'+') == 10);
    assert(calculate(7, 5,'-') == 2);
    assert(calculate(8, 5,'-') == 3);
    assert(calculate(5, 5,'*') == 25);
    assert(calculate(5, 3,'*') == 15);
    assert(calculate(20, 4, '/') == 5);
    assert(calculate(65, 5, '/') == 13);
    assert(calculate(1376, 192, 'x') == -1);
}
void test_calculate_case()
{
    assert(calculate_case(9, 1,'+') == 10);
    assert(calculate_case(7, 3,'+') == 10);
    assert(calculate_case(7, 5,'-') == 2);
    assert(calculate_case(8, 5,'-') == 3);
    assert(calculate_case(5, 5,'*') == 25);
    assert(calculate_case(5, 3,'*') == 15);
    assert(calculate_case(20, 4, '/') == 5);
    assert(calculate_case(65, 5, '/') == 13);
    assert(calculate_case(1376, 192, 'x') == -1);
}
int main(int argc, char *argv[])
{
    test_calculate();
    test_calculate_case();
    double A, B;
    char op;

    printf("Input A:\n");
    scanf("%lf", &A);
    printf("Input B:\n");
    scanf("%lf", &B);
    printf("Input operation in a single character (+,-,*,/):\n");
    scanf(" %c", &op);
    printf("Result: %f\n", calculate(A, B, op));

    return 0;
}