#include "../include/fileio.h"
int w(const char *filename, const char *string)
{
    FILE *fp;
    fp = fopen(filename, "w");
    fprintf(fp, "%s", string);
    fclose(fp);
    return 0;
}
