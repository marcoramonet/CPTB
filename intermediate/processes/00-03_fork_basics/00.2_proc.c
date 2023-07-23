#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
  /**
   * As an exercise try to predict how many times this forks
   * and how many times the printf() statement gets executed.
  */
  fork();
  fork();
  printf("Hello\n");
  return 0;
}
/** Bibliography:
 * Unix processes in C: https://youtube.com/playlist?list=PLfqABt5AS4FkW5mOn2Tn9ZZLLDwA3kZUY
 * See in bash: man fork
*/