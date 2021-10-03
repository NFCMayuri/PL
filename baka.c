#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int baka();
int main(){
    //char str1[20]="114514";
    //char *str2 ="1919810";
    //char str3[]= *str2;
    //printf("%s\n%s\n",&str1,str2);
    //strcpy(str1,str3);
    //printf("strcpy(str1,str3):%s\n",str3)
    baka();
}

int baka(){
    char saying1[99]="Baka,my Baka,I do love u so much. ";
    char saying2[]="Pls take me away";
    strcat(saying1,saying2);
    printf("%s!\n",&saying1);
    return 0;
}
