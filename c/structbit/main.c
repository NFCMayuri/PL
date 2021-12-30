#include <stdio.h>
int main(){
    struct test {
        unsigned int a:1;
        unsigned int b:2;
        unsigned int c:1;
    };
    struct test test2;
    test2.a=3;
    test2.b=1;
    test2.c=-1;
    printf("%d\n%d\n%d\n",test2.a,test2.b,test2.c);
}
