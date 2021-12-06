#include "../include/head.h"
int r(const char* filename){
    FILE *fp = fopen("file.txt","r");
    char a[100];
    fscanf(fp,"%s",a);
    printf("%s",a);
    fclose(fp);
    return 0;
}
