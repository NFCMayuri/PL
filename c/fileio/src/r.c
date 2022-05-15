#include "../include/fileio.h"
int r(const char *filename)
{
    FILE *fp = fopen("file.txt", "r");
    int i;
    long location = -2;
    while (ftell(fp) != -1 && ftell(fp) != location)
    {
        // location=ftell(fp);
        // printf("location:%ld       ",location);
        char a[100];
        fscanf(fp, "%s", a);
        printf("%s \n\n", a);
    }
    fclose(fp);
    return 0;
}
