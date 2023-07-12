#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include <assert.h>

int square(int x) 
{
    return x * x;
}
int power(int base, int exp)
{
    if (base == 0) {
        return 0;
    } else if (exp == 0) {
        return 1;
    } else {
        int result = base;
        for (int i = 1; i < exp; i++)
        {
            result = result * base;
        }
        return result;
    }
}
void test_power()
{
    assert(power(0, 0) == 0);
    assert(power(0, 1) == 0);
    assert(power(0, 2) == 0);

    assert(power(1, 0) == 1);
    assert(power(1, 1) == 1);
    assert(power(1, 2) == 1);

    assert(power(2, 0) == 1);
    assert(power(2, 1) == 2);
    assert(power(2, 2) == 4);
    assert(power(2, 3) == 8);
    assert(power(2, 4) == 16);
    assert(power(2, 5) == 32);

    assert(power(3, 0) == 1);
    assert(power(3, 1) == 3);
    assert(power(3, 2) == 9);
    assert(power(3, 3) == 27);
    assert(power(3, 4) == 81);
    assert(power(3, 5) == 243);

    assert(power(4, 0) == 1);
    assert(power(4, 1) == 4);
    assert(power(4, 2) == 16);
    assert(power(4, 3) == 64);
    assert(power(4, 4) == 256);
    assert(power(4, 5) == 1024);
    
}
#endif



/** Bibliography
 * header files: https://www.tutorialspoint.com/cprogramming/c_header_files.htm
*/