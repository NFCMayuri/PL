#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void strinit(char **str1,const char *str2){
    *str1=(char *)malloc(strlen(str2+1));
    sprintf(*str1,"%s",str2);
}
struct test{
    int type[2];
    char  *name;
    struct test *next;
};
struct test* add(){
    struct test *temp=(struct test*)malloc(sizeof(struct test));
    return temp;
}
int main(){
    struct test *test1=add();
    test1->type[0]=1;
    //test1->name=(char *)malloc(12);
    //sprintf((test1->name),"hello world");
    strinit(&(test1->name),"hello world");
    printf("name:%s\nnum:%d\n",(test1->name),(test1->type[0]));
    return 0;
}
