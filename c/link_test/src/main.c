#include "../include/head.h"
int main(){
    struct test {
        char name[20];
        int num;
        struct test *next;
    };
    struct test *test1=(struct test*)(malloc(sizeof(struct test)));
    scanf("%d",&test1->num);
    printf("%d\n",test1->num);
    return 0;
}

