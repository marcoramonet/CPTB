#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/**
 * A union may seem similar to a struct, but in reality it serves a different purpose.
 * While a struct groups different data together, a union does not.
 * A union is a way to define different possibilities of storing information,
 * but only one of those posibilities may be stored in the union at a time. 
 * A union only has enough space to store one of the members at a time .
 * A union will have the size of its largest member because it potentially has to store it.
 * A union serves the purpose of saving space which is very used in embedded systems for instance.
*/
union Data
{
    int x;
    double y;
    char s[32];
};

/**
 * Unions may be used like in the following struct. Here the type member tells us
 * which type of data we are currently holding.
 * For instance, the value of 0 tells us that the currently active member is x.
 * The value of 1 tells us that the currently active member is y.
 * The value of 2 tells us that the currently active member is s.
 * 
*/
struct Data2 
{
    int type;
    union Data d;
};

int main(int argc, char **argv)
{

    union Data d;

    /**
     * Note that in the following printing statements the value
     * that has been previously set is the only one that holds the actual value, 
     * the rest are gibberish
    */
    d.x = 5;
    printf("d.x: %d\td.y: %f\td.s: %s\n", d.x, d.y, d.s);
    d.y = 5.5;
    printf("d.x: %d\td.y: %f\td.s: %s\n", d.x, d.y, d.s);
    strcpy(d.s, "Overwriting previous info");
    printf("d.x: %d\td.y: %f\td.s: %s\n", d.x, d.y, d.s);

    struct Data2 d2;
    d2.type = 0;
    d2.d.x = 5;
    if (d2.type == 0) {
        printf("Data2.d.x: %d\n", d2.d.x);
    }
    return 0;
}