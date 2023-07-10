#include <stdlib.h>
#include <stdio.h>


/**
 * We cannot initialize an array with the size specified by a variable (variable length array). 
 * We can only initialize an array when the size is specified by an integer literal.
 * For instance, the following compiles fine:
    * int nums[2][2] = {
    *                  {0, 1},
    *                  {2, 3}
    *                  };
 * But, the following gives an error:
    * int nums[y_size][x_size] = {
    *                  {0, 1},
    *                  {2, 3}
    *                };
*/

int main(int argc, char *argv[])
{
    int amount_y_axis = 3;
    int amount_x_axis = 2;
    int nums[amount_y_axis][amount_x_axis];

    nums[0][0] = 1;
    nums[0][1] = 7;
    nums[1][0] = 49;
    printf("nums[1][0] + nums[0][0] = %d\n", nums[1][0] + nums[0][0]);

    int count = 0;
    for (int i = 0; i < amount_y_axis; i++)
    {
        for (int j = 0; j < amount_x_axis; j++)
        {
            nums[i][j] = count;
            printf("%d,\t", nums[i][j]);
            count++;
        }
        printf("\n");
    }


    return 0;
}