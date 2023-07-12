#include <stdlib.h>
#include <stdio.h>


int main(int argc, char *argv[])
{
    const int SECRET_NUM = 5;
    const int GUESS_LIMIT = 3;
    int guess;
    int guess_count = 0;
    

    do 
    {
        printf("Guess my secret number in 3 tries:\n");
        scanf("%d", &guess);
        guess_count++;
    } while (guess != SECRET_NUM && guess_count < GUESS_LIMIT);


    if (guess == SECRET_NUM)
    {
        printf("You won!\n");
        return 0;
    }
    printf("You lost!\n");
    return 0;
}