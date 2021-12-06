#include "../include/head.h"
int w(){
    FILE *fp;
    fp = fopen("file.txt","w");
    fprintf(fp,"this is an %s\n","apple");
    fclose(fp);
    return 0;
}
