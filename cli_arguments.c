#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

void print_instructions()
{
    printf("Run program with only one of the following options:\n");
    printf("\t-sleep: t: to put the program to sleep\n");
    printf("\t-echo: msg: to echo msg\n");
    printf("\t-quit: to quit the program\n");
}
int check_options(int argsc, char *args[])
{
    if (argsc > 3) {
        return 1;
    }
    int idx_param = 2;
    if (strcmp(args[1], "-echo") == 0 && argsc > idx_param) {
        printf("%s\n", args[2]);
    } else if (strcmp(args[1], "-sleep") == 0 && argsc > 2) {
        int sleep_duration =  atoi(args[2]);
        printf("Going to sleep for %d seconds.\n",sleep_duration);
        sleep(sleep_duration);
    } else {
        printf("Invalid argument or parameter\n");
    }
    return 0;
}
int main(int argc, char *argv[])
{
    int state = 0;
    switch (argc)
    {
    case 0:
    case 1:
        print_instructions();
        break;
    case 2:
        if (strcmp(argv[1], "-quit") == 0){
            return 0;
        } else if (strcmp(argv[1], "-help") == 0) {
            print_instructions();    
        } else if (strcmp(argv[1], "--help") == 0) {
            print_instructions();    
        } else {
            printf("Invalid argument or parameter!\n");
            return 0;
        }
        break;
    default:
        state = check_options(argc, argv);
        break;
    }
    if (state != 0) {
        printf("Error\n");
    }
    return state;
}

/** Bibliography:
 * atoi function: https://blog.udemy.com/c-string-to-int/#:~:text=The%20atoi()%20function%20converts,type%20pointer%20to%20a%20character.
 * break in a loop: https://www.ibm.com/docs/en/debug-for-zos/14.2?topic=commands-break-command-c-c
*/