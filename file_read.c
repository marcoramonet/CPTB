#include <stdlib.h>
#include <stdio.h>

int main(int argc, char* argv[])
{
    int LENGTH = 256;
    FILE *fread = fopen("files.txt", "r");
    char line[LENGTH];

    // We read the first line from the file "files.txt"
    fgets(line, LENGTH, fread);
    printf("%s", line);
    // The file pointer is on the second line because we've read the first line.
    // Whenever fgets is called the file pointer gets incremented
    // Therefore if we read again, the file reads the second line.
    fgets(line, LENGTH, fread);
    printf("%s", line);


    fclose(fread);
    return 0;
}