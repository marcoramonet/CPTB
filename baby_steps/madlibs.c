#include <stdlib.h>
#include <stdio.h>
/**
 * We can have multiple variables for each of the names of the celebrity. But, what about one name or three or more names? We have to be very specific about the amount of names that we are gonna read from the user
*/
int main()
{
    char color[16];
    char plur_noun[16];
    char celeb_first_name[16];
    char celeb_last_name[16];

    printf("Input a color:\n");
    scanf("%s", color);
    printf("Input a plural noun:\n");
    scanf("%s", plur_noun);
    printf("Input a celebrity name:\n");
    scanf("%s", celeb_first_name);
    scanf("%s", celeb_last_name);
    // fgets(celeb_name, 16, stdin);
    // scanf("%[^\n]", celeb_name);

    printf("\nPoem:\n");
    printf("Roses are %s\n", color);
    printf("%s are blue\n", plur_noun);
    printf("I love %s %s\n", celeb_first_name, celeb_last_name);

    return 0;
}
