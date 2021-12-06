#include "../include/head.h"
int r(){
    FILE *fp = fopen("file.txt","r");
    char a[10],b[10],c[10],d[10];
    fscanf(fp,"%s %s %s %s",a,b,c,d);
    printf("%s %s %s %s\n",a,b,c,d);
    fclose(fp);
    return 0;
}
